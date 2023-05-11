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
  *  @file utils.h
  *  @ingroup common
  *  @author Nikolaij Saegesser
  *  @brief Utils
  */

#pragma once

#include <stdbool.h>

#if defined(__cplusplus)
extern "C" {
#endif

/**
 * @brief Asserts that a given condition is true
 * @param condition Condition to assert on
 * @param message Message to print
 */
#define LEGUAN_Assert(condition, message) LEGUAN_AssertImpl(condition, #condition, message)

/**
 * @brief Assert implementation. Use LEGUAN_Assert instead.
 * @param condition Condition to assert on
 * @param conditionString String version of condition
 * @param message Message to print
 */
void LEGUAN_AssertImpl(bool condition, const char *conditionString, const char *message);


#if defined(__cplusplus)
}
#endif
