#ifndef _BSP_HCSR04_H_
#define _BSP_HCSR04_H_




#include "stm32f10x.h"
#define TRIG_H GPIO_WriteBit(GPIOB,GPIO_Pin_6,Bit_SET)
#define TRIG_L GPIO_WriteBit(GPIOB,GPIO_Pin_6,Bit_RESET)
#define ECHO GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_7)
void TIM2_Count_Configuration(void);
void HCSR04_GPIO_Configuration(void);




#endif