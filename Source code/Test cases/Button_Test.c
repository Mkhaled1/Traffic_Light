/*
 * Button_Test.c
 *
 * Created: 9/13/2022 6:25:32 AM
 *  Author: Moataz
 */ 

#include "Button_Test..h"
void TRAFF_BUT_001(){
	volatile Status ret;
	ret = BUTTON_Init(Port_A,PIN0);
}
void TRAFF_BUT_002(){
	volatile Status ret;
	ret = BUTTON_Init(Port_A,PIN8);
}
void TRAFF_BUT_003(){
	volatile Status ret;
	ret = BUTTON_Init(PORT_E,PIN0);
}
void TRAFF_BUT_004(){
	volatile Status ret;
	volatile uint8_t *value;
	ret = BUTTON_Init(Port_A,PIN0);
	ret = BUTTON_read(Port_A,PIN0,value);
}
void TRAFF_BUT_005(){
	volatile Status ret;
	volatile uint8_t *value;
	ret = BUTTON_read(Port_A,PIN8,value);
}
void TRAFF_BUT_006(){
	volatile Status ret;
	volatile uint8_t *value;
	ret = BUTTON_read(PORT_E,PIN0,value);
}