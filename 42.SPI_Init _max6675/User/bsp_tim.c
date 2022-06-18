#include "bsp_tim.h"

unsigned int times = 0;

void TIM2_BaseConfiguration(void)
{

	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	
	
	TIM_TimeBaseStructure.TIM_Period = 0xffff;  //999+1 =1000
	TIM_TimeBaseStructure.TIM_Prescaler = 71;  //71+1= 72��Ƶ
	//TIM_TimeBaseStructure.TIM_ClockDivision = 0x0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
	

	TIM_Cmd(TIM2, ENABLE);
	//��ʱ�ȹر�TIM2ʱ�ӣ���ȫ����ʼ����������ʽʹ�ö�ʱ��ǰ�ٿ���
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, DISABLE);
}

void TIM2_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
	{
		times++;
		if(times == 500)
		{
			LED_TOGGLE;
			times = 0;
		}
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
	}
}

void TIM2_PWM_Configuration(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA , ENABLE); 
   
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode =  GPIO_Mode_AF_PP; //�޸ĵĵط�
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	

	TIM_TimeBaseStructure.TIM_Period = 19999;  //999+1 =1000
	TIM_TimeBaseStructure.TIM_Prescaler = 71;  //71+1= 72��Ƶ
	//TIM_TimeBaseStructure.TIM_ClockDivision = 0x0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
	
	
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;  
   // TIM_OCInitStructure.TIM_Pulse = 0x3FFF;//����ռ�ձ� 
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OC2Init(TIM2, & TIM_OCInitStructure); 
	TIM_Cmd(TIM2, ENABLE);
}

void TIM4_PWM_Configuration(void)
{
	
	 GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);

   
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode =  GPIO_Mode_AF_PP; //�޸ĵĵط�
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	

	TIM_TimeBaseStructure.TIM_Period = 1999;  //999+1 =1000 1KHz�ķ���
	TIM_TimeBaseStructure.TIM_Prescaler = 71;  //71+1= 72��Ƶ
	//TIM_TimeBaseStructure.TIM_ClockDivision = 0x0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
	
	
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;  
    TIM_OCInitStructure.TIM_Pulse = 1000;//����ռ�ձ� 
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OC3Init(TIM4, & TIM_OCInitStructure); 
	TIM_Cmd(TIM4, ENABLE);
	
	
}
//PB6��ouput��:TRIG  PB7��input��:ECHO
void HCSR04_GPIO_Configuration(void)
{
	 GPIO_InitTypeDef GPIO_InitStructure;

	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB , ENABLE); 
   
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode =  GPIO_Mode_Out_PP; //�޸ĵĵط�
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode =  GPIO_Mode_IN_FLOATING; //�޸ĵĵط�
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
}