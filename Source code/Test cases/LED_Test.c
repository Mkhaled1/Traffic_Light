/*
 * LED_Test.c
 
 *
 * Created: 9/13/2022 5:54:45 AM
 *  Author: Moataz
 */ 

#include "LED_Test.h"

void TRAFF_LED_001(){
	volatile Status ret;
	ret = LED_Init(Port_A,PIN0); 
}
void TRAFF_LED_002(){
	volatile Status ret;
	ret = LED_Init(Port_A,PIN8);
}
void TRAFF_LED_003(){
	volatile Status ret;
	ret = LED_Init(PORT_E,PIN0);
}
void TRAFF_LED_004(){
	volatile Status ret;
	ret = LED_Init(Port_A,PIN0);
	ret = LED_On(Port_A,PIN0);
}
void TRAFF_LED_005(){
	volatile Status ret;
	ret = LED_On(Port_A,PIN8);
}
void TRAFF_LED_006(){
	volatile Status ret;
	ret = LED_On(PORT_E,PIN0);
}
void TRAFF_LED_007(){
	volatile Status ret;
	ret = LED_Init(Port_A,PIN0);
	ret = LED_Off(Port_A,PIN0);	
}
void TRAFF_LED_008(){
	volatile Status ret;
	ret = LED_Off(Port_A,PIN8);	
}
void TRAFF_LED_009(){
	volatile Status ret;
	ret = LED_Off(PORT_E,PIN0);	
}
void TRAFF_LED_010(){
	volatile Status ret;
	ret = LED_Init(Port_A,PIN0);
	ret = LED_toggle(Port_A,PIN0);	
}
void TRAFF_LED_011(){
	volatile Status ret;
	ret = LED_toggle(Port_A,PIN8);	
}
void TRAFF_LED_012(){
	volatile Status ret;
	ret = LED_toggle(PORT_E,PIN0);	
}