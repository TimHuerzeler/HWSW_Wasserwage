/**
 *****************************************************************************
 * @file        main.s
 * @brief       BTE 5053 HWSWE, Exercise U9A3.
 *
 * This program sorts an array using the bubble sort algorithm.
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

/************************************************************************
* Array of numbers
************************************************************************/
    .set size, 10                   @ number of array elements

    .data
    .align
array:  .word 0x55555555, 0x22222222, 0x99999999, 0x00000000, 0x11111111
        .word 0x33333333, 0x88888888, 0x77777777, 0x44444444, 0x66666666


/************************************************************************
* Code
************************************************************************/
    .text                           @ section text (executable code)

/**
 * @brief   Sort an array.
 *
 * This subroutine sorts an array of unsigned numbers, using bubble sort
 * there are no optimizations!
 *
 * @param   r0: array base address
 * @param   r1: array size
 * @return  none
 * @remark  The subroutine is using the following algorithm:
 *          for (r2 = (array_size - 1); r2 >= 0; r2--)
 *          {
 *              for (r3 = 1; r3 <= r2; r3++)
 *              {
 *                  if (numbers[r3-1] > numbers[r3])
 *                  {
 *                      temp = numbers[r3-1];
 *                      numbers[r3-1] = numbers[r3];
 *                      numbers[r3] = temp;
 *                  }
 *              }
 *          }
 * \remark  registers r4 to r6 used to swap numbers:
 *          r4: numbers[r3]
 *          r5: numbers[r3-1]
 *          r6: address offset in array
 */
sort_array:
    PUSH    {r4-r6,lr}
    # loop 1: for (r2 = (array_size - 1); r2 >= 0; r2--)
    MOV     r2,r1                   @ r2 = array_size - 1
    SUB     r2,r2,#1
sort_loop1:
    CMP     r2,#0                   @ check loop 1, r2 >= 0 ?
    BLT     sort_end                @ no, loop 1 end --> branch sort_end

    # loop 2: for (r3 = 1; r3 <= r2; r3++)
    MOV     r3,#1                   @ r3 = 1
sort_loop2:
    CMP     r3,r2                   @ r3 <= r2?
    BGT     sort_loop1_end          @ no, loop2 end --> branch sort_loop1_end
swap:
    MOV     r6,r3,LSL #2            @ address offset for index r3: r6 = r3*4
    LDR     r4,[r0,r6]              @ r4 = numbers[r3]
    SUB     r6,r6,#4                @ address offset for index (r3 - 1)
    LDR     r5,[r0,r6]              @ r5 = numbers[r3-1]
    CMP     r5,r4                   @ if (numbers[r3-1] > numbers[r3])
    BLS     sort_loop2_end          @ no --> don't swap
    STR     r4,[r0,r6]              @ numbers[r3-1] = lower value
    ADD     r6,r6,#4                @ prepare next address offset
    STR     r5,[r0,r6]              @ numbers[r3] = higher value

sort_loop2_end:
    ADD     r3,r3,#1                @ loop 2 end, prepare next loop, r3++
    B       sort_loop2              @ next loop 2

sort_loop1_end:
    SUB     r2,r2,#1                @ loop 1 end, prepare next loop, r2--
    B       sort_loop1              @ next loop 1
sort_end:
    POP {r4-r6,pc}

/**
 * @brief       main subroutine
 *
 * The main subroutine calls subroutine sort_array. Use the debugger
 * of STM32CubeIDE to check the values.
 *
 * @param       none
 * @return      none
 */
main:
/**
 * endless loop
 */
loop:
    LDR     r0,=array               @ r0 points to array base address
    MOV     r1,#size                @ r1 holds number of values in array
    BL      sort_array
    B       loop

.end
