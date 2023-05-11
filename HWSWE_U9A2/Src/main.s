/**
 *****************************************************************************
 * @file        main.s
 * @brief       BTE 5053 HWSWE, Exercise U9A2.
 *
 * This program calculates the lengt of a string, using different subroutines,
 * each of them with different optimizations.
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
str1:   .asciz  "ARM"
str2:   .asciz  "BFH-TI Biel-Burgdorf"
strzero:.asciz  ""

    .text                           @ section text (executable code)
    .align
/************************************************************************
* Code
************************************************************************/
/**
 * @brief   Calulate string length
 *
 * Reads each character of a string until end of string. Each
 * character increments the counter (r0, return value).
 *
 * @param   r0: String base address
 * @return  r0: string length
 * @remark  r1 used to point to actual char in string
 *          r2 holds actual char in string
 */
asm_strlen:
    MOV     r1,r0                   @ r1 points to actual char
    MOV     r0,#0                   @ r0 holds number of char in the string
while_strlen:
    LDRB    r2,[r1],#1              @ read actual char, increment string pointer
    CMP     r2,#0                   @ check if actual char is '\0' (stringend)
    BEQ     endwhile_strlen         @ branch if stringend
    ADD     r0,r0,#1                @ increment char counter
    BNE     while_strlen            @ --> next char
endwhile_strlen:
    MOV     pc,lr                   @ stringend, return

/**
 * @brief   Calulate string length
 *
 * Optimized version: strlen is initialized to -1
 *  and set to 0 with first ADD instruction.
 *
 * @param   r0: String base address
 * @return  r0: string length
 * @remark  r1 used to point to actual char in string
 *          r2 holds actual char in string
 */
asm_strlen2:
    MOV     r1,r0                   @ r1 points to actual char
    MOV     r0,#-1                  @ r0 holds number of char in the string
while_strlen2:
    ADD     r0,r0,#1                @ increment strlen
    LDRB    r2,[r1],#1              @ read actual char, increment string pointer
    CMP     r2,#0                   @ check if actual char is '\0' stringend
    BNE     while_strlen2           @ if not stringend, --> next char
endwhile_strlen2:
    MOV     pc,lr                   @ stringend, return


/**
 * @brief   Calulate string length
 *
 * Optimized version: Using adresses to calculate string length.
 *
 * @param   r0: String base address
 * @return  r0: string length
 * @remark  r1 used to point to actual address in string
 *          r2 holds actual char value
 */
asm_strlen3:
    MOV     r1,r0                   @ r1 points to actual char
while_strlen3:
    LDRB    r2,[r1],#1              @ read actual char, increment string pointer
    CMP     r2,#0                   @ check if actual char is '\0' stringend
    BNE     while_strlen3           @ if not stringend, --> next char
endwhile_strlen3:
    SUB     r0,r1,r0                @ number of char is difference of addresses
    SUB     r0,r0,#1                @ correct difference from postincrement of LDRB
    MOV     pc,lr                   @ stringend, return


/**
 * @brief       main subroutine
 *
 * The main subroutine calls each version of subroutine asm_strlen.
 * At the end, it tests if zero-strings are processed correctly.
 *
 * @param       none
 * @return      none
 */
main:
/**
 * endless loop
 */
loop:
    # calculate stringlength using different optimizations of asm_strlen
    LDR     r0,=str1                @ load r0 (parameter) with string base address
    BL      asm_strlen              @ call subroutine
    LDR     r0,=str2                @ load r0 (parameter) with string base address
    BL      asm_strlen2             @ call subroutine
    LDR     r0,=str2                @ load r0 (parameter) with string base address
    BL      asm_strlen3             @ call subroutine

    #test if zero-string runs correct
    LDR     r0,=strzero             @ load r0 (parameter) with string base address
    BL      asm_strlen              @ call subroutine
    LDR     r0,=strzero             @ load r0 (parameter) with string base address
    BL      asm_strlen2             @ call subroutine
    LDR     r0,=strzero             @ load r0 (parameter) with string base address
    BL      asm_strlen3             @ call subroutine

    B       loop

.end
