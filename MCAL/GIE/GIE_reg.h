/*
 * GIE_reg.h
 *
 *  Created on: Oct 23, 2026
 *      Author: hp
 */

#ifndef GIE_REG_H_
#define GIE_REG_H_

# define SREG (*(volatile uint8t*)0x5F)  /*Status Register*/
# define SREG_I 7U								/*Global Interrupt Enable Bit*/



#endif /* GIE_REG_H_ */
