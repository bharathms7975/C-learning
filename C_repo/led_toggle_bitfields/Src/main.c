/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2025 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>

#include "main.h"

void delay(void);

int main(void)
{
    /* Loop forever */
	//To enable the peripheral clock
	RCC_AHB1ENR_t volatile *const pClkCtrlReg = (RCC_AHB1ENR_t*)0x40023830;

	//To select GPIOD mode register
	GPIOx_MODER_t volatile *const GPIOD_MODE = (GPIOx_MODER_t*)0x40020C00;

	//To enable GPIOD output data register
	GPIOx_ODR volatile *const GPIOD_ODR = (GPIOx_ODR*)0x40020C14;


	pClkCtrlReg->gpiod_en = 1;
	GPIOD_MODE->mode_en12 = 1;
	GPIOD_MODE->mode_en13 = 1;


	for(int i=0; i<10; i++)
	{
	GPIOD_ODR->odr12 = 1;
	delay();
	GPIOD_ODR->odr12 = 0;
	delay();
	GPIOD_ODR->odr13 = 1;
	delay();
	GPIOD_ODR->odr13 = 0;
	delay();
	}



	for(;;);
}

void delay()
{
	for(int i=0; i<100000; i++);
}
