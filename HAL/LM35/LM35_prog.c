/*
 * LM35_prog.c
 *
 *  Created on: Oct 28, 2026
 *      Author: hp
 */

#include "StdLib.h"
#include "ErrorStates.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"

# include "LM35_inteface.h"
# include "LM35_cfg.h"


uint8t LM35_u8GetTempReading(ADC_Channels_t  copy_ADCch,uint16t * copy_pu16TempReading)
{
	uint16t local_u16DigitalRead=0;
	uint8t local_u8ErrorState=OK;
	if(copy_pu16TempReading==NULL)
	{
		local_u8ErrorState=NULLPTR;
	}
	else if(copy_ADCch>ADC_GND)
	{
		local_u8ErrorState=NOK;
	}

	else
	{
		local_u8ErrorState=ADC_getChannelReading(copy_ADCch,&local_u16DigitalRead);
		if(local_u8ErrorState==OK)
		{
			*copy_pu16TempReading=(uint16t)(((uint32t)local_u16DigitalRead*(LM35_u32REFVOLT/10))/1024UL);

		}
		else
		{
		}

	}

	return local_u8ErrorState;
}
