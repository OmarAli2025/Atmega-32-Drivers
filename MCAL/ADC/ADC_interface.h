/*
 * ADC_interface.h
 *
 *  Created on: Oct 26, 2026
 *      Author: hp
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

typedef enum
{
	ADC0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7,
	ADC0_ADC0X10,
	ADC1_ADC0X10,
	ADC0_ADC0X200,
	ADC1_ADC0X200,
	ADC2_ADC2X10,
	ADC3_ADC2X10,
	ADC2_ADC2X200,
	ADC3_ADC2X200,
	ADC0_ADC1X1,
	ADC1_ADC1X1,
	ADC2_ADC1X1,
	ADC3_ADC1X1,
	ADC4_ADC1X1,
	ADC5_ADC1X1,
	ADC6_ADC1X1,
	ADC7_ADC1X1,
	ADC0_ADC2X1,
	ADC1_ADC2X1,
	ADC2_ADC2X1,
	ADC3_ADC2X1,
	ADC4_ADC2X1,
	ADC5_ADC2X1,
	ADC_VBG,
	ADC_GND

}ADC_Channels_t;


void ADC_voidInit(void);
uint8t ADC_getChannelReading(ADC_Channels_t copy_ADCchanel,uint16t * copy_pu16ADC_data);
uint8t ADC_getChannel8bitReading(ADC_Channels_t copy_ADCchanel,uint8t * copy_pu8ADC_data);

#endif /* ADC_INTERFACE_H_ */
