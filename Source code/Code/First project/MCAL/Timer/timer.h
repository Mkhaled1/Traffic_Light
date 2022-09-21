/*
 * timer1.h
 *
 * Created: 9/8/2022 9:41:41 PM
 *  Author: Moataz
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_


#include "../../Registers.h"


#define WGM01 PIN3
#define WGM00 PIN6

/// timer mode enum 
typedef enum Timer_Mode{
	Timer_Normal = 0,
	Phase_Correct,
	CTC,
	Fast_PWM
	}Timer_Mode;

/// Compare Match Output Mode
typedef enum COM_Mode{
	NO_OUTPUT =0,
	Toggle,//only applicable in CTC mode
	Clear,
	Set
	}COM_Mode;	

/// prescalor enum for timer 0
typedef enum clk_source_T0 {
	T0_No_Clk_Source =0,
	T0_No_prescalor,
	T0_Precalor_8,
	T0_Precalor_64,
	T0_Precalor_256,
	T0_Precalor_1024,
	T0_Ext_falling,
	T0_Ext_Rising
	}clk_source_T0;



Status timer0_Init(Timer_Mode mode,COM_Mode comMode);
Status timer0_start(uint8_t CmpValue,clk_source_T0 prescalor);
Status timer0_stop();




#endif /* TIMER1_H_ */