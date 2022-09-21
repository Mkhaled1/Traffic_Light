/**
 * @file timer.c
 * @author Moataz Khaled
 * @brief 
 * @version 0.1
 * @date 2022-09-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "timer.h"
#include "../Interrupts.h"

/**
 * @brief Initialize the timer 0
 * @details Initialize the TCCR0 
 * set the Compare Match Output Mode
 * set the WGM01 and WGM00
 * @param mode determine which mode will be used for counting and overflow of the interrupt
 * @param comMode determine the compare match output mode
 * @return Status Ok for no error occurs, Not_Ok for error during intialization
 */
Status timer0_Init(Timer_Mode mode,COM_Mode comMode){
	
	//clear all bits
	TCCR0 = 0x00;

	//Setting the Compare Match Output Mode
	if(comMode <4)
	TCCR0 |= comMode<<4;
	else
	return Not_ok;
	//Setting the mode
	switch (mode){
		case Timer_Normal:
		bitclear(TCCR0,WGM01);
		bitclear(TCCR0,WGM00);
		break;
		
		case Phase_Correct:
		bitset(TCCR0,WGM00);
		bitclear(TCCR0,WGM01);		
		break;
		
		case CTC:
		bitclear(TCCR0,WGM00);
		bitset(TCCR0,WGM01);
		break;
		
		case Fast_PWM:
		bitset(TCCR0,WGM01);
		bitset(TCCR0,WGM00);
		break;
		default:
		return Not_ok;				 
	}
	return Ok;
}

/**
 * @brief Start the timer 0
 * @details set the OCR0 with the cmp value
 * set the prescalor in TCCR0
 * @param CmpValue the compare value at with the reset will occur
 * @param prescalor the value of the prescalor (in the project it prescalor 64 will be used)
 * @return Status returns ok after it starts the timer.
 */
Status timer0_start(uint8_t CmpValue,clk_source_T0 prescalor){
	
	if(prescalor > 7)
	return Not_ok;
	TCNT0 = 0x00;
	//Set the offset
	OCR0 = CmpValue;
	//setting the prescalor
	TCCR0 |= prescalor;
	return Ok;
}

/**
 * @brief stop the timer 0
 * @details Clear TCCR0 and OCR0 
 * @return Status returns ok after it stops the timer.
 */
Status timer0_stop(){
	TCCR0 = 0x00;
	OCR0 = 0x00;
	return Ok;
}

