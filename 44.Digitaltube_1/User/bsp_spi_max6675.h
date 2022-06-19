#ifndef _BSP_SPI_MAX6675_H_
#define _BSP_SPI_MAX6675_H_



#include "stm32f10x.h"

#define  MAX6675_CS_LOW  GPIO_WriteBit(GPIOA,GPIO_Pin_4,Bit_RESET);
#define  MAX6675_CS_HIGH GPIO_WriteBit(GPIOA,GPIO_Pin_4,Bit_SET);



void SPI1_Configuration(void);
u16 SPI_read(void);

#endif