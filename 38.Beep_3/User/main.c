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
	


	int i=0;
	
	SysTick_Configuration();
	
    TIM4_PWM_Configuration();   //PA1  TIM2_CH2
	
	while(1)
	{
		while(music_little_star[i][1]!=0)
		{
			TIM_Cmd(TIM4,ENABLE);
			sound(music_little_star[i][0]);
			Delay_us(music_little_star[i][1]);
			TIM_Cmd(TIM4,DISABLE);
			Delay_us(100000);
			
			i++;
			
		}
		 i=0;
		 Delay_us(3000000);
		
			
		} 
	}


