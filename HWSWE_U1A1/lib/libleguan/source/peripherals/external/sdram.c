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
  *  @file sdram.c
  *  @ingroup peripherals
  *  @author Nikolaij Saegesser
  *  @brief SDRAM implementation
  */

#include "peripherals/external/sdram.h"
#include "common/processor.h"
#include "common/core.h"

#define SDRAM_MODEREG_BURST_LENGTH_1 0
#define SDRAM_MODEREG_BURST_LENGTH_2 1
#define SDRAM_MODEREG_BURST_LENGTH_4 2
#define SDRAM_MODEREG_BURST_LENGTH_8 3
#define SDRAM_MODEREG_BURST_LENGTH_FULL 7
#define SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL 0
#define SDRAM_MODEREG_BURST_TYPE_INTERLEAVED (1<<3)
#define SDRAM_MODEREG_CAS_LATENCY_2 (2 << 4)
#define SDRAM_MODEREG_CAS_LATENCY_3 (3 << 4)
#define SDRAM_MODEREG_OPERATING_MODE_STANDARD 0
#define SDRAM_MODEREG_WRITEBURST_MODE_PROGRAMMED 0
#define SDRAM_MODEREG_WRITEBURST_MODE_SINGLE (1<<9)

extern SDRAM_HandleTypeDef hsdram1;

result_t SDRAM_Init(void) {
	  FMC_SDRAM_CommandTypeDef command;

	  // Configure a clock configuration enable command
	  command.CommandMode            = FMC_SDRAM_CMD_CLK_ENABLE;
	  command.CommandTarget          = FMC_SDRAM_CMD_TARGET_BANK1;
	  command.AutoRefreshNumber      = 1;
	  command.ModeRegisterDefinition = 0;
	  if (HAL_SDRAM_SendCommand(&hsdram1, &command, 0x1000) != HAL_OK) return RESULT_INITIALIZATION_ERROR;

	  // Wait 100ms
	  CORE_Delay(100);

	  // Configure a PALL (precharge all) command
	  command.CommandMode            = FMC_SDRAM_CMD_PALL;
	  command.CommandTarget          = FMC_SDRAM_CMD_TARGET_BANK1;
	  command.AutoRefreshNumber      = 1;
	  command.ModeRegisterDefinition = 0;
	  if (HAL_SDRAM_SendCommand(&hsdram1, &command, 0x1000) != HAL_OK) return RESULT_INITIALIZATION_ERROR;

	  // Configure a Auto-Refresh command
	  command.CommandMode            = FMC_SDRAM_CMD_AUTOREFRESH_MODE;
	  command.CommandTarget          = FMC_SDRAM_CMD_TARGET_BANK1;
	  command.AutoRefreshNumber      = 4;
	  command.ModeRegisterDefinition = 0;
	  if (HAL_SDRAM_SendCommand(&hsdram1, &command, 0x1000) != HAL_OK) return RESULT_INITIALIZATION_ERROR;

	  // Program the external memory mode register
	  command.CommandMode            = FMC_SDRAM_CMD_LOAD_MODE;
	  command.CommandTarget          = FMC_SDRAM_CMD_TARGET_BANK1;
	  command.AutoRefreshNumber      = 1;
	  command.ModeRegisterDefinition = SDRAM_MODEREG_BURST_LENGTH_2          |
									   SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL   |
									   SDRAM_MODEREG_CAS_LATENCY_3           |
									   SDRAM_MODEREG_OPERATING_MODE_STANDARD |
									   SDRAM_MODEREG_WRITEBURST_MODE_SINGLE;;
	  if (HAL_SDRAM_SendCommand(&hsdram1, &command, 0x1000) != HAL_OK) return RESULT_INITIALIZATION_ERROR;

	  if (HAL_SDRAM_ProgramRefreshRate(&hsdram1, 0x56A - 20) != HAL_OK) return RESULT_INITIALIZATION_ERROR;

	  return RESULT_SUCCESS;
}
