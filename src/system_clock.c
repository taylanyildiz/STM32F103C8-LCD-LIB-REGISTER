/*
 * system_clock.c
 *
 *  Created on: 11 Mar 2021
 *      Author: tylan
 */
#include "system_clock.h"
#include "stm32f10x.h"
void SYS_Config(void)
{
	RCC->CR |= 0x00010000;
	while(!(RCC->CR & 0x00020000));
	RCC->CR |= 0x00080000;
	RCC->CFGR |= 0x00010000;
	RCC->CFGR |= 0x00000000;
	RCC->CFGR |= 0x001C0000;
	RCC->CFGR |= 0x00000000;
	RCC->CFGR |= 0x00000400;
	RCC->CFGR |= 0x00000000;
	RCC->CR |= 0x01000000;
	while(!(RCC->CR & 0x02000000));
	RCC->CFGR |= 0x00000001;
	while(!(RCC->CFGR & 0x00000008));
	RCC->CIR = 0x00980000;
}

void PortEnable(GPIO_TypeDef* GPIO)
{
	if(GPIO == GPIOA)
	{
		RCC->APB2ENR |= 0x00000004;
	}
	else if(GPIO == GPIOB)
	{
		RCC->APB2ENR |= 0x00000008;
	}
	else if(GPIO == GPIOC)
	{
		RCC->APB2ENR |= 0x00000010;
	}
}

