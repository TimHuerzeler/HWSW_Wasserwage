/**
 *****************************************************************************
 * @file        main.s
 * @brief       BTE 5053 HWSWE, Condition Code Flags demonstration
 *
 * Description  :
 * The N, Z, C and V bits in the APSR register are collectively known as
 * the condition code flags. After the instruction has been executed,
 * the flags usually mean the following:
 * N is set to bit 31 of the result of the instruction. If the result is
 *   regarded as a two's complement signed integer, then N = 1 if the
 *   result is negative and N = 0 if the result is positive or zero.
 * Z is set to 1 if the result of the instruction is zero and set to 0
 *   otherwise.
 * C is set in the following ways:
 *   -   For an addition, including the comparison instruction CMN, C is
 *       set to 1 if the addition produced a carry (an unsigned overflow),
 *       and to 0 otherwise.
 *   -   For a subtraction, including the comparison instruction CMP, C is
 *       set to 0 if the subtraction produced a barrow (an unsigned
 *       underflow), and to 1 otherwise.
 *   -   For non-addition/subtractions that incorporate a shift operation,
 *       C is set to the last bit shifted out of the value by the shifter.
 *   -   For other non-addition/subtractions, C is normally left unchanged
 *       (see individual instruction description).
 * V is set in the following ways:
 *   -   For an addition or subtraction, V is set to 1 if signed overflow
 *       occurred.
 *   -   For non-addition/subtractions, V is normally left unchanged
 *       (see individual instruction description).
 *
 * Notation in the example below:
 * "Z" means Z flag is set
 * "z" means Z flag is cleared
 *
 * @version     1.0
 * @date        2022-03-14
 * @author      WBR1
 *
 * @remark      Last Modification
 *              \li 2022-03-14 WBR1 created
 *
 *****************************************************************************
 */
    .syntax unified                 @ using unified language
    .cpu cortex-m7                  @ using Cortex-M7 CPU
    .thumb                          @ using thumb instruction set

    .global main                    @ export main symbol, called in startup

    .text                           @ section text (executable code)

/**
 * @brief       main subroutine
 *
 * This code is pretty simple, it modifies register r0 in an endless loop.
 * Feel free to modify this code.
 *
 * @param       none
 * @return      none
 */
main:
    MOV     r0,#0               @ clear r0

/**
 * endless loop
 */
loop:
/*  instruction                 result after executing the instruction */
    MOV     r0,#2               @ r0 = 0x00000002
    SUBS    r0,#1               @ r0 = 0x00000001, flags set to: 00100
    SUBS    r0,#1               @ r0 = 0x00000000, flags set to: 01100
    SUBS    r0,#1               @ r0 = 0xFFFFFFFF, flags set to: 10000
    SUBS    r0,#1               @ r0 = 0xFFFFFFFE, flags set to: 10100
    ADDS    r0,#1               @ r0 = 0xFFFFFFFF, flags set to: 10000
    ADDS    r0,#1               @ r0 = 0x00000000, flags set to: 01100
    ADDS    r0,#1               @ r0 = 0x00000001, flags set to: 00000

    LDR     r1,=0x20000000      @ load r1 with address 0x20000000 (int. SRAM)
    LDR     r0,=0x12345678      @ load r0 with value 0x12345678
    STR     r0,[r1]             @ store value of r0 in address pointed to by r1
    B       loop

.end
