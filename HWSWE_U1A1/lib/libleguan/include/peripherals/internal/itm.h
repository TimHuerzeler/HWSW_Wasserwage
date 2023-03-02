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
  *  @file itm.h
  *  @ingroup peripherals
  *  @author Nikolaij Saegesser
  *  @brief ITM Abstraction
  */

#pragma once

#if defined(__cplusplus)
extern "C" {
#endif


/* Includes */
#include "common/types.h"
#include "common/attributes.h"
#include "common/mmio.h"

/* Functions */

/**
 * @brief Initializes the ITM interface
 * @return Status result
 */
result_t ITM_Init();

/**
 * @brief ITM Stream function for use with the logger
 * @param string String to print
 * @param new_line Advance a line after printing
 * @return Status result
 */
void ITM_Stream(const char *string, bool new_line);

/**
 * @brief Sends a string over the JTAG/SWD interface through the ITM peripheral
 * @param string String to send
 * @return Status result
 */
result_t ITM_Send(const char *string);

/**
 * @brief Receives a string from the JTAG/SWD interface through the ITM peripheral
 * @param string Buffer to store string into
 * @param size Size of buffer
 * @return Status result
 */
result_t ITM_Receive(char *string, size_t size);

/**
 * @brief Checks if there's data available in the ITM buffer
 * @return True if buffer is empty, false if it's not
 */
bool ITM_IsBufferEmpty();

#if defined(__cplusplus)
}
#endif
