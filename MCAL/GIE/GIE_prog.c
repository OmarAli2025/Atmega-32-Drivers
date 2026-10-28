/*
 * GIE_prog.c
 *
 *  Created on: Oct 23, 2026
 *      Author: hp
 */

#include "StdLib.h"
#include "ErrorStates.h"
#include "BIT_MATH.h"

#include "GIE_reg.h"
#include "GIE_interface.h"
#include "GIE_cfg.h"
#include "GIE_pvt.h"

void GIE_voidEnableGlobal(void)
{
	/*SREG|=(1<<SREG_I);*/
	__asm volatile("SEI");/*Inline Assembly:Set I bit*/
}

void GIE_voidDisableGlobal(void)
{
	/*SREG&=~(1<<SREG_I);*/
	__asm volatile("CLI");/*Inline Assembly:Clear I bit*/

}
