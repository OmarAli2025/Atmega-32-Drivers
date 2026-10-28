/*
 * DCMOTOR_interface.h
 *
 *  Created on: Oct 20, 2026
 *      Author: hp
 */

#ifndef DCMOTOR_INTERFACE_H_
#define DCMOTOR_INTERFACE_H_

//typedef struct
//{
//	uint8t DCMOTOR_u8MotorPort;
//	uint8t DCMOTOR_u8MotorPin1;
//	uint8t DCMOTOR_u8MotorPin2;
//
//}DCMOTORconfig_t;

uint8t DCMOTOR_u8Stop(uint8t copy_u8MotorPort,uint8t copy_u8MotorPin1,uint8t copy_u8MotorPin2);
uint8t DCMOTOR_u8RotateClockwise(uint8t copy_u8MotorPort,uint8t copy_u8MotorPin1,uint8t copy_u8MotorPin2);
uint8t DCMOTOR_u8RotateCounterClockwise(uint8t copy_u8MotorPort,uint8t copy_u8MotorPin1,uint8t copy_u8MotorPin2);




#endif /* DCMOTOR_INTERFACE_H_ */
