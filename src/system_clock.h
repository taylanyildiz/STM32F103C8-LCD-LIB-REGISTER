/*
 * system_clock.h
 *
 *  Created on: 11 Mar 2021
 *      Author: tylan
 */

#ifndef SYSTEM_CLOCK_H_
#define SYSTEM_CLOCK_H_

#include "stm32f10x.h"


void SYS_Config(void);
void PortEnable(GPIO_TypeDef* GPIO);


#endif /* SYSTEM_CLOCK_H_ */
