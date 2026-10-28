/*
 * ADC_cfg.h
 *
 *  Created on: Oct 26, 2026
 *      Author: hp
 */

#ifndef ADC_CFG_H_
#define ADC_CFG_H_

/*					Configure The ADC  Reference Selection bits:
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 		u8_AREF
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 		u8_AVCC
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 		u8_2_56AVCC	 	 	 	 	 	*/

# define ADC_REFMODE 															u8_AVCC

/*				Configure The ADC Left Adjust Result
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	  	 u8LEFTADJUST
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	  	 u8RIGHTADJUST 	 	 */

# define ADLAR_MODE 														  	 u8RIGHTADJUST
																									/*ADLAR  MUST BE ATLEFT MODE AT 8bit Resultion Func


/*				Configure ADC Prescaler:
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 u8_DIV2
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 u8_DIV4
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 u8_DIV8
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 u8_DIV16
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 u8_DIV32
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 u8_DIV64
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 u8_DIV128*/

# define ADC_PRESCALARDIV  u8_DIV128



#endif /* ADC_CFG_H_ */

