#include "Led_Key.h"
#include "bsp_exti.h"
#include "bsp_SysTick.h"
#include "bsp_iwdg.h"
#include "bsp_wwdg.h"
#include "bsp_uart.h"
#include "bsp_dma.h"
#include "bsp_adc.h"
#include "bsp_tim2.h"
#include "bsp_rtc.h"

int main(void)
{
	
	int i;
	
	SysTick_Configuration();
	
    TIM2_PWM_Configuration();
	
	
	while(1)
	{
		for(i=0;i<20000;i++)
		{
		   TIM_SetCompare2(TIM2, i);
			Delay_us(20);
			
		}
		for(i=20000;i>0;i--)
		{
		   TIM_SetCompare2(TIM2, i);
			Delay_us(20);
			
		}
	}
}

