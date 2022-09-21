/*
 * Delay_Test.c
 *
 * Created: 9/13/2022 6:57:46 AM
 *  Author: Moataz
 */ 

#include "Delay_Test.h"

void TRAFF_DEL_001(){
	volatile Status ret;
	ret = delay_init_0(CTC,NO_OUTPUT);
}
void TRAFF_DEL_002(){
	Status ret;
	ret = delay_init_0(CTC,NO_OUTPUT);
	ret = delay_ms_0(1000);
}
void TRAFF_DEL_003(){
	Status ret;
	ret = delay_init_0(CTC,NO_OUTPUT);
	ret = delay_ms_0(3000);
}
void TRAFF_DEL_004(){
	volatile Status ret;
	ret = delay_init_0(CTC,NO_OUTPUT);
	ret = delay_ms_0(5000);	
}
