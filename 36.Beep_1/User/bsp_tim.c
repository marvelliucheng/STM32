#include "bsp_tim.h"

unsigned int times = 0;

void TIM2_BaseConfiguration(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);	
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
	TIM_TimeBaseStructure.TIM_Period = 999;  //999+1 =1000
	TIM_TimeBaseStructure.TIM_Prescaler = 71;  //71+1= 72分频
	//TIM_TimeBaseStructure.TIM_ClockDivision = 0x0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
	
	TIM_ClearFlag(TIM2, TIM_FLAG_Update);
	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	TIM_Cmd(TIM2, ENABLE);
	//暂时先关闭TIM2时钟，等全部初始化结束后正式使用定时器前再开启
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
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
	GPIO_InitStructure.GPIO_Mode =  GPIO_Mode_AF_PP; //修改的地方
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	

	TIM_TimeBaseStructure.TIM_Period = 19999;  //999+1 =1000
	TIM_TimeBaseStructure.TIM_Prescaler = 71;  //71+1= 72分频
	//TIM_TimeBaseStructure.TIM_ClockDivision = 0x0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
	
	
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;  
   // TIM_OCInitStructure.TIM_Pulse = 0x3FFF;//决定占空比 
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
	GPIO_InitStructure.GPIO_Mode =  GPIO_Mode_AF_PP; //修改的地方
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	

	TIM_TimeBaseStructure.TIM_Period = 999;  //999+1 =1000 1KHz的方波
	TIM_TimeBaseStructure.TIM_Prescaler = 71;  //71+1= 72分频
	//TIM_TimeBaseStructure.TIM_ClockDivision = 0x0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
	
	
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;  
    TIM_OCInitStructure.TIM_Pulse = 500;//决定占空比 
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OC3Init(TIM4, & TIM_OCInitStructure); 
	TIM_Cmd(TIM4, ENABLE);
	
	
}