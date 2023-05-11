/**
 *****************************************************************************
 * @file        Accelerationcalc ASM.s
 * @brief       BTE 5053 HWSWE Mini Project, Assembler programm Accelerationcalc ASM
 *
 * This is Programm is part of the Mini C-Project running on the Leguan board
 * and using STM32CubeIDE.
 *
 * @version     1.0
 * @date        2022-05-01
 * @author      Tim Hürzeler
 * 				Nicolas Reust
 * 				Sacha Widr
 *
 *****************************************************************************
 */

.syntax unified
.cpu cortex-m4
.fpu softvfp
.thumb

/* give symbols external linkage */
    .global Accelerationcalc



/*
 **********************************************************************
 * Code
 ***********************************************************************
 */
    .text
 /**
 * @brief multiplies two values
 *
 * This  assembler subroutine implements the following C-statements:
 *
 *   return (acceleration*g);
 * }
 *
 * @param   r0: acceleration
 * @param   r1: g (=9.81)
 */


Accelerationcalc:
	MUL r0, r0, r1
	MOV     pc, lr                  @ return



