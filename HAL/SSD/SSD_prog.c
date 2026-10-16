/*

 * SSD_prog.c
 *
 *  Created on: Oct 13, 2026
 *      Author: hp
 */
#include "stdlib.h"
#include "ErrorStates.h"
# include "DIO_interface.h"
# include "SSD_Interface.h"
# include "SSD_cfg.h"
#include "SSD_pvt.h"


extern uint8t SSD_u8SSDtype;

uint8t SSD_u8DisplayNumber(uint8t  copy_u8SSDNum,uint8t copy_u8SSDPort)
{
	 const uint8t SSD_arr[]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};

	uint8t local_u8ErrorState=OK;
	if(copy_u8SSDNum>9)
	{
		 local_u8ErrorState=NOK;

	}

	else
	{
		if(SSD_u8SSDtype==u8_COMMCATHODE)
		{
			local_u8ErrorState=DIO_u8SetPortValue(copy_u8SSDPort,(SSD_arr[copy_u8SSDNum]));

		}

		else if(SSD_u8SSDtype==u8_COMMANODE)
		{
			local_u8ErrorState=DIO_u8SetPortValue(copy_u8SSDPort,~(SSD_arr[copy_u8SSDNum]));

		}

	}

	return local_u8ErrorState;

}

uint8t  SSD_u8SSDON(uint8t copy_u8COMMPin,uint8t copy_u8SSDPort)
{
	uint8t local_u8ErrorState=OK;
	local_u8ErrorState=DIO_u8SetPinValue(copy_u8SSDPort,copy_u8COMMPin,DIO_u8LOW);
	return local_u8ErrorState;

}

uint8t  SSD_u8SSDOFF(uint8t copy_u8COMMPin,uint8t copy_u8SSDPort)
{
	uint8t local_u8ErrorState=OK;
	local_u8ErrorState=DIO_u8SetPinValue(copy_u8SSDPort,copy_u8COMMPin,DIO_u8HIGH);
	return local_u8ErrorState;

}
