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

int main(void)
{
	

	
	SysTick_Configuration();
	
    TIM4_PWM_Configuration();   //PA1  TIM2_CH2
	

	while(1)
	{
		sound(tone[0]);
		Delay_us(1000000);
		sound(tone[1]);
		Delay_us(1000000);
		sound(tone[2]);
		Delay_us(1000000);
		sound(tone[3]);
		Delay_us(1000000);
		sound(tone[4]);
		Delay_us(1000000);
		sound(tone[5]);
		Delay_us(1000000);
		sound(tone[6]);
		Delay_us(1000000);
		
		    
		} 
	}


