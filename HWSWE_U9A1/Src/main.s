/**
 *****************************************************************************
 * @file        main.s
 * @brief       BTE 5053 HWSWE, Exercise U9A1.
 *
 * This program defines two strings and a subroutine to calculate the number
 * of 'e' in a string.
 *
 * @version     1.0
 * @date        2022-04-26
 * @author      WBR1
 *
 * @remark      Last Modification
 *              \li 2022-04-26 WBR1 created
 *
 *****************************************************************************
 */
    .syntax unified                 @ using unified language
    .cpu cortex-m7                  @ using Cortex-M7 CPU
    .thumb                          @ using thumb instruction set

    .global main                    @ export main symbol, called in startup

    .data                           @ section data (initialized data)
str1:   .asciz  "Test"
str2:   .asciz  "Assembler is great"

    .text                           @ section text (executable code)
    .align
/************************************************************************
* Code
************************************************************************/
/**
 * @brief   Counts number of 'e' in a string
 *
 * Reads each character of a string until end of string. Compares each
 * character with 'e' and increments a counter (r0) for each 'e'.
 *
 * @param   r0: String base address
 * @return  r0: number of 'e' within the string
 * @remark  r1 used to point to actual char in string
 *          r2 holds actual char
 */
count_e:
    MOV     r1,r0                   @ r1 points to start character
    MOV     r0,#0                   @ r0 holds number of 'e'
count_loop:
    LDRB    r2,[r1],#1              @ load actual character, increment pointer r1
    CMP     r2,#0                   @ end of string?
    BEQ     count_end               @ yes --> end
    CMP     r2,#'e'                 @ check if character is 'e'
    BNE     count_loop              @ no --> next character
    ADD     r0,r0,#1                @ yes --> increment counter r0
    B       count_loop              @ next character
count_end:
    MOV     pc,lr                   @ return

/**
 * @brief       main subroutine
 *
 * The main subroutine calls subroutine count_e twice, each time with
 * a differnt string. The return value of count_e is not processed. Use
 * the debugger to check the values.
 *
 * @param       none
 * @return      none
 */
main:
/**
 * endless loop
 */
loop:
    LDR     r0,=str1                @ load r0 (parameter) with string base address
    BL      count_e                 @ call subroutine
    LDR     r0,=str2                @ load r0 (parameter) with string base address
    BL      count_e                 @ call subroutine
    B       loop

.end
