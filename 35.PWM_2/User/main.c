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
	

	
	SysTick_Configuration();
	
    TIM2_PWM_Configuration();   //PA1  TIM2_CH2
	

	while(1)
	{
		      TIM_SetCompare2(TIM2, 500);  //0.5ms--0
			  Delay_us(1000000);
		      TIM_SetCompare2(TIM2, 1000);  //1ms--45
			  Delay_us(1000000);
			  TIM_SetCompare2(TIM2, 1500);  //1ms--90
			  Delay_us(1000000);
			  TIM_SetCompare2(TIM2, 2000);  //1ms--135
			  Delay_us(1000000);	
		      TIM_SetCompare2(TIM2, 2500);  //1ms--180
			  Delay_us(1000000);
		} 
	}


