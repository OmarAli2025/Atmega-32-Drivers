/*
 * EXTI_prog.c
 *
 *  Created on: Oct 23, 2026
 *      Author: hp
 */

#include "StdLib.h"
#include "ErrorStates.h"
#include "BIT_MATH.h"

#include "GIE_interface.h"

#include "EXTI_interface.h"
#include "EXTI_reg.h"
#include "EXTI_pvt.h"
#include "EXTI_cfg.h"

static void (*ptrfunc[3])(void)={NULL,NULL,NULL};

void EXTI_voidInit(void)
{


#if(INT0_SENSECTRL==u8_FALLING_EDGE)

	MCUCR&=~(0b11<<MCUCR_ISC00);
	MCUCR|=0b10<<MCUCR_ISC00;

#elif(INT0_SENSECTRL==u8_LOW_LEVEL)

	MCUCR&=~(0b11<<MCUCR_ISC00);

#elif(INT0_SENSECTRL==u8_ON_CHANGE)

	MCUCR&=~(0b11<<MCUCR_ISC00);
	MCUCR|=0b1<<MCUCR_ISC00;


#elif(INT0_SENSECTRL==u8_RISING_EDGE)

	MCUCR&=~(0b11<<MCUCR_ISC00);
	MCUCR|=0b11<<MCUCR_ISC00;

#else
#error Wrong Sense Control  Conifig INT0 options

#endif




#if(INT1_SENSECTRL==u8_FALLING_EDGE)

	MCUCR&=~(0b11<<MCUCR_ISC10);
	MCUCR|=0b10<<MCUCR_ISC10;



#elif(INT1_SENSECTRL==u8_LOW_LEVEL)

	MCUCR&=~(0b11<<MCUCR_ISC10);

#elif(INT1_SENSECTRL==u8_ON_CHANGE)

	MCUCR&=~(0b11<<MCUCR_ISC10);
	MCUCR|=0b1<<MCUCR_ISC10;


#elif(INT1_SENSECTRL==u8_RISING_EDGE)

	MCUCR&=~(0b11<<MCUCR_ISC10);
	MCUCR|=0b11<<MCUCR_ISC10;
#else
#error Wrong Sense Control  Conifig INT1 options

#endif



#if(INT2_SENSECTRL==u8_FALLING_EDGE)

	MCUCSR &=~(1<<MCUCSR_ISC2);




#elif(INT2_SENSECTRL==u8_RISING_EDGE)

	MCUCSR |=(1<<MCUCSR_ISC2);

#else
#error Wrong Sense Control  Conifig INT2options


#endif

#if(INT0_INITSTATE==u8ENABLE)
	GICR|=(1<<GICR_INT0);

#elif(INT0_INITSTATE==u8DISABLE)

	GICR&=~(1<<GICR_INT0);

#else
#error Wrong Conifig INT0 Intialize  Options

#endif

#if(INT1_INITSTATE==u8ENABLE)
	GICR|=(1<<GICR_INT1);

#elif(INT1_INITSTATE==u8DISABLE)

	GICR&=~(1<<GICR_INT1);

#else
#error Wrong Conifig INT1 Intialize  Options

#endif

#if(INT2_INITSTATE==u8ENABLE)

	GICR|=(1<<GICR_INT2);

#elif(INT2_INITSTATE==u8DISABLE)

	GICR&=~(1<<GICR_INT2);

#else
#error Wrong Conifig INT2 Intialize  Options

#endif

}
uint8t EXTI_u8SetSenseCtrl(IntChannel_t copy_IntCh,INTSenseCtrl_t copy_Sensctrl)
{
	uint8t local_u8ErrorState=OK;
	if(copy_IntCh >INT2 || copy_Sensctrl>RISING_EDGE)
	{
		local_u8ErrorState=NOK;
	}
	else
	{
		if(copy_IntCh==INT0)
		{
			switch(copy_Sensctrl)
			{
			case LOW_LEVEL :MCUCR&=~(0b11<<MCUCR_ISC00); break;
			case ON_CHANGE:MCUCR&=~(0b11<<MCUCR_ISC00);MCUCR|=(0b1<<MCUCR_ISC00); break;
			case FALLING_EDGE:MCUCR&=~(0b11<<MCUCR_ISC00);MCUCR|=(0b10<<MCUCR_ISC00); break;
			case RISING_EDGE:MCUCR&=~(0b11<<MCUCR_ISC00);MCUCR|=(0b11<<MCUCR_ISC00); break;
			default:local_u8ErrorState=NOK;
			}
		}
		else	if(copy_IntCh==INT1)
		{
			switch(copy_Sensctrl)
			{
			case LOW_LEVEL :MCUCR&=~(0b11<<MCUCR_ISC10); break;
			case ON_CHANGE:MCUCR&=~(0b11<<MCUCR_ISC10);MCUCR|=(0b1<<MCUCR_ISC10); break;
			case FALLING_EDGE:MCUCR&=~(0b11<<MCUCR_ISC10);MCUCR|=(0b10<<MCUCR_ISC10); break;
			case RISING_EDGE:MCUCR&=~(0b11<<MCUCR_ISC10);MCUCR|=(0b11<<MCUCR_ISC10); break;
			default:local_u8ErrorState=NOK;
			}
		}

		else if(copy_IntCh==INT2)
		{
			switch(copy_Sensctrl)
			{
			case FALLING_EDGE:MCUCSR&=~(0b1<<MCUCSR_ISC2); break;
			case RISING_EDGE:MCUCSR|=(0b1<<MCUCSR_ISC2); break;
			default:local_u8ErrorState=NOK;
			}
		}
	}
	return local_u8ErrorState;
}

uint8t EXTI_u8Enable(IntChannel_t copy_IntCh)
{
	uint8t local_u8ErrorState=OK;
	if(copy_IntCh>INT2 || copy_IntCh<INT0)
	{
		local_u8ErrorState=NOK;
	}
	else
	{
		switch(copy_IntCh)
		{
		case INT0:	GICR|=(1<<GICR_INT0);break;
		case INT1:	GICR|=(1<<GICR_INT1);break;
		case INT2:	GICR|=(1<<GICR_INT2);break;
		default:		local_u8ErrorState=NOK;break;

		}
	}
	return local_u8ErrorState;

}
uint8t EXTI_u8Disable(IntChannel_t copy_IntCh)
{
	uint8t local_u8ErrorState=OK;
	if(copy_IntCh>INT2 || copy_IntCh<INT0)
	{
		local_u8ErrorState=NOK;
	}
	else
	{
		switch(copy_IntCh)
		{
		case INT0:	GICR&=~(1<<GICR_INT0);break;
		case INT1:	GICR&=~(1<<GICR_INT1);break;
		case INT2:	GICR&=~(1<<GICR_INT2);break;
		default:		local_u8ErrorState=NOK;break;

		}
	}
	return local_u8ErrorState;
}
uint8t EXTI_u8SetCallBack(void (*copy_pfunction)(void),IntChannel_t copy_IntCh)
{
	uint8t local_u8ErrorState=OK;
	if(copy_pfunction==NULL)
	{
		local_u8ErrorState=NULLPTR;
	}

	else if(copy_IntCh>INT2)
	{
		local_u8ErrorState=NOK;

	}

	else
	{

		ptrfunc[copy_IntCh]=copy_pfunction;
	}

	return local_u8ErrorState;

}


void __vector_1(void)__attribute__((signal));
void __vector_1(void)
{
	if(ptrfunc[INT0]!=NULL)
	{
		ptrfunc[INT0]();

	}
}


void __vector_2(void)__attribute__((signal));
void __vector_2(void)
{
	if(ptrfunc[INT1]!=NULL)
	{
		ptrfunc[INT1]();

	}
}


void __vector_3(void)__attribute__((signal));
void __vector_3(void)
{
	if(ptrfunc[INT2]!=NULL)
	{
		ptrfunc[INT2]();

	}
}





