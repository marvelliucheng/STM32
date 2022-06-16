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
	

	
	u16 c;
	u16 temp;
	unsigned int flag_D2;
	float temperature;
	
	SysTick_Configuration();
	  Uart1_Configuration();
    SPI1_Configuration();
	
  
   
	while(1)
	{
	   
		MAX6675_CS_LOW;
		c=SPI_read();
		MAX6675_CS_HIGH;
		
		
		flag_D2=c&0x4;
		if(flag_D2==0)
		{
			temp=c<<1;
			temp=temp>>4;
			temperature=temp*0.25;
			printf("temperature=%4.2\n",temperature);
			
		}
		else
			printf("Sensor is broken.\n");
		Delay_us(100);
		
		} 
	}


