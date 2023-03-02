 /* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
  *          _                                                      *
  *         | |                                                     *
  *         | |     ___  __ _ _   _  __ _ _ __                      *
  *         | |    / _ \/ _` | | | |/ _` | '_ \                     *
  *         | |___|  __/ (_| | |_| | (_| | | | |                    *
  *         \_____/\___|\__, |\__,_|\__,_|_| |_|                    *
  *        ============= __/ | ==================                   *
  *                     |___/           BFH 2021                    *
  *                                                                 *
  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
  * This software can be used by students and other personal of the *
  * Bern University of Applied Sciences under the terms of the MIT  *
  * license.                                                        *
  * For other persons this software is under the terms of the GNU   *
  * General Public License version 2.                               *
  *                                                                 *
  * Copyright &copy; 2021, Bern University of Applied Sciences.     *
  * All rights reserved.                                            *
  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/**
  *  @file leguan.c
  *  @ingroup leguan
  *  @author Nikolaij Saegesser
  *  @brief Main leguan implementations
  */

#include "leguan.h"

result_t LEGUAN_Init(void) {
	FPGA_Init();
	LCD_Init();
	LCD_TouchInit();
	SENSOR_Init();
	SDRAM_Init();

	GPIO_Init();
	SERIAL_Init();
	SPI_Init(SPI_Sensor);
	SPI_Init(SPI_Touch);
	I2C_Init(I2C_Sensor);
	ITM_Init();
	ADC_Init();
	DAC_Init(DAC1_CH1);
	DAC_Init(DAC1_CH2);

#if defined (LEGUAN_FIRMWARE_CPU)
	I2C_Init(I2C_BoardConfig);
#endif

	return RESULT_SUCCESS;
}
