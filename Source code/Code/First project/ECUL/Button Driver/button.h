/**
 * @file button.h
 * @author Moataz Khaled
 * @brief button Driver that intialize and operates the DIO Pins as inputs connected to buttons
 * @version 0.1
 * @date 2022-09-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#ifndef BUTTON_H_
#define BUTTON_H_

//includes
#include "../../MCAL/DIO Driver/dio.h"

//Defines

/// Definition of the Pedestrian button to be PIN2 in PORTB
#define PEDESTRIAN_BUTTON   PIN2


//function prototypes
Status BUTTON_Init(uint8_t buttonPort, uint8_t buttonPin);
Status BUTTON_read(uint8_t buttonPort, uint8_t buttonPin, volatile uint8_t *value);


#endif /* INCFILE1_H_ */