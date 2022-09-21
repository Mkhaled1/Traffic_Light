/**
 * @file led.c
 * @author Moataz Khaled
 * @brief 
 * @version 0.1
 * @date 2022-09-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//includes
#include "led.h"

//Global variables

//function Definitions

//Initialize the pin in the port to provide input to an external LED connect
/**
 * @brief Initialize the LED PIN
 * @details Calls DIO_Init with specific port and pin with OUT direction
 * @param ledPort Port containing the PIN that will be set as output
 * @param ledPin PIN to be set as output
 * @see DIO_init()
 * @return Status NOT_OK if initialization failed, return OK otherwise 
 */
Status LED_Init(uint8_t ledPort, uint8_t ledPin){
	
	Status ret = Not_ok;
	
	//Initialize the pin as an input in the DIO driver
	ret = DIO_init(ledPin,ledPort, OUT);
	return ret;
}

//Turn the LED on
/**
 * @brief Turns LED on
 * @details Calls DIO_Write with specific port and pin to set the pin to high
 * @param ledPort Port containing the PIN that will be set to HIGH
 * @param ledPin PIN to be set as output
 * @see DIO_Write()
 * @return Status return if turning on the LED fails, return OK otherwise
 */
Status LED_On(uint8_t ledPort, uint8_t ledPin){
	
	Status ret = Not_ok;
	//raise the PIN connect to the LED to high in the DIO driver
	ret = DIO_Write(ledPin,ledPort, HIGH);
	return ret;
}

//Turn the LED Off
/**
 * @brief Turns LED Off
 * @details Calls DIO_Write with specific port and pin to set the pin to LOW
 * @param ledPort Port containing the PIN that will be set to low
 * @param ledPin PIN to be set as output
 * @see DIO_Write()
 * @return Status return if  turning off the LED fails, return OK otherwise
 */
Status LED_Off(uint8_t ledPort, uint8_t ledPin){
	
	Status ret = Not_ok;
	//put the PIN connect to the LED to low in the DIO driver
	DIO_Write(ledPin,ledPort, LOW);
	return ret;
}

//Toggle the LED status
/**
 * @brief Toggle the status of the LED
 * @details Calls DIO_Toggle with specific port and pin to flip the status of the pin
 * @param ledPort Port containing the PIN that will be flipped
 * @param ledPin PIN to be set as output
 * @see DIO_Toggle()
 * @return Status return if  toggling the LED fails, return OK otherwise
 */
Status LED_toggle(uint8_t ledPort, uint8_t ledPin){
	
	Status ret = Not_ok;
	//Toggle the PIN status connect to the LED 
	DIO_Toggle(ledPin,ledPort);
}