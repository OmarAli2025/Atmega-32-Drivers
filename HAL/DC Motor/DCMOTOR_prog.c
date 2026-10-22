/*
 * DCMOTOR_prog.c
 *
 *  Created on: Oct 20, 2026
 *      Author: hp
 */

#include "StdLib.h"
#include "BIT_MATH.h"
#include "ErrorStates.h"

#include "DIO_interface.h"

#include "DCMOTOR_interface.h"
#include "DCMOTOR_cfg.h"
#include "DCMOTOR_pvt.h"


uint8t DCMOTOR_u8Stop(uint8t copy_u8MotorPort,uint8t copy_u8MotorPin1,uint8t copy_u8MotorPin2)
{
	uint8t local_u8ErrorState=OK;

	if(copy_u8MotorPort>DIO_u8PORTD || copy_u8MotorPin1>DIO_u8PIN7 || copy_u8MotorPin2>DIO_u8PIN7||copy_u8MotorPin1==copy_u8MotorPin2)
	{
		local_u8ErrorState=NOK;
	}

	else
	{
		local_u8ErrorState=DIO_u8SetPinValue(copy_u8MotorPort,copy_u8MotorPin1,DIO_u8LOW);
		local_u8ErrorState=DIO_u8SetPinValue(copy_u8MotorPort,copy_u8MotorPin2,DIO_u8LOW);

	}

	return local_u8ErrorState;
}

uint8t DCMOTOR_u8RotateClockwise(uint8t copy_u8MotorPort,uint8t copy_u8MotorPin1,uint8t copy_u8MotorPin2)
{
	uint8t local_u8ErrorState=OK;

	if(copy_u8MotorPort>DIO_u8PORTD || copy_u8MotorPin1>DIO_u8PIN7 || copy_u8MotorPin2>DIO_u8PIN7||copy_u8MotorPin1==copy_u8MotorPin2)
	{
		local_u8ErrorState=NOK;
	}

	else
	{
		local_u8ErrorState=DIO_u8SetPinValue(copy_u8MotorPort,copy_u8MotorPin2,DIO_u8LOW);
		local_u8ErrorState=DIO_u8SetPinValue(copy_u8MotorPort,copy_u8MotorPin1,DIO_u8HIGH);

	}

	return local_u8ErrorState;
}

uint8t DCMOTOR_u8RotateCounterClockwise(uint8t copy_u8MotorPort,uint8t copy_u8MotorPin1,uint8t copy_u8MotorPin2)
{
	uint8t local_u8ErrorState=OK;

	if(copy_u8MotorPort>DIO_u8PORTD || copy_u8MotorPin1>DIO_u8PIN7 || copy_u8MotorPin2>DIO_u8PIN7||copy_u8MotorPin1==copy_u8MotorPin2)
	{
		local_u8ErrorState=NOK;
	}

	else
	{
		local_u8ErrorState=DIO_u8SetPinValue(copy_u8MotorPort,copy_u8MotorPin1,DIO_u8LOW);
		local_u8ErrorState=DIO_u8SetPinValue(copy_u8MotorPort,copy_u8MotorPin2,DIO_u8HIGH);

	}

	return local_u8ErrorState;
}
