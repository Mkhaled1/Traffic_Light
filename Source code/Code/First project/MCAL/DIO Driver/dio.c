/**
 * @file dio.c
 * @author Moataz Khaled
 * @brief 
 * @version 0.1
 * @date 2022-09-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//include .h
#include "dio.h"

//global variables

//function definitions
///Initialize the pin of the port with the required direction

/**
 * @brief initialize a pin in a certain port with the direction
 * 
 * @param pinNumber PIN that will be set 
 * @param portNumber Port containing the PIN that will be set 
 * @param direction (IN//OUT)
 * @return Status return Not_Ok if the passed port is not in range (A->D) or pin number > 7
 */
Status DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction){
	
	if(pinNumber > 7)
	return Not_ok;
	//Check which pin in which port needed to be initialized with the given direction
	switch (portNumber)
	{
		case Port_A:
			if(direction == IN)
			bitclear(DDRA,pinNumber);//input
			//DDRA &=~(1<<pinNumber); //input
			else if (direction == OUT)
			{
				bitset(DDRA,pinNumber);//output
				//DDRA |=(1<<pinNumber); 
			}
			else{
				return Not_ok;
			}
		break;
		
		case Port_B:
		if(direction == IN)
			bitclear(DDRB,pinNumber);//input
		//DDRB &=~(1<<pinNumber); //input
		else if (direction == OUT)
		{
			bitset(DDRB,pinNumber);//output
			//DDRB |=(1<<pinNumber); //output
		}
		else{
			//error handling
			return Not_ok;
		}
		break;
		
		case Port_C:
		if(direction == IN)
			bitclear(DDRC,pinNumber);//input
		//DDRC &=~(1<<pinNumber); //input
		else if (direction == OUT)
		{
			bitset(DDRC,pinNumber);//output
			//DDRC |=(1<<pinNumber); //output
		}
		else{
			//error handling
			return Not_ok;
		}
		break;
			
		case Port_D:
		if(direction == IN)
			bitclear(DDRD,pinNumber);//input
		//DDRD &=~(1<<pinNumber); //input
		else if (direction == OUT)
		{
			bitset(DDRC,pinNumber);//output
			//DDRD |=(1<<pinNumber); //output
		}
		else{
			//error handling
			return Not_ok;
		}
		break;
		default:
		return Not_ok;
	}
	return Ok;
}

//Write the Pin value in the port

/**
 * @brief write a value in the pin
 * 
 * @param pinNumber PIN that will be set 
 * @param portNumber Port containing the PIN that will be set 
 * @param value (HIGH/LOW)
 * @return Status return Not_Ok if the passed pin direction is in not set as output or pin number > 7, otherwise return Ok
 */
Status DIO_Write(uint8_t pinNumber, uint8_t portNumber, uint8_t value) {
	
	if(pinNumber > 7)
	return Not_ok;

	switch (portNumber)
	{
		case Port_A:
		//Check if the pin is set as output
		if (bitRead(DDRA,pinNumber) == 0 )
		return Not_ok;		
		
		if(value == LOW)
			bitclear(PORTA,pinNumber); //Write 0
		else if (value == HIGH)
		{
			bitset(PORTA,pinNumber); //output
		}
		else{
			//error handling
			return Not_ok;
		}
		break;
		
		case Port_B:
		//Check if the pin is set as output
		if (bitRead(DDRB,pinNumber) == 0 )
		return Not_ok;
		
		if(value == LOW)
		bitclear(PORTB,pinNumber); //Write 0
		else if (value == HIGH)
		{
			bitset(PORTB,pinNumber); //output
		}
		else{
			//error handling
			return Not_ok;
		}
		break;
		
		case Port_C:
		//Check if the pin is set as output
		if (bitRead(DDRC,pinNumber) == 0 )
		return Not_ok;
		
		if(value == LOW)
		bitclear(PORTC,pinNumber); //Write 0
		else if (value == HIGH)
		{
			bitset(PORTC,pinNumber); //output
		}
		else{
			//error handling
			return Not_ok;
		}
		break;
		
		case Port_D:
		//Check if the pin is set as output
		if (bitRead(DDRD,pinNumber) == 0 )
		return Not_ok;
		
		if(value == LOW)
			bitclear(PORTD,pinNumber); //Write 0
		else if (value == HIGH)
		{
			bitset(PORTD,pinNumber); //output
		}
		else{
			//error handling
			return Not_ok;
		}
		break;
		default:
		return Not_ok;

	}
	return Ok;
}

/**
 * @brief Toggle the value of the output pin
 * 
 * @param pinNumber PIN that will be toggled
 * @param portNumber Port containing the PIN that will be toggled 
 * @return Status return Not_Ok if the passed pin direction is in not set as output or pin number > 7, otherwise return Ok
 */
Status DIO_Toggle(uint8_t pinNumber, uint8_t portNumber){

	if(pinNumber > 7)
	return Not_ok;

	switch (portNumber)
	{
		case Port_A:
		//Check if the pin is set as output
		if (bitRead(DDRA,pinNumber) == 0 )
		return Not_ok;
		bitflip(PORTA,pinNumber);
		break;
		
		case Port_B:
		//Check if the pin is set as output
		if (bitRead(DDRB,pinNumber) == 0 )
		return Not_ok;
		
		bitflip(PORTB,pinNumber); //Toggle
		break;
		
		case Port_C:
		//Check if the pin is set as output
		if (bitRead(DDRC,pinNumber) == 0 )
		return Not_ok;
		bitflip(PORTC,pinNumber); //Toggle
		break;
		
		case Port_D:
		//Check if the pin is set as output
		if (bitRead(DDRD,pinNumber) == 0 )
		return Not_ok;
		bitflip(PORTD,pinNumber); //Toggle
		break;
		
		default:
		return Not_ok;
	}
}

/**
 * @brief Read the value of a certain PIN
 * 
 * @param pinNumber PIN that will be read
 * @param portNumber Port containing the PIN that will be read
 * @param value pointer holds the state of the PIN (HIGH or LOW)
 * @return Status return Not_Ok if the passed pin direction is in not set as input or pin number > 7, otherwise return Ok
 */
Status DIO_Read(uint8_t pinNumber, uint8_t portNumber, uint8_t* value){

	if(pinNumber > 7)
	return Not_ok;
		switch (portNumber)
		{
			case Port_A:
			//Check if the pin is set as output
			if (bitRead(DDRA,pinNumber) == 1 )
			return Not_ok;
			*value=bitRead(PORTA,pinNumber);//read the bit
			break;
			
			case Port_B:
			//Check if the pin is set as output
			if (bitRead(DDRB,pinNumber) == 1 )
			return Not_ok;
			*value=bitRead(PORTB,pinNumber);//read the bit
			break;
			
			case Port_C:
			//Check if the pin is set as output
			if (bitRead(DDRC,pinNumber) == 1 )
			return Not_ok;
			*value=bitRead(PORTC,pinNumber);//read the bit
			break;
			
			case Port_D:
			//Check if the pin is set as output
			if (bitRead(DDRC,pinNumber) == 1 )
			return Not_ok;
			*value=bitRead(PORTC,pinNumber); //read the bit
			break;
			default:
			return Not_ok;
		}
		return Ok;
}


