/*
 * main.h
 *
 *  Created on: Apr 6, 2025
 *      Author: bhara
 */

#ifndef MAIN_H_
#define MAIN_H_

typedef struct
{
	uint32_t gpioa_en:1;
	uint32_t gpiob_en:1;
	uint32_t gpioc_en:1;
	uint32_t gpiod_en:1;
	uint32_t gpioe_en:1;
	uint32_t gpiof_en:1;
	uint32_t gpiog_en:1;
	uint32_t gpioh_en:1;
	uint32_t gpioi_en:1;
	uint32_t reserved0:3;
	uint32_t crc_en:1;
	uint32_t reserved1:5;
	uint32_t bkpsrame:1;
	uint32_t reserved2:1;
	uint32_t ccmdataram_en:1;
	uint32_t dma1_en:1;
	uint32_t dma2_en:1;
	uint32_t reserved3:2;
	uint32_t ethmac_en:1;
	uint32_t ethmac_tx_en:1;
	uint32_t ethmac_x_en:1;
	uint32_t ethmac_ptp_en:1;
	uint32_t otghs_en:1;
	uint32_t otghsulpi_en:1;
	uint32_t reserved4:1;
}RCC_AHB1ENR_t;

//GPIO Mode selector/enabler
typedef struct
{
	uint32_t mode_en0:2;
	uint32_t mode_en1:2;
	uint32_t mode_en2:2;
	uint32_t mode_en3:2;
	uint32_t mode_en4:2;
	uint32_t mode_en5:2;
	uint32_t mode_en6:2;
	uint32_t mode_en7:2;
	uint32_t mode_en8:2;
	uint32_t mode_en9:2;
	uint32_t mode_en10:2;
	uint32_t mode_en11:2;
	uint32_t mode_en12:2;
	uint32_t mode_en13:2;
	uint32_t mode_en14:2;
	uint32_t mode_en15:2;
	uint32_t reserved:16;

}GPIOx_MODER_t;

//GPIO output data register
typedef struct
{
	uint32_t odr0:1;
	uint32_t odr1:1;
	uint32_t odr2:1;
	uint32_t odr3:1;
	uint32_t odr4:1;
	uint32_t odr5:1;
	uint32_t odr6:1;
	uint32_t odr7:1;
	uint32_t odr8:1;
	uint32_t odr9:1;
	uint32_t odr10:1;
	uint32_t odr11:1;
	uint32_t odr12:1;
	uint32_t odr13:1;
	uint32_t odr14:1;
	uint32_t odr15:1;
}GPIOx_ODR;

#endif /* MAIN_H_ */
