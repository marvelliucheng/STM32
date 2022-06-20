#include "bsp_lcd1602.h"





void LCD1602_GPIO_Configuration(void)
{
	
	
		GPIO_InitTypeDef GPIO_InitStructure;
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC , ENABLE);
	    GPIO_InitStructure.GPIO_Pin =GPIO_Pin_5| GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12;  
	    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	    GPIO_Init(GPIOA, &GPIO_InitStructure);
	    
	    GPIO_InitStructure.GPIO_Pin =GPIO_Pin_5| GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;   
	    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	    GPIO_Init(GPIOB, &GPIO_InitStructure);
	    GPIO_InitStructure.GPIO_Pin =GPIO_Pin_13;   
	    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	    GPIO_Init(GPIOC, &GPIO_InitStructure);
}



void LCD1602_Wait_Ready(void)
{
	//首先将PC13改为输入
	GPIOC->CRH &=0XFF0FFFF;
	GPIOC->CRH |=4<<20;
	LCD1602_RS_Clr();	
	LCD1602_RS_Set();
	LCD1602_EN_Set();
	Delay_us(5000);
	
    while(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13)==0x1);
	
	//LCD1602就绪后，再将PC13(DB7)改为输出
	
	GPIOC->CRH &=0XFF0FFFF;
	GPIOC->CRH |=3<<20;
	
	LCD1602_EN_Clr();
	
}
	

	

void LCD1602_Write_Cmd(unsigned char cmd)
{
	LCD1602_Wait_Ready();
	LCD1602_RS_Clr();
	LCD1602_Rw_Clr();
	
	
	SET_LCD1602_D0((cmd>>0)&0x1);
	SET_LCD1602_D1((cmd>>1)&0x1);
	SET_LCD1602_D2((cmd>>2)&0x1);
	SET_LCD1602_D3((cmd>>3)&0x1);
	SET_LCD1602_D4((cmd>>4)&0x1);
	SET_LCD1602_D5((cmd>>5)&0x1);
	SET_LCD1602_D6((cmd>>6)&0x1);
	SET_LCD1602_D7((cmd>>7)&0x1);

	
	LCD1602_EN_Set();
	LCD1602_EN_Clr();
	
}
void LCD1602_Write_Dat(unsigned char dat)
{

     LCD1602_Wait_Ready();
	 LCD1602_RS_Set();
	 LCD1602_Rw_Clr();
    LCD1602_EN_Set();
	LCD1602_EN_Clr();
	SET_LCD1602_D0((dat>>0)&0x1);
	SET_LCD1602_D1((dat>>1)&0x1);
	SET_LCD1602_D2((dat>>2)&0x1);
	SET_LCD1602_D3((dat>>3)&0x1);
	SET_LCD1602_D4((dat>>4)&0x1);
	SET_LCD1602_D5((dat>>5)&0x1);
	SET_LCD1602_D6((dat>>6)&0x1);
	SET_LCD1602_D7((dat>>7)&0x1);
}	
void LCD1602_Clear_Screen(void)
{
	LCD1602_Write_Cmd(0x01);
	
	
	
	
	
}
void LCD1602_Set_Cursor(unsigned char x,unsigned char y)
{
	unsigned char addr;
	
	
	if(y==0)
    	addr=0x00+x;
	else
		addr=0x40|x;
	LCD1602_Write_Cmd(0x80|addr);
	
	
	
	
}
void LCD1602_Show_Char(unsigned char x,unsigned char y, unsigned char dat)
{
	LCD1602_Set_Cursor(x,y);
	
	LCD1602_Write_Dat(dat);
	
	
}

void LCD1602_Show_Str(unsigned char x,unsigned char y, unsigned char *str)
{
		
	LCD1602_Set_Cursor(x,y);
	while(*str)
	LCD1602_Write_Dat(*str++);	
	
}

void LCD1602_Init(void)
{
	
	LCD1602_Write_Cmd(0x38);//两行显示，5*7点阵，8位数据线
	LCD1602_Write_Cmd(0x0C);//开显示，关闭光标
	LCD1602_Write_Cmd(0x06);//屏幕文字不动，然后光标向右移动
	LCD1602_Write_Cmd(0x01);//清屏
	
}
