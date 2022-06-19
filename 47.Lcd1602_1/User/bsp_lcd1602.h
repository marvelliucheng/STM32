#ifndef _BSP_LCD1602_H_
#define _BSP_LCD1602_H_



#include <stm32f10x.h>



void LCD1602_GPIO_Configuration(void);
void LCD1602_Init(void);
/******LCD1602管脚定义************/
// 1.lcd1602 VSS--------GND
// 2.lcd1602 VCC--------3.3V
// 3.lcd1602 VEE--------通过电位器接GND
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