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
	int key_num;
	
	SysTick_Configuration();
	
	Uart1_Configuration();
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	while(1)
	{
		key_num = Matrix_Key_Scan();
		if(key_num != 0)
			printf("Key %d is pressed.\n", key_num);
	}
}

