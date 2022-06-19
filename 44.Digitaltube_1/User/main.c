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
#include "bsp_digitaltube_1.h"

int main(void)
{
	int i;

	
	SysTick_Configuration();
	 
    Digital_tube_Configuration();
	
//	GPIOA->ODR=num;//GPIOA->ODR=0XA4;
	
	while(1)
	{
	      for(i=0;i<12;i++)
		{
			GPIOA->ODR=num[i];
			Delay_us(500000);
			
			
			
		}
	}


}