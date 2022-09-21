/**
 * @file delay_ms.c
 * @author Moataz Khaled
 * @brief Implements Delays to be used in the program using the Timer driver
 * @version 0.1
 * @date 2022-09-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*include .h*/
#include "delay_ms.h"

/*Global Variables*/

/*Function Implementation*/

/**
 * @brief Initialize timer 0 with the provided Timer mode and  compare match output mode
 * @details calls the timer0_Init() to initialize the timer with the provided Timer mode and compare match output mode
 * @param mode determine which mode will be used for counting and overflow of the interrupt
 * @param comMode determine the compare match output mode
 * @see timer0_Init()
 * @return Status Ok for no error occurs, Not_Ok for error during intialization
 */
Status delay_init_0(Timer_Mode mode,COM_Mode comMode){
	
	Status ret = Not_ok;
//Call the timer driver to set the mode and COM of timer 0	
	ret = timer0_Init(mode,comMode);
	return ret;
}




//The function performs a delay of the required time using timer 0
/**
 * @brief perform a delay with the required time passed in delay_ms
 * @details according to the presecalor used, the function will calculate the number of overflows and the OCR 
 * and performs a loop the timer 0 reach the OCR the exact number of overflows
 * @param delay_ms The amount of delay in milli second
 * @return Status Not_Ok if the component failed to perform the delay otherwise will return OK.
 */
Status delay_ms_0(volatile uint16_t delay_ms){
	
	
	Status ret = Not_ok;
	// initialize the prescalor, the choice was prescalor 64
	volatile clk_source_T0  prescalor = T0_Precalor_64;
	
	
	//calculate the number of overflows needed for the 
	uint16_t Num_Overflow = (uint16_t)((delay_ms/16.384)+1); 
	
	//calculate the compare time to be placed in OCR0
	volatile uint8_t compare_value = (uint8_t)((delay_ms/0.064)/Num_Overflow);
	
	//call timer0_start to start the timer with the required OCR and prescalor
	ret = timer0_start(compare_value,prescalor);
	
	if(ret == Not_ok )
		return ret;
	//Loop until the number of overflows are reached
	for(int i =0; i<Num_Overflow;i++){
		while((TIFR & (1<<1)) == 0);
		TIFR |= (1<<1);
		TIFR |= (1<<0);
	}
	// stop the timer
	ret = timer0_stop();
	return ret;
}


