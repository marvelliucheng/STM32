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
#include "bsp_HC74595.h"

unsigned int count=0;

int main(void)
{
	int i;
   
	
	
	SysTick_Configuration();
	 
    Uart1_Configuration();
	
	RTC_Configuration();
	
	
//	GPIOA->ODR=num;//GPIOA->ODR=0XA4;
	
	while(1)
	{
	  
//	HC595_Send_Data(num[2],3); //3号数码管最左侧显示数字2
//	
//	
//	HC595_Send_Data(num[1],3); //3号数码管最左侧显示数字2
//	
//	HC595_Send_Data(num[3],3); //3号数码管最左侧显示数字2
//	
//	HC595_Send_Data(num[4],3); //3号数码管最左侧显示数字2
	Time_Display(RTC_GetCounter());
	Delay_us(100000);
		
	
	}
	count++;


}