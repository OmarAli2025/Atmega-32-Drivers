/*
 * EXTI_reg.h
 *
 *  Created on: Oct 23, 2026
 *      Author: hp
 */

#ifndef EXTI_REG_H_
#define EXTI_REG_H_

# define GICR 		(*(volatile uint8t*)0x5B)  /*General Interrupt Control Register*/
# define GICR_INT2	5u                                /*INT2 bit*/
# define GICR_INT0	6u   								/*INT0 bit*/
# define GICR_INT1	7u	  							 /*INT1 bit*/

# define MCUCR 	(*(volatile uint8t*)0x55)   /*MCU Control Register*/
#define MCUCR_ISC00 0u                   			/*INT0 Sense Control*/
#define MCUCR_ISC01 1u								/*INT0 Sense Control*/
#define MCUCR_ISC10 2u								/*INT1 Sense Control*/
#define MCUCR_ISC11 3u								/*INT1 Sense Control*/

# define MCUCSR 	(*(volatile uint8t*)0x54)	/*MCU Control &Status Register*/
#define MCUCSR_ISC2 6u 								/*INT2 Sense Control*/





# define GIFR			(*(volatile uint8t*)0x5A)


#endif /* EXTI_REG_H_ */
