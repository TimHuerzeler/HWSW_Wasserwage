/**
 *****************************************************************************
 * @file		main.c
 * @brief		BTE 5053 HWSWE, Exercise U2A1 and A2
 *
 * This program measures the time to execute a floating point operation
 * (sqrt), once in software (library), once in hardware using the FPU.
 * As the leguan library is programmed to use FPU, this exercise uses an
 * additional library function my_sqrtf() defined in file mysqrtf.c that
 * calculates sqrtf without FPU.
 *
 * @version		1.0
 * @date		2022-02-01
 * @author		WBR1
 *
 * @remark      Last Modification
 *              \li wbr1 2022-02-01 created for BTE 5053
 *****************************************************************************
 */
#include <leguan.h>
#include <cube.h>

/* Defines */
/* number of loops to calculate sqrt, do not modify this value, ms will be ns
 * in measured time.
 */
#define NBR_LOOPS (1000000)


/* function my_sqrtf() calculates sqrtf as a library function without using FPU */
extern float my_sqrtf(float x);

/**
 * @brief		main function
 *
 * This main function calculates the sqrt, once using a software library, once
 * using the FPU, and displays the measured time.
 *
 * @param		none
 * @return		always 0
 */
__attribute__((optimize("0")))  /* Make sure the compiler doesn't optimize away the loops */

int main(void)
{
    uint32_t start_tick;        /* tick count when starting calculation */
    uint32_t end_tick;          /* tick count when calculation done */
    uint32_t time_loop;         /* measures time for loop only */
    char array[];
    float res;                  /* result of sqrt */
    float value = 25.0F;        /* operand for sprt() */
    uint32_t i;                 /* loop variable */

    /* Initialize Hardware */
    CUBEMX_Init();
    /* Initialize Leguan board */
    LEGUAN_Init();

    /* Set logging output destination to be the LCD */
    LOG_SetDestination(LCD_Stream);


    /* Main loop */
    for (;;) {
        /* measure time to do a loop NBR_LOOPS times */
        start_tick = HAL_GetTick();
        for (i=0; i<NBR_LOOPS; i++) {
            /* do nothing, just to get loop time */
        }
        end_tick = HAL_GetTick();
        time_loop = end_tick - start_tick;
        snprintf(text, "Time to do a loop in ns: %d", (unsigned int)time_loop);
        LCD_String(0, 100, text);

        /* measure sqrtf() using FPU and print result */
        /* put your code here */
        asm volatile("vsqrt.f32 %0, %1" : "=w" (res) : "w" (value));

        /* measure sqrtf() using library function and print result */
        start_tick = HAL_GetTick();
        for (i=0; i<NBR_LOOPS; i++){
        	res = my_sqrtf(value);
        	}
        end_tick = HAL_GetTick();
        time_lib = end_tick - start_tick - time_loop;
        snprintf(text, "Time with library function: %d", (unsigned int)time_lib);
        LCD_String(0, 100, text);
    }

    return (0);
}
