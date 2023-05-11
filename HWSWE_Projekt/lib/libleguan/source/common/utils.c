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
  *  @file fpu.c
  *  @ingroup common
  *  @author Nikolaij Saegesser
  *  @brief Utils
  */

#include "common/utils.h"

#include "common/processor.h"
#include "common/intrinsics.h"
#include "common/logger.h"

void LEGUAN_AssertImpl(bool condition, const char *conditionString, const char *message) {
	if(LEGUAN_UNLIKELY(!condition)) {
		LOG_Fatal("Assertion failed! %s ((%s) == false)", message, conditionString);
		while (true) { asm volatile("nop"); }
	}
}
