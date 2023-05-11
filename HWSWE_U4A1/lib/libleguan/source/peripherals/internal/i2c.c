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
  *  @file i2c.c
  *  @ingroup peripherals
  *  @author Nikolaij Saegesser
  *  @brief I2C implementations
  */

#include "peripherals/internal/i2c.h"
#include "common/processor.h"

#include <string.h>

#if defined(LEGUAN_FIRMWARE_CPU)
	extern I2C_HandleTypeDef hi2c1;
	extern I2C_HandleTypeDef hi2c2;

	I2C_Handle_t I2C_Sensor = { &hi2c1 };
	I2C_Handle_t I2C_BoardConfig = { &hi2c2 };
#else
	extern I2C_HandleTypeDef hi2c2;

	I2C_Handle_t I2C_Sensor = { &hi2c2 };
#endif

result_t I2C_Init(I2C_Handle_t handle) {
	/* Noting to do */

	return RESULT_SUCCESS;
}

result_t I2C_Write(I2C_Handle_t handle, uint8_t address, uint8_t data) {
	if (HAL_I2C_Master_Transmit(handle.handle, address << 1, &data, 1, HAL_MAX_DELAY) != HAL_OK)
		return RESULT_IO_ERROR;

	return RESULT_SUCCESS;
}

result_t I2C_WriteRegister(I2C_Handle_t handle, uint8_t address, uint8_t reg, uint8_t data) {
	uint8_t transmission[] = { reg, data };
	if (HAL_I2C_Master_Transmit(handle.handle, address << 1, transmission, 2, HAL_MAX_DELAY) != HAL_OK)
		return RESULT_IO_ERROR;

	return RESULT_SUCCESS;
}

result_t I2C_WriteBuffer(I2C_Handle_t handle, uint8_t address, uint8_t *buffer, size_t size) {
	if (HAL_I2C_Master_Transmit(handle.handle, address << 1, buffer, size, HAL_MAX_DELAY) != HAL_OK)
		return RESULT_IO_ERROR;

	return RESULT_SUCCESS;
}

result_t I2C_WriteRegisterBuffer(I2C_Handle_t handle, uint8_t address, uint8_t reg, uint8_t *buffer, size_t size) {
	if (buffer == NULL)
		return RESULT_INVALID_ARGUMENTS;

	uint8_t sendBuffer[size + 1];
	buffer[0] = reg;
	memcpy(&sendBuffer[1], buffer, size);

	if (I2C_WriteBuffer(handle, address, sendBuffer, size) != RESULT_SUCCESS)
		return RESULT_IO_ERROR;

	return RESULT_SUCCESS;
}

result_t I2C_Read(I2C_Handle_t handle, uint8_t address, uint8_t *value) {
	if (value == NULL)
		return RESULT_INVALID_ARGUMENTS;

	if (HAL_I2C_Master_Receive(handle.handle, address << 1, value, 1, HAL_MAX_DELAY) != HAL_OK)
		return RESULT_IO_ERROR;

	return RESULT_SUCCESS;
}

result_t I2C_ReadBuffer(I2C_Handle_t handle, uint8_t address, uint8_t *buffer, size_t size) {
	if (HAL_I2C_Master_Receive(handle.handle, address << 1, buffer, size, HAL_MAX_DELAY) != HAL_OK)
		return RESULT_IO_ERROR;

	return RESULT_SUCCESS;
}

result_t I2C_ReadRegister(I2C_Handle_t handle, uint8_t address, uint8_t reg, uint8_t *value) {
	if (value == NULL)
		return RESULT_INVALID_ARGUMENTS;

	if (HAL_I2C_Master_Transmit(handle.handle, address << 1, &reg, 1, HAL_MAX_DELAY) != HAL_OK)
		return RESULT_IO_ERROR;

	if (I2C_Read(handle, address, value) != RESULT_SUCCESS)
		return RESULT_IO_ERROR;

	return RESULT_SUCCESS;
}

result_t I2C_ReadRegisterBuffer(I2C_Handle_t handle, uint8_t address, uint8_t reg, uint8_t *buffer, size_t size) {
	if (buffer == NULL)
		return RESULT_INVALID_ARGUMENTS;

	if (HAL_I2C_Master_Transmit(handle.handle, address << 1, &reg, 1, HAL_MAX_DELAY) != HAL_OK)
		return RESULT_IO_ERROR;

	if (I2C_ReadBuffer(handle, address, buffer, size) != RESULT_SUCCESS)
		return RESULT_IO_ERROR;

	return RESULT_SUCCESS;
}
