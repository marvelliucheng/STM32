#ifndef _BSP_HC74595_H_
#define _BSP_HC74595_H_




#include "stm32f10x.h"
#include "bsp_SysTick.h"
#include "bsp_digitaltube_1.h"
#include "bsp_tim.h"
void  HC595_GPIO_Configuration(void);
void HC595_Send_Data(unsigned char num,unsigned char show_bit);
void display(unsigned int n);



#endif