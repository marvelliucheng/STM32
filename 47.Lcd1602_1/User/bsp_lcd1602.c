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


void LCD1602_Write_Cmd(unsigned char cmd)
{
	LCD1602_Wait_Ready();
	LCD1602_RS_Clr();
	LCD1602_RW_Clr();
	
	
	SET_LCD_D0(cmd&(1<<0));
	
	SET_LCD_D1((cmd>>0)&0x1);
	SET_LCD_D2((cmd>>1)&0x1);
	SET_LCD_D3((cmd>>2)&0x1);
	SET_LCD_D4((cmd>>3)&0x1);
	SET_LCD_D5((cmd>>4)&0x1);
	SET_LCD_D6((cmd>>5)&0x1);
	SET_LCD_D7((cmd>>6)&0x1);
	SET_LCD_D7((cmd>>7)&0x1);
	
	LCD_EN_Set();
	LCD_EN_Clr();
	
}

void LCD1602_Init(void)
{
	
	LCD1602_Write_Cmd(0x38);//两行显示，5*7点阵，8位数据线
	LCD1602_Write_Cmd(0x0C);//开显示，关闭光标
	LCD1602_Write_Cmd(0x06);//屏幕文字不动，然后光标向右移动
	LCD1602_Write_Cmd(0x01);//清屏
	
}