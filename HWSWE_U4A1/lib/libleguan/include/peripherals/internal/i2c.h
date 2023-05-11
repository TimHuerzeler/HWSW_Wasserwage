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
  *  @file i2c.h
  *  @ingroup peripherals
  *  @author Nikolaij Saegesser
  *  @brief I2C Abstraction
  */

#pragma once

#if defined(__cplusplus)
extern "C" {
#endif


/* Includes */
#include "common/types.h"
#include "common/attributes.h"
#include "common/mmio.h"
#include "common/processor.h"

/* Functions */

typedef struct {
	I2C_HandleTypeDef *handle;
} I2C_Handle_t;

/* Constants */

extern I2C_Handle_t I2C_Sensor;

#if defined(LEGUAN_FIRMWARE_CPU)
	extern I2C_Handle_t I2C_BoardConfig;
#endif

/**
 * @brief Initializes the I2C interface
 * @return Status result
 */
result_t I2C_Init(I2C_Handle_t handle);

/**
 * @brief Writes one byte to an I2C device
 * @param address Device address
 * @param data Data to write
 * @return Status result
 */
result_t I2C_Write(I2C_Handle_t handle, uint8_t address, uint8_t data);

/**
 * @brief Writes one byte into a register of an I2C device
 * @param address Device address
 * @param reg Register address
 * @param data Data to write
 * @return Status result
 */
result_t I2C_WriteRegister(I2C_Handle_t handle, uint8_t address, uint8_t reg, uint8_t data);

/**
 * @brief Writes a full buffer to an I2C device
 * @param address Device address
 * @param buffer Buffer to send to device
 * @param size Size of buffer
 * @return Status result
 */
result_t I2C_WriteBuffer(I2C_Handle_t handle, uint8_t address, uint8_t *buffer, size_t size);

/**
 * @brief Writes a full buffer to an I2C register
 * @param address Device address
 * @param reg Register address
 * @param buffer Buffer to send
 * @param size Size of buffer
 * @return Status result
 */
result_t I2C_WriteRegisterBuffer(I2C_Handle_t handle, uint8_t address, uint8_t reg, uint8_t *buffer, size_t size);

/**
 * @brief Reads one byte from an I2C device
 * @param address Device address
 * @param data Pointer to where read byte should be written to
 * @return Status result
 */
result_t I2C_Read(I2C_Handle_t handle, uint8_t address, uint8_t *data);

/**
 * @brief Reads a full buffer from an I2C device
 * @param address Device address
 * @param buffer Buffer to store read data in
 * @param size Size of buffer
 * @return Status result
 */
result_t I2C_ReadBuffer(I2C_Handle_t handle, uint8_t address, uint8_t *buffer, size_t size);

/**
 * @brief Reads one byte from a register of an I2C device
 * @param address Device address
 * @param reg Register address
 * @param data Pointer to where read byte should be written to
 * @return Status result
 */
result_t I2C_ReadRegister(I2C_Handle_t handle, uint8_t address, uint8_t reg, uint8_t *data);

/**
 * @brief Reads a full buffer from an I2C register
 * @param address Device address
 * @param reg Register address
 * @param buffer Buffer to store read data in
 * @param size Size of buffer
 * @return Status result
 */
result_t I2C_ReadRegisterBuffer(I2C_Handle_t handle, uint8_t address, uint8_t reg, uint8_t *buffer, size_t size);


#if defined(__cplusplus)
}
#endif
