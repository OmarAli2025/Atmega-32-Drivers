/*
 * LED_interface.h
 *
 *  Created on: Oct 14, 2026
 *      Author: hp
 */

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

typedef enum
{
	ACTIVELOW,
	ACTIVEHIGH

}LED_ACT_t;

typedef struct
{
	uint8t local_u8PORTLED;
	uint8t local_u8PINLED;
	LED_ACT_t  local_LEDACTt_ledtype;

}LEDConfig_t;

uint8t LED_u8LEDON(const LEDConfig_t *copy_pLEDcfg_t);
uint8t LED_u8LEDOFF(const LEDConfig_t *copy_pLEDcfg_t);
uint8t LED_u8LEDTOGGLEconst (const LEDConfig_t *copy_pLEDcfg_t);


#endif /* LED_INTERFACE_H_ */
