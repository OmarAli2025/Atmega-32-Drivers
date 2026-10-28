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

uint8t ADC_getChannelReading(ADC_Channels_t copy_ADCchanel,uint16t * copy_pu16ADC_data)
{
	uint8t local_u8ErrorState=OK;

	if(copy_pu16ADC_data==NULL)
	{
		local_u8ErrorState=NULLPTR;
	}
	else if(copy_ADCchanel>ADC_GND)
	{
		local_u8ErrorState=NOK;

	}
	else
	{
		/*Set ADC Channel*/
		ADMUX &=~(u8ADCCHANNELMUSK<<ADMUX_MUX0);
		ADMUX |=(copy_ADCchanel<<ADMUX_MUX0);

		/*Start Conversion*/
		ADCSRA|=(1<<ADCSRA_ADSC);

		/*Polling On Flag Till Conversion FInish*/
		while(((ADCSRA >>ADCSRA_ADIF)&1)==0);

		/*Clear Flag by Writing logical One*/
		ADCSRA|=(1<<ADCSRA_ADIF) ;

#if ADLAR_MODE==u8LEFTADJUST
		*copy_pu16ADC_data = ADCLH >> 6;
#elif ADLAR_MODE==u8RIGHTADJUST
		*copy_pu16ADC_data = ADCLH;
#endif
	}


	return local_u8ErrorState;
}

uint8t ADC_getChannel8bitReading(ADC_Channels_t copy_ADCchanel,uint8t * copy_pu8ADC_data)
{
	uint8t local_u8ErrorState=OK;

	if(copy_pu8ADC_data==NULL)
	{
		local_u8ErrorState=NULLPTR;
	}
	else if(copy_ADCchanel>ADC_GND)
	{
		local_u8ErrorState=NOK;

	}
	else
	{
		/*Set ADC Channel*/
		ADMUX &=~(u8ADCCHANNELMUSK<<ADMUX_MUX0);
		ADMUX |=(copy_ADCchanel<<ADMUX_MUX0);

		/*Start Conversion*/
		ADCSRA|=(1<<ADCSRA_ADSC);

		/*Polling On Flag Till Conversion FInish*/
		while(((ADCSRA >>ADCSRA_ADIF)&1)==0);

		/*Clear Flag by Writing logical One*/
		ADCSRA|=(1<<ADCSRA_ADIF) ;

		*copy_pu8ADC_data = ADCH;
	}


	return local_u8ErrorState;
}

