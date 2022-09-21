/*
 * dio.h
 *
 * Created: 9/6/2022 10:36:59 PM
 *  Author: Moataz
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../Registers.h"
#include "../Interrupts.h"

//all internal driver typedefs
//all driver macros

#define Port_A 'A'
#define Port_B 'B'
#define Port_C 'C'
#define Port_D 'D'

//Pin Direction
#define IN 0 
#define OUT 1

//PIN Value
#define LOW 0
#define HIGH 1

//all driver function prototypes

Status DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction);

Status DIO_Write(uint8_t pinNumber, uint8_t portNumber, uint8_t value);
Status DIO_Toggle(uint8_t pinNumber, uint8_t portNumber);
Status DIO_Read(uint8_t pinNumber, uint8_t portNumber, uint8_t* value);



#endif /* DIO_H_ */