#ifndef __BSP_TIM_H__
#define __BSP_TIM_H__

#include <stm32f10x.h>
#include "Led_Key.h"
#include <stdio.h>

extern unsigned int high_value;
extern unsigned char high_complete_flag;
extern unsigned int period_times;

void TIM2_PWM_Configuration(void);
void TIM2_Count_Configuration(void);
void TIM3_InputCapture_Configuration(void);	
#endif
