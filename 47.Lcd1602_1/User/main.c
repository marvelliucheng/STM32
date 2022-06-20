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
#include "bsp_lcd1602.h"


unsigned int count=0;

int main(void)
{
	
	unsigned int n=3;
	unsigned int thousand_bit,hundred_bit,ten_bit,single_bit;
	unsigned char Hex2char[]="012345678ABCDEF";
	
	
	int i;
   
	
	
	SysTick_Configuration();
	 
    LCD1602_GPIO_Configuration();
	
	LCD1602_Init();
	LCD1602_Show_Str(1,0,"STM32 LCD1602");
	LCD1602_Show_Str(2,1,"I Love you.");
	Delay_us(100000);
    LCD1602_Clear_Screen();
	
	
//	GPIOA->ODR=num;//GPIOA->ODR=0XA4;
	
	while(1)
	{
	  

//		thousand_bit=n/1000;
//		hundred_bit=n/100%10;
//		ten_bit=n/10%10;
//		single_bit=n%10;
//		
		LCD1602_Show_Char(12,1,Hex2char[thousand_bit]);
		LCD1602_Show_Char(13,1,Hex2char[hundred_bit]);
		LCD1602_Show_Char(14,1,Hex2char[ten_bit]);
		LCD1602_Show_Char(15,1,Hex2char[single_bit]);
		
		n++;
		
		LCD1602_Write_Cmd(0x18);
		
		
		Delay_us(1000000);
		
	
	}
	count++;


}