/*****************************************************************//**
 * \file   app.h
 * \brief  Coniatins the needed definition of the macros, variables and functions used by the application
 * 
 * \author Moataz
 * \date   September 2022
 *********************************************************************/


#ifndef APP_H_
#define APP_H_

/**
 * @brief enum to hold in which mode the program is
 * 
 */
typedef enum Mode{
	/** The program is in Car normal mode*/
	Normal, 
	/** The program is in pedestrian mode*/
	Pedestrian 
	}Mode;

/**
 * @brief enum to hold in which led state the program is
 * 
 */
typedef enum  LedMode{
	/** The Green led is On*/
	Green,
	/**The yellow led is blinking*/ 
	Yellow, 
	/** The red led is on*/
	Red,
	/** Non of the LEDS are on*/ 
	NON 
	}LedMode;

///The delay time for the LEDs
#define ON_DELAY 5000
///The delay used for toggling of the yellow led
#define TOGGLE_DELAY 1000

//Function Prototypes
void AppStart();
Status LEDS_OFF();
Status Blink_CAR_YELLOW();
Status Blink_Both_YELLOW();
#endif /* APP_H_ */