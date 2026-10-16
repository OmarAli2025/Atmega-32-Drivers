/*
 * SSD_Interface.h
 *
 *  Created on: Oct 13, 2026
 *      Author: hp
 */

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_

# define u8_COMMCATHODE 0
# define u8_COMMANODE		1

uint8t SSD_u8DisplayNumber(uint8t  copy_u8SSDNum,uint8t copy_u8SSDPort);
uint8t  SSD_u8SSDON(uint8t copy_u8COMMPin,uint8t copy_u8COMMPort);
uint8t  SSD_u8SSDOFF(uint8t copy_u8COMMPin,uint8t copy_u8COMMPort);

typedef struct
{
	uint8t  copy_u8SSDNum;
	uint8t copy_u8SSDPort;
	uint8t copy_u8COMMPin;
	uint8t tcopy_u8COMMPort;

}SSDconfig_t;


#endif /* SSD_INTERFACE_H_ */
