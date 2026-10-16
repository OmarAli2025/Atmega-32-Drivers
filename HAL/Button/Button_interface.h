/*
 * Button_interface.h
 *
 *  Created on: Oct 13, 2026
 *      Author: hp
 */

#ifndef BUTTON_INTERFACE_H_
#define BUTTON_INTERFACE_H_


typedef enum
{
	u8_PRESSED,
	u8_UNPRESSED

}Buttonstate_t;

typedef enum
{
	u8_PULLDOWN,
	u8_PULLUP

}ButtonMode_t;

typedef struct
{
	uint8t  local_u8ButtonPort;
	uint8t  local_u8ButtonPin;
	ButtonMode_t local_ButtonMode;

}ButtonCofig_t;

uint8t Button_voidUpdateRead(uint8t copy_u8DIOPort,uint8t copy_u8DIOPin,uint8_t* copy_pu8Value );

uint8t Button_u8GetState(const ButtonCofig_t *pButtonConfig,Buttonstate_t* local_pButtonMode);







#endif /* BUTTON_INTERFACE_H_ */
