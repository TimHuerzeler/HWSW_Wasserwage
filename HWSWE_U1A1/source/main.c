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
 * This main function initializes the Leguan board. There is no additional
 * functionality in the main loop.
 *
 * @param       none
 * @return      always 0
 */
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

    }

    return (0);
}
