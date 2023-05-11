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
  *  @file serial.c
  *  @ingroup peripherals
  *  @author Nikolaij Saegesser
  *  @brief Serial implementations
  */

#include "peripherals/internal/itm.h"
#include "common/processor.h"
#include "common/core.h"

#include <string.h>

result_t ITM_Init(void){
	/* Noting to do */

	return RESULT_SUCCESS;
}


void ITM_Stream(const char *string, bool new_line) {
	ITM_Send(string);

	if (new_line)
		ITM_Send("\r\n");
}

result_t ITM_Receive(char *buffer, size_t size) {
	if (buffer == NULL || size == 0)
		return RESULT_IO_ERROR;

	for (uint32_t offset = 0; offset < size; ) {
		if (!ITM_IsBufferEmpty()) {
			buffer[offset] = ITM_ReceiveChar();
		} else {
			CORE_Delay(1);
		}
	}

	return RESULT_SUCCESS;
}

result_t ITM_Send(const char *string) {
	if (string == NULL)
		return RESULT_IO_ERROR;

	while (*string != '\x00') {
		ITM_SendChar(*string);
		string++;
	}

	return RESULT_SUCCESS;
}

bool ITM_IsBufferEmpty() {
	return ITM_CheckChar() == 0;
}
