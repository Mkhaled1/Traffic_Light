/*
 * Registers.h
 *
 * Created: 9/6/2022 9:50:40 PM
 *  Author: Moataz
 */ 
/****************************************************************/
/* All MicroController Registers for ATMEGA32A
*/
/****************************************************************/



#ifndef REGISTERS_H_
#define REGISTERS_H_

//include
#include "Types.h"


//Definitions
/****************************************************************/
/* DIO Registers for ATMEGA32A
*/
/****************************************************************/

// PORTA register
#define PORTA (*(volatile uint8_t*) 0x3B)
#define DDRA (*(volatile uint8_t*)0x3A)
#define PINA (*(volatile uint8_t*) 0x39)

// PORTB register
#define PORTB (*(volatile uint8_t*) 0x38)
#define DDRB (*(volatile uint8_t*) 0x37)
#define PINB (*(volatile uint8_t*) 0x36)

// PORTC register
#define PORTC (*(volatile uint8_t*) 0x35)
#define DDRC (*(volatile uint8_t*)0x34)
#define PINC (*(volatile uint8_t*) 0x33)

// PORTD register
#define PORTD (*(volatile uint8_t*) 0x32)
#define DDRD (*(volatile uint8_t*) 0x31)
#define PIND (*(volatile uint8_t*) 0x30)

/****************************************************************/
/* Timer Registers for ATMEGA32A
*/
/****************************************************************/

//Timer 0 registers
#define TCCR0 (*(volatile uint8_t*) 0x53)
#define TCNT0 (*(volatile uint8_t*) 0x52)
#define OCR0 (*(volatile uint8_t*) 0x5C)

// Timer 2 registers
#define TCCR2 (*(volatile uint8_t*) 0x45)
#define TCNT2 (*(volatile uint8_t*) 0x44)
#define OCR2 (*(volatile uint8_t*) 0x43)


#define TIFR (*(volatile uint8_t*) 0x58)
/****************************************************************/
/* Status Register for ATMEGA32A
*/
/****************************************************************/

#define SREG (*(volatile uint8_t*) 0x5F)

/****************************************************************/
/* External Interrupt Registers for ATMEGA32A
*/
/****************************************************************/
#define MCUCR (*(volatile uint8_t*) 0x55)
#define MCUCSR (*(volatile uint8_t*) 0x54)
#define GICR (*(volatile uint8_t*) 0x5B)
#define GIFR (*(volatile uint8_t*) 0x5A)

#define ISC00   0
#define ISC01   1
#define INT0    6

/****************************************************************/
/* Definition of the bits of the registers
*/
/****************************************************************/

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

//function like macros for register and bit accessing
#define bitset(byte,nbit)   ((byte) |=  (1<<(nbit)))
#define bitclear(byte,nbit) ((byte) &= ~(1<<(nbit)))
#define bitflip(byte,nbit)  ((byte) ^=  (1<<(nbit)))
#define bitRead(byte,nbit) (((byte) &   (1<<(nbit))) >> nbit)


#endif /* REGISTERS_H_ */