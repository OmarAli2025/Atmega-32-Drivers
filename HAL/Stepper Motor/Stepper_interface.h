/*
 * Stepper_interface.h
 *
 *  Created on: Oct 21, 2026
 *      Author: hp
 */

#ifndef STEPPER_INTERFACE_H_
#define STEPPER_INTERFACE_H_

typedef enum
{
	CW,
	CCW


}StepperDirection_t;


typedef struct
{
	uint8t u8_PortID;
	uint8t u8_BluePin;
	uint8t u8_PinkPin;
	uint8t u8_YellowPin;
	uint8t u8_OrangePin;

}StepperConfig_t;

uint8t StepperMotor_u8Rotate(const StepperConfig_t * copy_pstepperconig,StepperDirection_t copy_stepperDirection,uint16t copy_u16Angle);

#endif /* STEPPER_INTERFACE_H_ */
