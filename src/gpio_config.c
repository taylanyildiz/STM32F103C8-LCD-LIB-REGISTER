/*
 * gpio_config.c
 *
 *  Created on: 11 Mar 2021
 *      Author: tylan
 */

#include "gpio_config.h"
#include "stm32f10x.h"

void GPIO_BitSel(GPIO_TypeDef *GPIO,int Pin)
{
	// OUTPUT MODE
	if(Pin < 8)
	{
		/*
		 * MODE[0,1]
		 * CNF[2,3]
		 * 4 bit for every pin
		 */
		if((GPIO->CRL & 0x11111111) <= 0)
		{
			GPIO->CRL  = 1 << (Pin * 4) | 1 << ((Pin * 4) + 1);
		}
		else
		{
			GPIO->CRL  |= 1 << (Pin * 4) | 1 << ((Pin * 4) + 1);
		}

	}
	else if(Pin > 8)
	{
		GPIO->CRH |= 1 << (Pin * 4);
	}
}
void GPIO_WriteHighPin(GPIO_TypeDef *GPIO,int Pin)
{
	if(GPIO->ODR == 0)
	{
		GPIO->ODR = 1 << Pin;
	}
	else{
		GPIO->ODR |= 1 << Pin;
	}
}
void GPIO_WriteLowPin(GPIO_TypeDef *GPIO,int Pin)
{
	GPIO->BSRR  = 1 << Pin;
}

void delay(uint32_t time)
{
	while(time--);
}
