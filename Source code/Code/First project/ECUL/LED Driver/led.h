/**
 * @file led.h
 * @author Moataz Khaled
 * @brief 
 * @version 0.1
 * @date 2022-09-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO Driver/dio.h"


#define CAR_LED_GREEN		PIN0
#define CAR_LED_YELLOW		PIN1
#define CAR_LED_RED			PIN2

#define PEDES_LED_GREEN		PIN0
#define PEDES_LED_YELLOW	PIN1
#define PEDES_LED_RED		PIN2

Status LED_Init(uint8_t ledPort, uint8_t ledPin);
Status LED_On(uint8_t ledPort, uint8_t ledPin);
Status LED_Off(uint8_t ledPort, uint8_t ledPin);
Status LED_toggle(uint8_t ledPort, uint8_t ledPin);




#endif /* LED_H_ */