#include "bsp_SysTick.h"

unsigned int TimingDelay;

void SysTick_Configuration(void)
{
	while(SysTick_Config(72));
	
	SysTick->CTRL &= ~(1<<0);   //��ʱ��ʼ�����ȹرն�ʱ����ʹ��ǰ����
}

void Delay_us(unsigned int n)
{
	TimingDelay = n;
	SysTick->CTRL |= (1<<0);   //����Sys_Tick
	while(TimingDelay);
	SysTick->CTRL &= ~(1<<0);
}
