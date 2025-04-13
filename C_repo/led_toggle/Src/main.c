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

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

void delay(void);

int main(void)
{
    /* Loop forever */
	//To enable the peripheral clock
	uint32_t *pClkCtrlReg = (uint32_t*)0x40023830;
	//To select GPIOD mode register
	uint32_t *pPortMode = (uint32_t*)0x40020C00;
	//To enable GPIOD output data register
	uint32_t *pPortDOutReg = (uint32_t*)0x40020C14;

	//enable clk for PORTD
	*pClkCtrlReg |= (1<<3);

	//clear mode and set 24th bit
	*pPortMode &= ~(0XFF<<24); // this clear the mode of this port
	*pPortMode |= (0x55<<24); // in this step we set mode to GP output mode



	//set 12th bit to turn on led

	for(int i=0; i<10; i++)
	{
		//turn on led
		*pPortDOutReg |= (1<<12);
		delay();
		*pPortDOutReg &= ~(1<<12);
		delay();
		*pPortDOutReg |= (1<<13);
		delay();
		*pPortDOutReg &= ~(1<<13);
		delay();
		*pPortDOutReg |= (1<<14);
		delay();
		*pPortDOutReg &= ~(1<<14);
		delay();
		*pPortDOutReg |= (1<<15);
		delay();
		*pPortDOutReg &= ~(1<<15);
		delay();

	}



	for(;;);
}

void delay()
{
	for(int i=0; i<50000; i++);
}
