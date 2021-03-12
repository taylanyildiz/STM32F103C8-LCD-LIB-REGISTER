/*
 * lcd.c
 *
 *  Created on: 11 Mar 2021
 *      Author: tylan
 */


#include "lcd.h"
#include "stm32f10x.h"
#include "gpio_config.h"
#include "system_clock.h"
/*
 * 4 Bit mode
*/

void LCD_init(void)
{
	/*
	 * DB4 => A4
	 * DB5 => A5
	 * DB6 => A6
	 * DB7 => A7
	 *
	 * R\W => Ground
	 * VSS => Ground
	 * VDD => PWR 5V
	 * V0 => Ground or Resistor
	 * RS => A3
	 * EN => A0
	*/

	PortEnable(GPIOA); 		//PORTA Enable
	GPIO_BitSel(GPIOA,4);	//DB4
	GPIO_BitSel(GPIOA,5);	//DB5
	GPIO_BitSel(GPIOA,6);	//DB6
	GPIO_BitSel(GPIOA,7);	//DB7
	GPIO_BitSel(GPIOA,3);	//RS
	GPIO_BitSel(GPIOA,0);	//EN
	delay(7200000);
	GPIO_WriteLowPin(GPIOA,3); // RS = 0
	/*
	 * lcd start
	 */
	lcd_delay();
	LCD_cmd(LCD_Func);
	lcd_delay();
	LCD_cmd(LCD_Clear);
	lcd_delay();
	LCD_cmd(LCD_Return);
	lcd_delay();
	LCD_cmd(LCD_Display);
	/*
	 * LCD Ready
	*/
}

void LCD_cmd(uint32_t cm)
{
	lcd_delay();
	GPIOA->ODR = 0xF0 & cm | 0<<3;
	lcd_delay();
	GPIO_WriteHighPin(GPIOA,0);
	lcd_delay();
	GPIOA->ODR = (0xF0 & (cm << 4));
	lcd_delay();
	GPIO_WriteHighPin(GPIOA,0);
}

void LCD_Write_String(char *str)
{
	for(int i = 0;str[i] != '\0';i++)
	{
		lcd_delay();
		GPIOA->ODR = (0xF0 & str[i]) | 1 << 3;
		lcd_delay();
		GPIOA->ODR |= 1 << 0;
		lcd_delay();
		GPIOA->ODR = (0xF0 & (str[i] << 4)) | 1 << 3;
		lcd_delay();
		GPIOA->ODR |= 1 << 0;
	}
	lcd_delay();
	LCD_cmd(LCD_Clear);
}

void lcd_delay()
{
	uint32_t time = 7200;
	while(time--);
}



