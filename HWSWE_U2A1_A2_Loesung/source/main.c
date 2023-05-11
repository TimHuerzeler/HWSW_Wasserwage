/**
 *****************************************************************************
 * @file        main.c
 * @brief       BTE 5053 HWSWE, Exercise U2A1 and A2
 *
 * This program measures the time to execute a floating point operation
 * (sqrt), once in software (library), once in hardware using the FPU.
 * As the leguan library is programmed to use FPU, this exercise uses an
 * additional library function my_sqrtf() defined in file mysqrtf.c that
 * calculates sqrtf without FPU.
 *
 * @version     1.0
 * @date        2022-02-01
 * @author      WBR1
 *
 * @remark      Last Modification
 *              \li wbr1 2022-02-01 created for BTE 5053
 *****************************************************************************
 */
#include <leguan.h>
#include <cube.h>
#include <stdio.h>              /* for snprintf */

/* Defines */
/* number of loops to calculate sqrt, do not modify this value, ms will be ns
 * in measured time.
 */
#define NBR_LOOPS (1000000)

/* defines for Display */
#define LINE_LENGTH         (60)
/* positions to draw text */
#define POS_WELCOME         (20)
#define POS_WITHFPU         (50)
#define POS_WITHLIB         (70)
/* text to display */
static const char *textWelcome = "Welcome to exercise U2A1 and U2A2";
static const char *textWithFPU = "Time to calculate with FPU: %u ns, result is %f";
static const char *textWithLib = "Time to calculate with library: %u ns, result is %f";

/* function my_sqrtf() calculates sqrtf as a library function without using FPU */
extern float my_sqrtf(float x);

/**
 * @brief       main function
 *
 * This main function calculates the sqrt, once using a software library, once
 * using the FPU, and displays the measured time.
 *
 * @param       none
 * @return      always 0
 */
__attribute__((optimize("0")))  /* Make sure the compiler doesn't optimize away the loops */

int main(void)
{
    uint32_t start_tick;        /* tick count when starting calculation */
    uint32_t end_tick;          /* tick count when calculation done */
    uint32_t time_fpu;          /* measures time for sqrtf function using FPU */
    uint32_t time_lib;          /* measures time for sqrtf function using library */
    uint32_t time_loop;         /* measures time for loop only */
    char text[LINE_LENGTH];     /* array to store text to display */
    register float res;         /* result of sqrt */
    register float value = 25.0F; /* operand for sprt() */
    register uint32_t i;        /* loop variable */

    /* Initialize Hardware */
    CUBEMX_Init();
    /* Initialize Leguan board */
    LEGUAN_Init();

    /* Set logging output destination to be the LCD */
    LOG_SetDestination(LCD_Stream);

    /* Define colors for display and display welcome */
    LCD_SetForegroundColor(ColorWhite);
    LCD_SetBackgroundColor(ColorBlack);
    LCD_String(0,POS_WELCOME, textWelcome);

    /* Main loop */
    for (;;) {
        /* measure time to do a loop NBR_LOOPS times */
        start_tick = HAL_GetTick();
        for (i=0; i<NBR_LOOPS; i++) {
            /* do nothing, just to get loop time */
        }
        end_tick = HAL_GetTick();
        time_loop = end_tick - start_tick;

        /* measure sqrtf() using FPU and print result */
        start_tick = HAL_GetTick();
        for (i=0; i<NBR_LOOPS; i++) {
            asm volatile("vsqrt.f32 %0, %1" : "=w" (res) : "w" (value));
        }
        end_tick = HAL_GetTick();
        time_fpu = end_tick - start_tick - time_loop;
        snprintf(text, LINE_LENGTH, textWithFPU, (unsigned int)time_fpu, res);
        LCD_String(0, POS_WITHFPU, text);

        /* measure sqrtf() using library function and print result */
        start_tick = HAL_GetTick();
        for (i=0; i<NBR_LOOPS; i++) {
            res = my_sqrtf(value);
        }
        end_tick = HAL_GetTick();
        time_lib = end_tick - start_tick - time_loop;
        snprintf(text, LINE_LENGTH, textWithLib, (unsigned int)time_lib, res);
        LCD_String(0, POS_WITHLIB, text);

    }

    return (0);
}
