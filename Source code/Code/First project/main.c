/*****************************************************************//**
 * \file   main.c
 * \brief  the application main function and App_start function
 * 
 * \author Moataz
 * \date   September 2022
 *********************************************************************/


//#include <avr/io.h>
#include "ECUL/Button Driver/button.h"
#include "ECUL/LED Driver/led.h"
#include "Service/Delay/delay_ms.h"
#include "MCAL/Timer/timer.h"
#include "MCAL/Interrupts.h"
#include "App/app.h"
/*
#include "Test_Dio.h"
#include "timer0_test.h"
#include "LED_Test.h"

*/
///Clock frequency
#define F_CPU 1000000U // 1MHZ	frequency

//Global variables

///The state of the program
Mode currentMode = Normal;

///The variable holds the currently illuminated LED
LedMode current_carLed_Mode = Green;

///The variable holds the previously illuminated LED
LedMode previous_carLed_Mode = Green;

/// The flag which determine if the interrupt is fired or not
uint8_t Flag = FALSE;

///The variable shows which LED was illuminated when the interrupt was fired 
LedMode FirstState;

/// holds the status of the running application
Status App_state;

/**
 * @brief Program main function
 * @details Initializers the needed drivers for the application
 * calls the Appstart to start the application
 * @see	LED_Init() BUTTON_Init() delay_init_0() AppStart()
 * @return int 0 if the programs has no errors,
 */
int main(void)
{
	
	
	Status ret;
	
	
	ret=LED_Init(Port_A,CAR_LED_GREEN);
	ret=LED_Init(Port_A,CAR_LED_YELLOW);
	ret=LED_Init(Port_A,CAR_LED_RED);
	ret=LED_Init(Port_B,PEDES_LED_GREEN);
	ret=LED_Init(Port_B,PEDES_LED_YELLOW);
	ret=LED_Init(Port_B,PEDES_LED_RED);
	
	ret = BUTTON_Init(PORTD,PEDESTRIAN_BUTTON);
	
	ret=delay_init_0(CTC,NO_OUTPUT);
	
	sei();
	
	MCUCR |= (1<<0) | (1<<1);
	
	GICR  |= (1<<6);
	
	AppStart();
	
	return 0;

}

/**
 * @brief AppStart determine which mode the program is on and in return will detemine the illumination of the car and pedestrian LEDs accordingly
 * @details 
 */
void AppStart(){
	
    while (1){
		// initialize the variable holding the return variables from the called functions
		Status ret;
		//switch case to determine in which state the program is (Normal, Pedestrian)
		switch(currentMode){
			// In case of Normal mode the sequence will go as follows
			//car Green LED is on for 5 seconds == ==> car Yellow LED will toggle for 5 seconds ==> car Red LED will be on for 5 seconds
			//==> car Yellow LED will toggle for 5 seconds ==> car Green LED is on for 5 seconds 
			case Normal:
				switch(current_carLed_Mode)
				{
				case Green:
					//turn of all LEDs
					ret = LEDS_OFF();
					// Turn the CAR gree LED on 
					ret= LED_On(Port_A,CAR_LED_GREEN);
					// Delay for 5 seconds
					delay_ms_0(ON_DELAY);
					// Check if interrupt occur with in the delay
					//this determines in which carLed_Mode are we
					//in case no interrupt occurs the program will enter the pedestrian state without change the carLed_Mode
					if (Flag == TRUE){
					current_carLed_Mode = Green;
					}
					else {
					current_carLed_Mode = Yellow;
					//store the previous mode
					previous_carLed_Mode = Green;
					}
				break;
				// In case the program's carLed_Mode is in Yellow state, the yellow LED will toggle for 5 seconds
				case Yellow:
					LEDS_OFF();
					ret = Blink_CAR_YELLOW();
					if (Flag == TRUE){
						current_carLed_Mode = Yellow;
					}
					else {
						if(previous_carLed_Mode == Green)
							current_carLed_Mode = Red;
						else{
						current_carLed_Mode = Green;
						previous_carLed_Mode = Yellow;
						}
				break;
				// In case the program's carLed_Mode is in Red state, the Red LED will be on for 5 seconds
				case Red:
					LEDS_OFF();
					ret= LED_On(Port_A,CAR_LED_RED);
					delay_ms_0(ON_DELAY);
					
					if (Flag == TRUE){
						current_carLed_Mode = Red;
					}
					else {
					current_carLed_Mode = Yellow;
					previous_carLed_Mode = Red;
					}
				break;
				
				default:
					break;
				}	
			break;
			}
			break;
			
			
			// In case of Pedestrian mode the sequence depends when the interrupt occurs
			case Pedestrian:
			//setting the flag to true to remove the effect of the button while in pedestrain mode
				Flag = TRUE;
				
				switch(current_carLed_Mode)
				{
					// In case the current_carLed_Mode is Green it has to be checked if it is the first state in the pedestrian mode
					// If it is not the first state the occurs after the interrupt the current mode will return back to normal
					// current_carLed_Mode will be equal Yellow
					// previous_carLed_Mode will be equal Green
					case Green:
						LEDS_OFF();
						ret= LED_On(Port_A,CAR_LED_GREEN);
						ret= LED_On(Port_B,PEDES_LED_RED);
						delay_ms_0(ON_DELAY);
						if(FirstState == Green){
							current_carLed_Mode = Yellow;
							// set first state to NON to be able to return back to the normal mode
							FirstState = NON;
						}
						else {
							current_carLed_Mode = Yellow;
							currentMode = Normal;
							Flag = FALSE;
						}
						previous_carLed_Mode = Green;
					break;
					
					// In case the current_carLed_Mode is Yellow it has to be checked if it is the first state in the pedestrian mode
					// If it is not the first state the occurs after the interrupt the current mode will return back to normal
					// current_carLed_Mode will determined based on the previous_carLed_Mode
					// after that previous_carLed_Mode will be equal Yellow
					case Yellow:
						LEDS_OFF();
						if(FirstState == Yellow){
							current_carLed_Mode = Red;
							// set first state to NON to be able to return back to the normal mode
							FirstState = NON;
							ret= LED_Off(Port_B,PEDES_LED_RED);
						}
						else{
						if(previous_carLed_Mode == Green)
							current_carLed_Mode = Red;
						else
							current_carLed_Mode = Green;
						
						}
						ret= LED_Off(Port_B,PEDES_LED_RED);
						ret = Blink_Both_YELLOW();
						previous_carLed_Mode = Yellow;
					break;
					
					// In case the current_carLed_Mode is Red it has to be checked if it is the first state in the pedestrian mode
					// If it is not the first state the occurs after the interrupt the current mode will return back to normal
					// current_carLed_Mode will be equal Yellow
					// after that previous_carLed_Mode will be equal Red
					case Red:
						LEDS_OFF();
						ret= LED_On(Port_B,PEDES_LED_GREEN);
						ret= LED_On(Port_A,CAR_LED_RED);
						delay_ms_0(ON_DELAY);
						// set first state to NON to be able to return back to the normal mode
						if(FirstState == Red){
							FirstState == NON;
						}
						current_carLed_Mode = Yellow;
						previous_carLed_Mode = Red;
					break;
					
					default:
					break;
			}
		}
	}
}


/**
 * @brief 
 * 
 * @return Status 
 */
Status LEDS_OFF(){
	
	//Turn off all leds
	Status ret = Ok;
	ret = LED_Off(Port_B,PEDES_LED_GREEN);
	ret = LED_Off(Port_B,PEDES_LED_YELLOW);
	ret = LED_Off(Port_B,PEDES_LED_RED);
	ret = LED_Off(Port_A,CAR_LED_GREEN);
	ret = LED_Off(Port_A,CAR_LED_YELLOW);
	ret = LED_Off(Port_A,CAR_LED_RED);		
	return ret;
}

/**
 * @brief blink the car yellow LED for 5 seconds
 * @details calls LED toggle passing the car yellow LED parameters then delay 1 ms in a loop of 5 iterations
 * @return Status returns not ok if failure occurs during toggling or delay, otherwise return Ok
 */
Status Blink_CAR_YELLOW(){
	
	// Blink the car yellow LED
	//it is designed to blink within 5 seconds 
	Status ret = Ok;
	for(int i = 0; i< (ON_DELAY/TOGGLE_DELAY); i++){
		ret = LED_toggle(Port_A,CAR_LED_YELLOW);
		ret = delay_ms_0(TOGGLE_DELAY);
	}
	return ret;
}

/**
 * @brief blink the both  yellow LEDs for 5 seconds
 * @details calls LED toggle passing the car yellow LED parameters then delay 1 ms in a loop of 5 iterations
 * @return Status returns not ok if failure occurs during toggling or delay, otherwise return Ok
 */
Status Blink_Both_YELLOW(){
	
	// Blink the both yellow LEDs
	//it is designed to blink within 5 seconds
	Status ret = Ok;
	for(int i = 0; i< (ON_DELAY/TOGGLE_DELAY); i++){
		LED_toggle(Port_A,CAR_LED_YELLOW);
		LED_toggle(Port_B,PEDES_LED_YELLOW);
		delay_ms_0(TOGGLE_DELAY);
	}
	return ret;
}

/**
 * @brief ISR will shift the state from Normal to Pedestrian Upon button press
 * @details the ISR will be fired with the button is pressed
 */
ISR(EXT_INT_0){
	
	// Check if the flag is false which means that we are not in a pedestrian mode and a press on the button is acceptable
	if(Flag == FALSE){
		Flag = TRUE;
		//FirstState will hold the value of the current_carLed_Mode as it is the state when the interrupt occurs
		FirstState = current_carLed_Mode;
		// switch the current mode to pedestrian
		currentMode =Pedestrian;
		
		//according to which car led state was active the leds (Red or Green) for the pedestrians will be on
		switch(current_carLed_Mode)
		{
			case Green:
				LED_On(Port_B,PEDES_LED_RED);
				current_carLed_Mode =Green;
			break;
			case Yellow:
				LED_On(Port_B,PEDES_LED_RED);
				current_carLed_Mode =Yellow;
			break;
			case Red:
				LED_On(Port_B,PEDES_LED_GREEN);
				current_carLed_Mode =Green;
		}
	}
}
