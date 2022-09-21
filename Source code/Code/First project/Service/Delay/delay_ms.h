/*
 * delay.h
 *
 * Created: 9/10/2022 10:30:37 PM
 *  Author: Moataz
 */ 


#ifndef DELAY_H_
#define DELAY_H_


//includes
#include "../../MCAL/Timer/timer.h"

//Definitions

//Functions prototype
Status delay_init_0(Timer_Mode mode,COM_Mode comMode);



Status delay_ms_0(uint16_t delay_ms);


Status Stop_delay();

#endif /* DELAY_H_ */