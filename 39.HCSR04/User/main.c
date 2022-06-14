#include "Led_Key.h"
#include "bsp_exti.h"
#include "bsp_SysTick.h"
#include "bsp_iwdg.h"
#include "bsp_wwdg.h"
#include "bsp_uart.h"
#include "bsp_dma.h"
#include "bsp_adc.h"
#include "bsp_tim.h"
#include "bsp_rtc.h"
#include "music.h"
#include "bsp_hcsr04.h"



int main(void)
{
	unsigned  time;
	
   float distance=0;
	
	
	SysTick_Configuration();
	
    Uart1_Configuration();
	
	TIM2_Count_Configuration();
	
	HCSR04_GPIO_Configuration();
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

	while(1)
	{
	    TIM_Cmd(TIM2,ENABLE);	
		TRIG_H;
		Delay_us(15);
		TRIG_L;
		 while(ECHO==0);
		TIM_SetCounter(TIM2,0);
		while(ECHO==1);
		TIM_Cmd(TIM2,DISABLE);
		time=TIM_GetCounter(TIM2);
		distance=time*0.017;
		printf("Distance=%.2f\n",distance);
		Delay_us(1000000);
		
		
		} 
	}


