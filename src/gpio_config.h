/*
 * gpio_config.h
 *
 *  Created on: 11 Mar 2021
 *      Author: tylan
 */

#ifndef GPIO_CONFIG_H_
#define GPIO_CONFIG_H_

#include "stm32f10x.h"

void GPIO_BitSel(GPIO_TypeDef* GPIO,int Pin);
void GPIO_WriteHighPin(GPIO_TypeDef* GPIO,int Pin);
void GPIO_WriteLowPin(GPIO_TypeDef* GPIO,int Pin);
void delay(uint32_t time);
#endif /* GPIO_CONFIG_H_ */
