/*
 * lcd.h
 *
 *  Created on: 11 Mar 2021
 *      Author: tylan
 */

#ifndef LCD_H_
#define LCD_H_

#include "stm32f10x.h"

#define LCD_Clear 0x01
#define LCD_Return 0x02
#define LCD_Display 0x0C
#define LCD_Func  0x20


void lcd_delay();
void LCD_init(void);
void LCD_cmd(uint32_t cm);
void LCD_Write_String(char *str);
#endif /* LCD_H_ */
