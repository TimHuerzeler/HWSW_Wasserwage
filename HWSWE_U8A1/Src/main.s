/**
 *****************************************************************************
 * @file        main.s
 * @brief       BTE 5053 HWSWE, Exercise U8A1
 *
 * This program uses assembler directives to define sections and variables.
 *
 * @version     1.0
 * @date        2022-04-19
 * @author      WBR1
 *
 * @remark      Last Modification
 *              \li 2022-04-19 WBR1 created
 *
 *****************************************************************************
 */
    .syntax unified                 @ using unified language
    .cpu cortex-m7                  @ using Cortex-M7 CPU
    .thumb                          @ using thumb instruction set

/************************************************************************
# PUBLIC DECLARATIONS
# export also Variables and Constants for Mapfile
************************************************************************/
    .global main
    .global counter
    .global ytab
    .global value
    .global byteTab
    .global CTAB1
    .global CTAB2
    .global TEXT

/************************************************************************
#  8.1b) Uninitialized variables, section bss
************************************************************************/
    .bss
    .align
counter:    .space 4            @ Word
ytab:       .space 8*4          @ Array with 8 words
ytabend:


/************************************************************************
#  8.1c) Initialized variables, section data
************************************************************************/
    .data
    .align
value:      .word 0x4321

/************************************************************************
#  8.1d) Constants
************************************************************************/
    .text
    .align
CTAB1:  .word   0,1,2,3,4,5,6,7
CTAB2:  .byte   0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55
TEXT:   .asciz  "BFH-TI Biel-Burgdorf"

/************************************************************************
# Code
************************************************************************/
    .text
    .align
/**
 * @brief       main subroutine
 *
 * The main subroutine axesses different global variables.
 *
 * @param       none
 * @return      none
 */
main:
/**
 *  8.1e) endless loop
 */
loop:
/* Initialize variable counter with 0x12345678
    LDR     r0,=counter         @ load memory address
    LDR     r1,=0x12345678      @ value to write
    STR     r1,[r0]             @ store indirect */
    LDR		r4,=0x20001000

/* Initialize array ytab starting with 0, each value incremented by 1
    LDR     r0,=ytab            @ use a loop to process array
    MOV     r1,#0               @ value to write
L1: STR     r1,[r0],#4
    ADD     r1,r1,#1
    CMP     r1,#(ytabend-ytab)>>2  @ loopcounter: # words is (# adresses / 4)
    BNE     L1*/

/* Load variable value, multiply it with 33 and store it again
    LDR     r0,=value           @ load adress of variable value
    LDR     r1,[r0]             @ load value of variable
    MOV     r2,#33
    MUL     r1,r2,r1            @ multiply variable with 33
    STR     r1,[r0]             @ store value

    B       loop*/
	STMIA r4!,{r0, r3}
.end
