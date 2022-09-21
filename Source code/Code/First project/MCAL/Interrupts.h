/*
 * Interrupts.h
 *
 * Created: 9/9/2022 12:34:52 AM
 *  Author: Moataz
 */ 



#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include "../Registers.h"

#define TIMER0_OVF  __vector_12
#define EXT_INT_0	__vector_1
#define EXT_INT_1	__vector_2
#define EXT_INT_2	__vector_3

/// Enable the interrupt in the status register
#define sei() __asm__ __volatile__("sei" ::: "memory")

/// clear the interrupt in the status register
#define cli() __asm__ __volatile__("cli" ::: "memory")

///Interrupt definition 
#define ISR(INT_VECT)void INT_VECT(void)  __attribute__((signal,used));\
void INT_VECT(void)



#endif /* INTERRUPTS_H_ */

