#include "bsp_uart.h"
#include "bsp_SysTick.h"

void Uart1_Configuration(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_USART1, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;   //TX
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;   //RX
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	USART_InitStructure.USART_BaudRate = 115200;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	USART_Init(USART1, &USART_InitStructure);
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	USART_Cmd(USART1, ENABLE);
}

void Uart1_NVIC_Init(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);	
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

void USART_SendString(const unsigned char *pt)
{
	while(*pt)
	{
		while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) != SET);//确保发送缓冲区为空，只有发送缓冲区为空才继续发送
		USART_SendData(USART1, *pt);
		while(USART_GetFlagStatus(USART1, USART_FLAG_TC) != SET);//等待发送完成
		pt++;
	}
}

int fputc (int c, FILE *fp)
{
	while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) != SET);//确保发送缓冲区为空，只有发送缓冲区为空才继续发送
	USART_SendData(USART1, c);
	while(USART_GetFlagStatus(USART1, USART_FLAG_TC) != SET);//等待发送完成
	
	return 0;
}

int fgetc(FILE *fp)
{
	while(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) != SET);  //等待直到接收缓冲区内非空
	return (int)USART_ReceiveData(USART1);
}
void Control_Led(unsigned int LED_Number,unsigned int LED_State)
{
	
	GPIO_WriteBit(GPIOA,(uint16_t)1<<LED_Number,(BitAction)LED_State);
	
	
	
}


void USART1_IRQHandler(void)
{
	static unsigned int i=1;
	
    static unsigned int flag=0;
	
    static unsigned int arr[5]={0,0,0,0,0};
	
	
	unsigned char ch;
	while(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == SET)
	{
		ch = USART_ReceiveData(USART1);
	    if(ch==0xaa)
		{
			arr[0]=ch;
			flag=1;	
			
		}
		if(ch!=0xaa&&flag==1)
		{
			arr[i++]=ch;
			if(i==5)
			{
				flag=0;
				i=1;
				if(arr[i]+arr[2]==arr[3]&&arr[4]==0xff)
				{
//					switch(arr[1])
//					{
//						
//						case 0x01:
//					 		      if(arr[2]==0x01)
//									  GPIO_WriteBit(GPIOA,GPIO_Pin_1,Bit_SET);
//								  else
//						              GPIO_WriteBit(GPIOA,GPIO_Pin_1,Bit_RESET);
//								  break;
//								  
//						case 0x02:
//							      if(arr[2]==0x01)
//									  GPIO_WriteBit(GPIOA,GPIO_Pin_2,Bit_SET);
//								  else
//						              GPIO_WriteBit(GPIOA,GPIO_Pin_2,Bit_RESET);
//								  break;
//						 case 0x03:
//							      if(arr[2]==0x01)
//									  GPIO_WriteBit(GPIOA,GPIO_Pin_3,Bit_SET);
//								  else
//						              GPIO_WriteBit(GPIOA,GPIO_Pin_3,Bit_RESET);
//								  break;
//						case 0x04:
//							      if(arr[2]==0x01)
//									  GPIO_WriteBit(GPIOA,GPIO_Pin_4,Bit_SET);
//								  else
//						              GPIO_WriteBit(GPIOA,GPIO_Pin_4,Bit_RESET);
//								  break;
						             Control_Led(arr[1],arr[2]);
									 
									 
					}
				}
				
			}
		}
	}			
void Uart1_scan(unsigned int *pt,unsigned int bits)
{
	unsigned int i=0;
	
	unsigned int tmp[]={0,0,0,0};
	
	while(i<bits)
	{
		while(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) ==RESET);
		
		tmp[i++]=USART_ReceiveData(USART1);
	}
	if(bits==4)
		*pt=(tmp[0]-'0')*1000+(tmp[1]-'0')*100+(tmp[2]-'0')*10+(tmp[3]-'0');
	else
		*pt=(tmp[0]-'0')*10+(tmp[1]-'0');
	
}
