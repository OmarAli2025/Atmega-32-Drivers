/*
 * LED_prog.c
 *
 *  Created on: Oct 14, 2026
 *      Author: hp
 */

#include "stdlib.h"
#include "ErrorStates.h"
# include "DIO_interface.h"
#include "LED_interface.h"
#include "LED_pvt.h"
#include "LED_cfg.h"


uint8t LED_u8LEDON(const LEDConfig_t *copy_pLEDcfg_t)
{
	uint8t local_u8ErrorState=OK;
		if(copy_pLEDcfg_t==NULL)
		{
			local_u8ErrorState=NULLPTR;
		}
		else
		{
			if(copy_pLEDcfg_t->local_LEDACTt_ledtype==ACTIVEHIGH)
			{
				local_u8ErrorState=DIO_u8SetPinValue(copy_pLEDcfg_t->local_u8PORTLED,copy_pLEDcfg_t->local_u8PINLED,DIO_u8HIGH);

			}
			else if(copy_pLEDcfg_t->local_LEDACTt_ledtype==ACTIVELOW)
			{
				local_u8ErrorState=DIO_u8SetPinValue(copy_pLEDcfg_t->local_u8PORTLED,copy_pLEDcfg_t->local_u8PINLED,DIO_u8LOW);

			}
			else
			{
				 local_u8ErrorState=NOK;
			}
		}

		return local_u8ErrorState;
}
uint8t LED_u8LEDOFF(const LEDConfig_t *copy_pLEDcfg_t)
{
	uint8t local_u8ErrorState=OK;
		if(copy_pLEDcfg_t==NULL)
		{
			local_u8ErrorState=NULLPTR;
		}
		else
		{
			if(copy_pLEDcfg_t->local_LEDACTt_ledtype==ACTIVEHIGH)
			{
				local_u8ErrorState=DIO_u8SetPinValue(copy_pLEDcfg_t->local_u8PORTLED,copy_pLEDcfg_t->local_u8PINLED,DIO_u8LOW);

			}
			else if(copy_pLEDcfg_t->local_LEDACTt_ledtype==ACTIVELOW)
			{
				local_u8ErrorState=DIO_u8SetPinValue(copy_pLEDcfg_t->local_u8PORTLED,copy_pLEDcfg_t->local_u8PINLED,DIO_u8HIGH);

			}
			else
			{
				 local_u8ErrorState=NOK;
			}
		}

		return local_u8ErrorState;
}
uint8t LED_u8LEDTOGGLE(const LEDConfig_t *copy_pLEDcfg_t)
{
	uint8t local_u8ErrorState=OK;
			if(copy_pLEDcfg_t==NULL)
			{
				local_u8ErrorState=NULLPTR;
			}
			else
			{
					local_u8ErrorState=DIO_u8TogglePinValue(copy_pLEDcfg_t->local_u8PORTLED,copy_pLEDcfg_t->local_u8PINLED);

			}

			return local_u8ErrorState;
}
