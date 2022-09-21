/**
 * @file button.c
 * @author Moataz Khaled
 * @brief button Driver that intialize and operates the DIO Pins as inputs connected to buttons
 * @version 0.1
 * @date 2022-09-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*include .h*/
#include "button.h"



/*Global Variables*/


/*Function implementation*/

/**
 * @brief Initialize DIO PIN as input
 * @details calls the DIO_init passing the dirction value as IN to set provided pin in the port as input
 * @param buttonPort contains in which port the pin will be intialized as an input
 * @param buttonPin contains which pin will be intialized as an input
 * @return Status returns Not_Ok if the intiailization fails, ekse returns Ok.
 */
Status BUTTON_Init(uint8_t buttonPort, uint8_t buttonPin){
	
	//Initialize the return value
	Status ret = Not_ok;
	//calls the DIO to initialize the pin as an input
	
	ret = DIO_init(buttonPin, buttonPort, IN);
	return ret;
}

/**
 * @brief Reads the input comming from the button connected to the microcontroller pin
 * @details calls the DIO passing the pointer value to get the status of the PIN
 * @param buttonPort port to be accessed (PORTA, PORTB, PORTC, PORTD)
 * @param buttonPin Pin to be accessed
 * @param value pointer that holds the state of the pin (high or low)
 * @return Status 
 */
Status BUTTON_read(uint8_t buttonPort, uint8_t buttonPin, volatile uint8_t *value){
	
	
	Status ret = Not_ok;
	//check if the value pointer points to NULL
	if(value == NULL)
	ret = Not_ok;
	
	
	//calls the DIO to read the value on the addressed pin
	ret = DIO_Read(buttonPin, buttonPort,value);
	

	
	return ret;
}