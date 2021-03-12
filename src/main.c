#include "stm32f10x.h"
#include "system_clock.h"
#include "gpio_config.h"
#include "lcd.h"

void lcd_write()
{
	lcd_delay();
	GPIOA->ODR = (0xF0 & 0x41) | 1 << 3;
	lcd_delay();
	GPIOA->ODR |= 1 << 0;
	lcd_delay();
	GPIOA->ODR = (0xF0 & (0x41 << 4)) | 1 << 3;
	lcd_delay();
	GPIOA->ODR |= 1 << 0;
}

int main(void)
{
	SYS_Config();
	LCD_init();

	char number[] = "210 12";
	LCD_Write_String(number);
	while(1)
	{
	}
}
