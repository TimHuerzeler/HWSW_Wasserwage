/**
 *****************************************************************************
 * @file        main.c
 * @brief       BTE 5053 HWSWE, C Template
 *
 * This is a template for C-Projects running on the Leguan board
 * and using STM32CubeIDE.
 *
 * @version     1.0
 * @date        2022-01-07
 * @author      ssn1, WBR1
 *
 * @remark      Last Modification
 *              \li wbr1 2022-01-07 created for BTE 5053
 *****************************************************************************
 */
#include <leguan.h>
#include <cube.h>

/**
 * @brief       main function
 *
 * This main function initialises the Leguan board. There is no additional
 * functionality in the main loop.
 *
 * @param       none
 * @return      always
 */

uint32_t copyData( uint8_t *dest , uint8_t *source , uint32_t size )
{
    uint32_t start_tick;        /* tick count when starting calculation */
    uint32_t end_tick;          /* tick count when calculation done */
    uint32_t time_loop;         /* measures time for loop only */

    /* measure time to do a loop NBR_LOOPS times */
    start_tick = HAL_GetTick();
    for (i=0; i<NBR_LOOPS; i++) {
        /* do nothing, just to get loop time */
    }
    end_tick = HAL_GetTick();
    time_loop = end_tick - start_tick;
}


int main(void)
{
    /* Initialize Hardware */
    CUBEMX_Init();
    /* Initialize Leguan board */
    LEGUAN_Init();

    /* Set logging output destination to be the LCD */
    LOG_SetDestination(LCD_Stream);

    /* Main loop */
    for (;;) {
    	/* enable instruction and data cache */
    	SCB_EnableICache();
    	SCB_EnableDCache();
    	/* copy data and start measuring time */
    	copyData();
    	/* disable instruction and data cache */
    	SCB_DisableICache();
    	SCB_DisableDCache();
    }

    return (0);
}
