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
  *  @file errors.h
  *  @ingroup common
  *  @author Nikolaij Saegesser
  *  @brief Error definitions
  */

#pragma once

#if defined(__cplusplus)
extern "C" {
#endif


#include <stdint.h>

/* Types */
typedef enum {
    RESULT_SUCCESS						= 0,
 
    RESULT_INITIALIZATION_ERROR			= 1,
    RESULT_INVALID_ARGUMENTS			= 2,
	RESULT_OPERATION_FAILED				= 3,
 
    RESULT_ADC_MEASUREMENT_ERROR		= 100,
    RESULT_ADC_INVALID_VALUE			= 101,
 
    RESULT_IO_ERROR						= 200
} result_t;


/* Macros */
#define R_SUCCESS(x)						((x) == 0)
#define R_FAILURE(x)						((x) != 0)
#define R_TRY(x) 								\
	({ 											\
        const result_t _tmp_rtry_result = (x); 	\
        if (R_FAILURE(_tmp_rtry_result)) { 		\
            return _tmp_rtry_result; 			\
        } 										\
    })


#if defined(__cplusplus)
}
#endif
