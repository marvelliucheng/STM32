#include "bsp_HC74595.h"





//SCLK:PB13  RCLK:PB12   DIO:PB15

void HC595_GPIO_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_WriteBit(GPIOB,GPIO_Pin_12,Bit_RESET);
	GPIO_WriteBit(GPIOB,GPIO_Pin_13,Bit_RESET);
	GPIO_WriteBit(GPIOB,GPIO_Pin_15,Bit_RESET);
	
	
		
}
//¥Æ»Î
void HC595_Send_Byte(unsigned char byte)
{
	
	unsigned int i;
	
	
	for(i=0;i<8;i++)
	{
		if(byte&0x80)
		{
			GPIO_WriteBit(GPIOB,GPIO_Pin_15,Bit_SET);			
		}
		else
			
	GPIO_WriteBit(GPIOB,GPIO_Pin_15,Bit_RESET);
	GPIO_WriteBit(GPIOB,GPIO_Pin_13,Bit_RESET);
	Delay_us(10);
	GPIO_WriteBit(GPIOB,GPIO_Pin_13,Bit_SET);
	Delay_us(10);
	
		byte << 1;
		
	}
}
//≤¢≥ˆ

void HC595_Send_Data(unsigned char num,unsigned char show_bit)
{
	
	
	HC595_Send_Byte(num);
	HC595_Send_Byte(1<<show_bit);
	
	GPIO_WriteBit(GPIOB,GPIO_Pin_12,Bit_RESET);
	Delay_us(10);
	GPIO_WriteBit(GPIOB,GPIO_Pin_12,Bit_SET);
	Delay_us(10);
	
}	
void display(unsigned int n)
{
	static unsigned int thousand_bit,hundred_bit,ton_bit,single_bit;
	
	thousand_bit=n/1000;
	hundred_bit=(n%1000)/100;
	ton_bit=n%1000%100/10;
	single_bit=n%10;
	HC595_Send_Data(num[thousand_bit],3);
	HC595_Send_Data(num[hundred_bit],2);
	HC595_Send_Data(num[ton_bit],1);
	HC595_Send_Data(num[single_bit],0);
}