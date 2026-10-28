/*
 * Button_prog.c
 *
 *  Created on: Oct 13, 2026
 *      Author: hp
 */
#include  "StdLib.h"
#include "ErrorStates.h"
#include  "DIO_interface.h"
#include "Button_interface.h"
# include <util/delay.h>


uint8t Button_voidUpdateRead(uint8t copy_u8DIOPort,uint8t copy_u8DIOPin,uint8_t* copy_pu8Value )
{
	uint8t ErrorState=OK;

	if(copy_u8DIOPort>DIO_u8PORTD || copy_u8DIOPin>DIO_u8PIN7)
	{
		ErrorState=NOK;
	}
	else if(copy_pu8Value==NULL)
	{
		ErrorState=NULLPTR;

	}
	else
	{
		uint8t local_u8currentstate=1,local_u8nextstate=1,local_u8Iterator=0;
		DIO_u8ReadPinValue(copy_u8DIOPort,copy_u8DIOPin,&local_u8currentstate);

		if(local_u8currentstate==0)
		{
			while(local_u8Iterator<20)
			{
				_delay_ms(1);
				DIO_u8ReadPinValue(copy_u8DIOPort,copy_u8DIOPin,&local_u8nextstate);
				if(local_u8nextstate==0)
				{
					local_u8Iterator++;
				}

				if(local_u8nextstate==1)
				{
					break;
				}

			}

			if(local_u8Iterator==20)
			{
				*copy_pu8Value=0;
			}
			else
			{
				*copy_pu8Value=1;
			}

		}
		else
		{
			*copy_pu8Value=1;
		}
	}


	return ErrorState;
}


uint8t Button_u8GetState(const ButtonCofig_t *pButtonConfig,Buttonstate_t* local_pButtonMode)
{
	uint8t local_u8ErrorState=OK;
	if(pButtonConfig==NULL || local_pButtonMode==NULL)
	{
		local_u8ErrorState=NULLPTR;
	}
	else if(pButtonConfig->local_ButtonMode>u8_PULLUP)
	{
		local_u8ErrorState=NOK;

	}
	else
	{
		uint8_t local_u8Read;

		local_u8ErrorState=DIO_u8ReadPinValue(pButtonConfig->local_u8ButtonPort,pButtonConfig->local_u8ButtonPin,&local_u8Read);

		if(pButtonConfig->local_ButtonMode==u8_PULLDOWN)
		{

			if(local_u8ErrorState==OK)
			{
				if(local_u8Read==0)
				{
					* local_pButtonMode=u8_UNPRESSED;
				}
				else if(local_u8Read==1)
				{
					* local_pButtonMode=u8_PRESSED;
				}
				else
				{
					local_u8ErrorState=NOK;
				}
			}
		}

		else if(pButtonConfig->local_ButtonMode==u8_PULLUP)
		{

			if(local_u8ErrorState==OK)
			{

				if(local_u8Read==1)
				{
					* local_pButtonMode=u8_UNPRESSED;
				}
				else if(local_u8Read==0)
				{
					* local_pButtonMode=u8_PRESSED;
				}
				else
				{
					local_u8ErrorState=NOK;

				}
			}
		}
		else
		{
			local_u8ErrorState=NOK;

		}
	}

	return local_u8ErrorState;


}










