#include "bsp_tim.h"

unsigned int times = 0;
unsigned int high_value=0;
unsigned char high_complete_flag=0;
unsigned int period_times=0;

void TIM2_BaseConfiguration(void)
{

	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	
	
	TIM_TimeBaseStructure.TIM_Period = 0xffff;  //999+1 =1000
	TIM_TimeBaseStructure.TIM_Prescaler = 719;  //71+1= 720分频
	//TIM_TimeBaseStructure.TIM_ClockDivision = 0x0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
	

	TIM_Cmd(TIM2, ENABLE);
	//暂时先关闭TIM2时钟，等全部初始化结束后正式使用定时器前再开启
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
	

	TIM_TimeBaseStructure.TIM_Period = 1999;  //999+1 =1000 1KHz的方波
	TIM_TimeBaseStructure.TIM_Prescaler = 71;  //71+1= 72分频
	//TIM_TimeBaseStructure.TIM_ClockDivision = 0x0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);
	
	
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;  
    TIM_OCInitStructure.TIM_Pulse = 1000;//决定占空比 
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; 
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OC3Init(TIM4, & TIM_OCInitStructure); 
	TIM_Cmd(TIM4, ENABLE);
	
	
}
//PB6（ouput）:TRIG  PB7（input）:ECHO
void HCSR04_GPIO_Configuration(void)
{
	 GPIO_InitTypeDef GPIO_InitStructure;

	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB , ENABLE); 
   
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode =  GPIO_Mode_Out_PP; //修改的地方
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode =  GPIO_Mode_IN_FLOATING; //修改的地方
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
}


void  TIM3_InputCapture_Configuration(void)
{
	
    GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_ICInitTypeDef TIM_ICInitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING ; //修改的地方
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	TIM_TimeBaseStructure.TIM_Period = 0xffff;  //当前测量的单次测量的最大周期是65.535ms
	TIM_TimeBaseStructure.TIM_Prescaler = 71;  //71+1= 72分频
	//TIM_TimeBaseStructure.TIM_ClockDivision = 0x0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
	TIM_DeInit(TIM2); 
  
    
   TIM_ICInitStructure.TIM_Channel = TIM_Channel_1; 
   TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising; 
   TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI; 
   TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1; 
   TIM_ICInitStructure.TIM_ICFilter = 0x0; 
   TIM_ICInit(TIM3, &TIM_ICInitStructure);

    
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);	
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
	TIM_ClearFlag(TIM3,TIM_FLAG_CC1);
	TIM_ITConfig(TIM3,TIM_FLAG_CC1|TIM_IT_Update,ENABLE);	
	TIM_Cmd(TIM2,ENABLE);
	
	
}
 void TIM3_IRQHandler(void)
 {
      static unsigned char high_flag=0;
	if(high_complete_flag==0)
	 {
		 if(TIM_GetITStatus(TIM3,TIM_IT_Update)==SET)
		 {
			if(high_flag==1)
               period_times++;
			
		 }
      if(TIM_GetITStatus(TIM3,TIM_FLAG_CC1)==SET)
	  {
		 if(high_flag==0) //上升沿
		 {
			  TIM_SetCounter(TIM3,0);
		      high_flag=1;
			  high_value=0;
			 
		     TIM_OC1PolarityConfig(TIM3, TIM_OCPolarity_Low); 
		  
		 }
		 else//下降沿
		 {
			 
			  high_value=TIM_GetCounter(TIM3);
			  TIM_OC1PolarityConfig(TIM3, TIM_OCPolarity_High); 
			  high_flag=1;	 
			  high_complete_flag=1;
			 
		 }
	  }
	  
     TIM_ClearITPendingBit(TIM3,TIM_FLAG_CC1|TIM_IT_Update);
	 


	 }	
 } 