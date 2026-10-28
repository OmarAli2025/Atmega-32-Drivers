/*
 * EXTI_interface.h
 *
 *  Created on: Oct 23, 2026
 *      Author: hp
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

typedef enum
{
	INT0,
	INT1,
	INT2

}IntChannel_t;

typedef enum
{
	LOW_LEVEL,
	ON_CHANGE,
	FALLING_EDGE,
	RISING_EDGE

}INTSenseCtrl_t;

void EXTI_voidInit(void);

uint8t EXTI_u8SetSenseCtrl(IntChannel_t copy_IntCh,INTSenseCtrl_t copy_Sensctrl);
uint8t EXTI_u8Enable(IntChannel_t copy_IntCh);
uint8t EXTI_u8Disable(IntChannel_t copy_IntCh);

uint8t EXTI_u8SetCallBack(void (*copy_pfunction)(void),IntChannel_t copy_IntCh);




#endif /* EXTI_INTERFACE_H_ */
