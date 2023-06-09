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
  *  @file adc.h
  *  @ingroup peripherals
  *  @author Nikolaij Saegesser
  *  @brief ADC Abstraction
  */

#pragma once

#if defined(__cplusplus)
extern "C" {
#endif


/* Includes */
#include "common/types.h"
#include "common/attributes.h"
#include "common/mmio.h"

/* Macros */
#define ADC_REFERENCE_VOLTAGE 3.3/*V*/

/* Types */
#if defined(LEGUAN_FIRMWARE_CPU)

	typedef enum {
		ADC1_6,
		ADC2_7
	} ADC_Input_t;

#else

	typedef enum {
		ADC1_14,
		ADC1_15,
		ADC1_16,
		ADC2_3,
		ADC3_8,
		Potentiometer
	} ADC_Input_t;

#endif


/* Functions */

/**
 * @brief Initializes the ADC Hardware
 * @return Status result
 */
result_t ADC_Init(void);

/**
 * @brief Starts conversion of one ADC input
 * @brief input ADC Input
 * @return Status result
 */
result_t ADC_StartMeasurement(ADC_Input_t input);

/**
 * @brief Checks if ADC conversion is done
 * @param input ADC Input
 * @return Done
 *
 */
bool ADC_IsReady(ADC_Input_t input);

/**
 * @brief Gets the current ADC value
 * @note Blocks if conversion is not done yet
 * @param input ADC Input
 * @param result Pointer where result in volts is written to
 * @return Status result
 */
result_t ADC_GetValue(ADC_Input_t input, float32_t *result);


#if defined(__cplusplus)
}
#endif
