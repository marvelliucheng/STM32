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
	
	Led_Configuration();
    Uart1_NVIC_Init();

	while(1)
	{
	   
		
		
		} 
	}


