/*
 * EXTI_cfg.h
 *
 *  Created on: Oct 23, 2026
 *      Author: hp
 */

#ifndef EXTI_CFG_H_
#define EXTI_CFG_H_
													/*	Configure INT0 Channel Sense Control :
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	1-u8_LOW_LEVEL
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	2-u8_ON_CHANGE
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	3:-u8_FALLING_EDGE
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	4-u8_RISING_EDGE	 	 */

# define INT0_SENSECTRL 																			u8_FALLING_EDGE

													/*	Configure INT1 Channel Sense Control :
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	1-u8_LOW_LEVEL
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	2-u8_ON_CHANGE
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	3:-u8_FALLING_EDGE
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	4-u8_RISING_EDGE	 	 */

# define INT1_SENSECTRL																			u8_FALLING_EDGE

													/*	Configure INT2 Channel Sense Control :
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	1:-u8_FALLING_EDGE
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	2-u8_RISING_EDGE	 	 */

# define INT2_SENSECTRL																			 u8_FALLING_EDGE

													/*	Configure INT0 Channel Initial State :
												 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 1-u8ENABLE
												 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 2-u8DISABLE */

# define INT0_INITSTATE  																			 u8ENABLE

													/*	Configure INT1 Channel Initial State :
												 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 1-u8ENABLE
												 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 2-u8DISABLE */

# define INT1_INITSTATE  																			 u8DISABLE

													/*	Configure INT2 Channel Initial State :
												 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 1-u8ENABLE
												 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 2-u8DISABLE */

# define INT2_INITSTATE  																			 u8ENABLE











#endif /* EXTI_CFG_H_ */
