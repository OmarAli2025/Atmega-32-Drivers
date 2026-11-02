/*
 * ADC_prog.c
 *
 *  Created on: Oct 26, 2026
 *      Author: hp
 */

#include "StdLib.h"
#include "ErrorStates.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_reg.h"
#include "ADC_cfg.h"
#include "ADC_pvt.h"

static void (*ADC_globalPtrFunc)(void)=NULL;
static volatile uint8t global_u8CurrentChanel=0;

static volatile uint16t* global_u16ADCAsyncRead=NULL;
static volatile  uint8t global_u8ADCIdleFlag=IDLE;

static volatile  ADC_AsyncChainConfig *ADC_globalChainConfig=NULL;

static volatile uint8t global_ISRMODE=SINGLECONVERSIONMODE;

void ADC_voidInit(void)
{
	/*Set ADC Refrence Volt*/
	ADMUX&=~(0b11<<ADMUX_REFS0);
	ADMUX|=(ADC_REFMODE<<ADMUX_REFS0);

	/*Adjust  ADC Data Alligment*/
#if ADLAR_MODE==u8RIGHTADJUST

	ADMUX&=~(1<<ADMUX_ADLAR);

#elif ADLAR_MODE==u8LEFTADJUST

	ADMUX|=(1<<ADMUX_ADLAR);

#else
#error Wrong Config

#endif

	/*Disable Interrupt*/

	ADCSRA&=~(1<<ADCSRA_ADIE);

	/*Disable Auto trigger*/
	ADCSRA&=~(1<<ADCSRA_ADATE);
	/*Adjust ADC Prescaler*/

	ADCSRA &=~(ADCPRESCALAR_MUSK<<ADCSRA_ADPS0);
	ADCSRA|=(ADC_PRESCALARDIV<<ADCSRA_ADPS0);

	/*Enable ADC peripheral*/
	ADCSRA|=(1<<ADCSRA_ADEN);

}

uint8t ADC_StartConversionSync(ADC_Channels_t copy_ADCchanel,uint16t * copy_pu16ADC_data)
{

	uint32t local_u32Counter=0;
	uint8t local_u8ErrorState=OK;


	if(copy_pu16ADC_data==NULL)
	{
		local_u8ErrorState=NULLPTR;
	}
	else if(copy_ADCchanel>ADC_GND)
	{
		local_u8ErrorState=NOK;

	}
	else if(global_u8ADCIdleFlag==BUSY)
	{
		local_u8ErrorState=BUSYFUNC_ERR;
	}
	else
	{
		global_u8ADCIdleFlag=BUSY;
		/*Set ADC Channel*/
		ADMUX &=~(u8ADCCHANNELMUSK<<ADMUX_MUX0);
		ADMUX |=(copy_ADCchanel<<ADMUX_MUX0);

		/*Start Conversion*/
		ADCSRA|=(1<<ADCSRA_ADSC);

		/*Wait with  blocking*/
		while(((ADCSRA >>ADCSRA_ADIF)&1)==0 &&local_u32Counter<ADC_u32TIMEOUT)
		{
			local_u32Counter++;

		}
		if(local_u32Counter==ADC_u32TIMEOUT)
		{
			local_u8ErrorState=TIMEOUT_ERR;
		}
		else
		{
			/*Clear Flag by Writing logical One*/
			ADCSRA|=(1<<ADCSRA_ADIF) ;

#if ADLAR_MODE==u8LEFTADJUST
			*copy_pu16ADC_data = ADCLH >> 6;
#elif ADLAR_MODE==u8RIGHTADJUST
			*copy_pu16ADC_data = ADCLH;
#endif
		}

		global_u8ADCIdleFlag=IDLE;
	}

	return local_u8ErrorState;
}

# if ADLAR_MODE==u8LEFTADJUST
uint8t ADC_StartConversion8bitSync(ADC_Channels_t copy_ADCchanel,uint8t * copy_pu8ADC_data)
{
	uint32t local_u32Counter=0;

	uint8t local_u8ErrorState=OK;

	if(copy_pu8ADC_data==NULL)
	{
		local_u8ErrorState=NULLPTR;
	}
	else if(copy_ADCchanel>ADC_GND)
	{
		local_u8ErrorState=NOK;

	}
	else if(global_u8ADCIdleFlag==BUSY)
	{
		local_u8ErrorState=BUSYFUNC_ERR;
	}
	else
	{
		global_u8ADCIdleFlag=BUSY;

		/*Set ADC Channel*/
		ADMUX &=~(u8ADCCHANNELMUSK<<ADMUX_MUX0);
		ADMUX |=(copy_ADCchanel<<ADMUX_MUX0);

		/*Start Conversion*/
		ADCSRA|=(1<<ADCSRA_ADSC);

		/*Polling On Flag Till Conversion FInish*/
		while(((ADCSRA >>ADCSRA_ADIF)&1)==0 &&local_u32Counter<ADC_u32TIMEOUT)
		{
			local_u32Counter++;

		}

		if(local_u32Counter==ADC_u32TIMEOUT)
		{
			local_u8ErrorState=TIMEOUT_ERR;
		}
		else
		{
			/*Clear Flag by Writing logical One*/
			ADCSRA|=(1<<ADCSRA_ADIF) ;

			*copy_pu8ADC_data = ADCH;
		}
		global_u8ADCIdleFlag=IDLE;

	}
	return local_u8ErrorState;
}

#endif

uint8t ADC_StartChainConversionSync(ADC_Channels_t const* copy_aADCchannels,uint8t copy_u8NumberChannels,uint16t copy_au16Results[])
{

	uint8t Local_u8ErrorState=OK;
	uint8t local_u8Counter=0;
	uint32t local_u32Counter=0;

	if((copy_aADCchannels==NULL )|| (copy_au16Results==NULL) )
	{
		Local_u8ErrorState=NULLPTR;
	}

	else if(global_u8ADCIdleFlag==BUSY)
	{
		Local_u8ErrorState=BUSYFUNC_ERR;
	}

	else if(copy_u8NumberChannels==0 ||copy_u8NumberChannels>31)
	{
		Local_u8ErrorState=NOK;
	}

	else
	{
		for(local_u8Counter=0;local_u8Counter<copy_u8NumberChannels;local_u8Counter++)
		{
			if(copy_aADCchannels[local_u8Counter]>ADC_GND)
			{
				Local_u8ErrorState=NOK;
				break;
			}
		}
		if(Local_u8ErrorState==OK)
		{
			global_u8ADCIdleFlag=BUSY;

			for(local_u8Counter=0;local_u8Counter<copy_u8NumberChannels;local_u8Counter++)
			{
				ADMUX &=~(u8ADCCHANNELMUSK<<ADMUX_MUX0);
				ADMUX |=(copy_aADCchannels[local_u8Counter]<<ADMUX_MUX0);
				/*Start Conversion*/
				ADCSRA|=(1<<ADCSRA_ADSC);

				/*Polling On Flag Till Conversion FInish*/
				while(((ADCSRA >>ADCSRA_ADIF)&1)==0 &&local_u32Counter<ADC_u32TIMEOUT)
				{
					local_u32Counter++;

				}

				if(local_u32Counter==ADC_u32TIMEOUT)
				{
					Local_u8ErrorState=TIMEOUT_ERR;
					break;
				}
				else
				{
					ADCSRA|=(1<<ADCSRA_ADIF) ;

#if ADLAR_MODE==u8LEFTADJUST
					copy_au16Results[local_u8Counter] = ADCLH >> 6;
#elif ADLAR_MODE==u8RIGHTADJUST
					copy_au16Results[local_u8Counter] = ADCLH;
#endif
				}

				local_u32Counter=0;

			}
			global_u8ADCIdleFlag=IDLE;

		}
	}
	return Local_u8ErrorState;

}



uint8t ADC_StartConversionAsync(ADC_Channels_t copy_ADCchanel,volatile uint16t * copy_pu16ADC_data,void(*copy_pvNotificationFunc)(void))
{

	uint8t local_u8ErrorState=OK;

	if((copy_pu16ADC_data==NULL)||(copy_pvNotificationFunc==NULL))
	{
		local_u8ErrorState=NULLPTR;
	}

	else if(copy_ADCchanel>ADC_GND)
	{
		local_u8ErrorState=NOK;

	}
	else if(global_u8ADCIdleFlag==BUSY)
	{
		local_u8ErrorState=BUSYFUNC_ERR;
	}
	else
	{
		global_u8ADCIdleFlag=BUSY;
		global_u16ADCAsyncRead=copy_pu16ADC_data;
		ADC_globalPtrFunc=copy_pvNotificationFunc;
		/*Set ADC Channel*/
		ADMUX &=~(u8ADCCHANNELMUSK<<ADMUX_MUX0);
		ADMUX |=(copy_ADCchanel<<ADMUX_MUX0);
		/*Enable Interrupt*/
		ADCSRA|=(1<<ADCSRA_ADIE);
		/*Start Conversion*/
		ADCSRA|=(1<<ADCSRA_ADSC);

	}

	return local_u8ErrorState;
}



uint8t ADC_StartChainConversionASync(volatile ADC_AsyncChainConfig  * copy_ChainConfig)
{
	uint8t local_u8ErrorState=OK;

	if(copy_ChainConfig==NULL || copy_ChainConfig->ADC_channel==NULL || copy_ChainConfig->local_au16Results==NULL || copy_ChainConfig->pfNotification==NULL)
	{
		local_u8ErrorState=NULLPTR;

	}
	else if(copy_ChainConfig->local_u8NumChannel ==0 || copy_ChainConfig->local_u8NumChannel>31)
	{
		local_u8ErrorState=NOK;

	}
	else if(global_u8ADCIdleFlag==BUSY)
	{
		local_u8ErrorState=BUSYFUNC_ERR;

	}

	else
	{
		uint8t local_u8Counter=0;
		for(local_u8Counter=0;local_u8Counter<copy_ChainConfig->local_u8NumChannel;local_u8Counter++)
		{
			if(copy_ChainConfig->ADC_channel[local_u8Counter]>ADC_GND)
			{
				local_u8ErrorState=NOK;
				break;
			}
		}

		if(local_u8ErrorState==OK)
		{
			global_u8ADCIdleFlag=BUSY;
			ADC_globalChainConfig=copy_ChainConfig;
			global_u8CurrentChanel=0;
			global_ISRMODE=CHAINCONVERSIONMODE;
			/*Set ADC Channel*/
			ADMUX &=~(u8ADCCHANNELMUSK<<ADMUX_MUX0);
			ADMUX |=((copy_ChainConfig->ADC_channel[global_u8CurrentChanel])<<ADMUX_MUX0);
			/*Enable Interrupt*/
			ADCSRA|=(1<<ADCSRA_ADIE);
			/*Start Conversion*/
			ADCSRA|=(1<<ADCSRA_ADSC);

		}
	}


	return local_u8ErrorState;

}


void __vector_16(void)__attribute__((signal));
void __vector_16(void)
{
	if(global_ISRMODE==SINGLECONVERSIONMODE)
	{
		/*Disable Interrupt*/
		ADCSRA&=~(1<<ADCSRA_ADIE);
		global_u8ADCIdleFlag=IDLE;

		if(global_u16ADCAsyncRead!=NULL)
		{
#if ADLAR_MODE==u8LEFTADJUST
			*global_u16ADCAsyncRead=ADCH;
#elif ADLAR_MODE==u8RIGHTADJUST
			*global_u16ADCAsyncRead=ADCLH;
#endif


			if(ADC_globalPtrFunc!=NULL)
			{
				ADC_globalPtrFunc();

			}

		}

	}

	else
	{
#if ADLAR_MODE==u8LEFTADJUST
		ADC_globalChainConfig->local_au16Results[global_u8CurrentChanel]=ADCH;
#elif ADLAR_MODE==u8RIGHTADJUST
		ADC_globalChainConfig->local_au16Results[global_u8CurrentChanel]=ADCLH;
#endif

		global_u8CurrentChanel++;
		if(global_u8CurrentChanel<ADC_globalChainConfig->local_u8NumChannel)
		{
			ADMUX &=~(u8ADCCHANNELMUSK<<ADMUX_MUX0);
			ADMUX |=((ADC_globalChainConfig->ADC_channel[global_u8CurrentChanel])<<ADMUX_MUX0);
			/*Enable Interrupt*/
			ADCSRA|=(1<<ADCSRA_ADIE);
			/*Start Conversion*/
			ADCSRA|=(1<<ADCSRA_ADSC);
		}

		else
		{
			/*Disbale Interrupt*/
			ADCSRA&=~(1<<ADCSRA_ADIE);

			global_ISRMODE=SINGLECONVERSIONMODE;
			global_u8ADCIdleFlag=IDLE;

			if(ADC_globalChainConfig->pfNotification!=NULL)
			{
				ADC_globalChainConfig->pfNotification();
			}

		}


	}
}


