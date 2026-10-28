/*
 * ADC_reg.h
 *
 *  Created on: Oct 26, 2026
 *      Author: hp
 */

#ifndef ADC_REG_H_
#define ADC_REG_H_

# define ADMUX  		(*(volatile uint8t*) 0x27)
# define ADCSRA 		(*(volatile uint8t*) 0x26)
# define ADCL 			(*(volatile uint8t*) 0x24)
# define ADCH 			(*(volatile uint8t*) 0x25)
# define ADCLH			(*(volatile uint16t*) 0x24)
# define SFIOR 			(*(volatile uint8t*) 0x50)

# define ADMUX_MUX0	 0
# define ADMUX_REFS0 	 6
# define ADMUX_REFS1 	 7
# define ADMUX_ADLAR 	 5

# define ADCSRA_ADPS0 	 0
# define ADCSRA_ADIE        3
# define ADCSRA_ADIF 		 4
# define ADCSRA_ADATE	 5
# define ADCSRA_ADEN 		 7
# define ADCSRA_ADSC 		 6




#endif /* ADC_REG_H_ */
