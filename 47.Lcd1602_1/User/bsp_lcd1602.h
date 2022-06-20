#ifndef _BSP_LCD1602_H_
#define _BSP_LCD1602_H_



#include <stm32f10x.h>
#include "bsp_SysTick.h"



#define LCD1602_RS_Set()  GPIO_SetBits(GPIOA,GPIO_Pin_5)
#define LCD1602_RS_Clr()  GPIO_ResetBits(GPIOA,GPIO_Pin_5)



#define LCD1602_Rw_Set()  GPIO_SetBits(GPIOB,GPIO_Pin_12)
#define LCD1602_Rw_Clr()  GPIO_ResetBits(GPIOB,GPIO_Pin_12)


#define LCD1602_EN_Set()  GPIO_SetBits(GPIOB,GPIO_Pin_13)
#define LCD1602_EN_Clr()  GPIO_ResetBits(GPIOB,GPIO_Pin_13)


#define LCD1602_EN_Set()  GPIO_SetBits(GPIOB,GPIO_Pin_13)
#define LCD1602_EN_Clr()  GPIO_ResetBits(GPIOB,GPIO_Pin_13)


#define SET_LCD1602_D0(a) GPIO_WriteBit(GPIOB,GPIO_Pin_14,(BitAction)(a))
#define SET_LCD1602_D1(a) GPIO_WriteBit(GPIOB,GPIO_Pin_15,(BitAction)(a))
#define SET_LCD1602_D2(a) GPIO_WriteBit(GPIOB,GPIO_Pin_9,(BitAction)(a))
#define SET_LCD1602_D3(a) GPIO_WriteBit(GPIOB,GPIO_Pin_10,(BitAction)(a))
#define SET_LCD1602_D4(a) GPIO_WriteBit(GPIOB,GPIO_Pin_11,(BitAction)(a))
#define SET_LCD1602_D5(a) GPIO_WriteBit(GPIOB,GPIO_Pin_12,(BitAction)(a))
#define SET_LCD1602_D6(a) GPIO_WriteBit(GPIOB,GPIO_Pin_5,(BitAction)(a))
#define SET_LCD1602_D7(a) GPIO_WriteBit(GPIOC,GPIO_Pin_13,(BitAction)(a))

void LCD1602_GPIO_Configuration(void);
void LCD1602_Init(void);
void LCD1602_Show_Str(unsigned char x,unsigned char y, unsigned char *str);
void LCD1602_Show_Char(unsigned char x,unsigned char y, unsigned char dat);
void LCD1602_Clear_Screen(void);
void LCD1602_Write_Cmd(unsigned char cmd);
/******LCD1602�ܽŶ���************/
// 1.lcd1602 VSS--------GND
// 2.lcd1602 VCC--------3.3V
// 3.lcd1602 VEE--------ͨ����λ����GND
// 4.lcd1602 RS--------PA5
// 5.lcd1602 R/S-------PB12
// 6.lcd1602 E --------PB13
// 7.lcd1602 DB0-------PB14
// 8.lcd1602 DB1-------PB15
// 9.lcd1602 DB2-------PA9
// 10.lcd1602 DB3------PA10
// 11.lcd1602 DB4------PA11
// 12.lcd1602 DB5------PA12
// 13.lcd1602 DB6------PB5
// 14.lcd1602 DB7------PC13
// 15.lcd1602 A-------3.3V
// 16.lcd1602 K-------GND


#endif 