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
#include "bsp_spi_max6675.h"


int main(void)
{
	

	
	SysTick_Configuration();
	 
	TIM2_PWM_Configuration();//脉冲周期：200ms
	
	TIM_SetCompare2(TIM2,5000);//占空比50%，即100ms高电平时间
	
    TIM3_InputCapture_Configuration();//杜邦线让PA1与PA6连在一起
	
     Uart1_Configuration();
	
	while(1)
	{
	   if(high_complete_flag==1)
	   {
		   printf("High level=%d us\n",period_times*65536+high_value);
		   
		   high_complete_flag=0;
		   period_times=0;
	   }
		Delay_us(100000);
	   
		} 
	}


