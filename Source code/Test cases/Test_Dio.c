/**
 * @file Test_Dio.c
 * @author Moataz Khaled
 * @brief file contain the tests for DIO Driver
 * @version 0.1
 * @date 2022-09-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "Test_Dio.h"
#include "MCAL/DIO Driver/dio.h"
#include <stdio.h>
#include <assert.h>

void TRAFF_DIO_001(){
	
	volatile Status ret;
	ret = DIO_init(PIN0,Port_A,IN);
}

void TRAFF_DIO_002(){
	Status ret;
	ret = DIO_init(PIN1,Port_B,IN);	
}

void TRAFF_DIO_003(){
	Status ret;
	ret = DIO_init(PIN2,Port_C,IN);	
}

void TRAFF_DIO_004(){
	Status ret;
	ret = DIO_init(PIN3,Port_D,IN);
}

void TRAFF_DIO_005(){
	Status ret;
	ret = DIO_init(PIN4,Port_A,OUT);	
}

void TRAFF_DIO_006(){
	Status ret;
	ret = DIO_init(PIN5,Port_B,OUT);
}

void TRAFF_DIO_007(){
	Status ret;
	ret = DIO_init(PIN6,Port_C,IN);	
}

void TRAFF_DIO_008(){
	Status ret;
	ret = DIO_init(PIN7,Port_D,OUT);	
}

void TRAFF_DIO_009(){
	Status ret;
	ret = DIO_init(8,Port_A,IN);	
}

void TRAFF_DIO_010(){
	Status ret;
	ret = DIO_init(10,Port_B,OUT);
}

void TRAFF_DIO_011(){
	Status ret;
	ret = DIO_init(PIN7,PORT_E,OUT);
}

void TRAFF_DIO_012(){
	Status ret;
	ret = DIO_init(PIN0,Port_A,OUT);
	ret = DIO_Write(PIN0,Port_A,HIGH);
}
void TRAFF_DIO_013(){
	Status ret;
	ret = DIO_init(PIN1,Port_B,OUT);
	ret = DIO_Write(PIN1,Port_B,LOW);	
}
void TRAFF_DIO_014(){
	Status ret;
	ret = DIO_init(PIN2,Port_C,OUT);
	ret = DIO_Write(PIN2,Port_C,HIGH);
}
void TRAFF_DIO_015(){
	Status ret;
	ret = DIO_init(PIN3,Port_D,OUT);
	ret = DIO_Write(PIN3,Port_D,LOW);	
}
void TRAFF_DIO_016(){
	Status ret;
	ret = DIO_init(PIN5,Port_A,IN);
	ret = DIO_Write(PIN5,Port_A,HIGH);
}
void TRAFF_DIO_017(){
	Status ret;
	ret = DIO_Write(8,Port_A,HIGH);	
}
void TRAFF_DIO_018(){
	Status ret;
	ret = DIO_Write(15,Port_B,HIGH);
}
void TRAFF_DIO_019(){
	Status ret;
	ret = DIO_Write(PIN3,PORT_E,HIGH);
}

void TRAFF_DIO_020(){
	Status ret;
	uint8_t *value;
	ret = DIO_init(PIN0,Port_A,IN);
	ret = DIO_Read(PIN0,Port_A,value);
}
void TRAFF_DIO_021(){
	Status ret;
	uint8_t *value;
	ret = DIO_init(PIN1,Port_B,IN);
	ret = DIO_Read(PIN1,Port_B,value);
}
void TRAFF_DIO_022(){
	Status ret;
	uint8_t *value;
	ret = DIO_init(PIN2,Port_C,IN);
	ret = DIO_Read(PIN2,Port_C,value);
}
void TRAFF_DIO_023(){
	Status ret;
	uint8_t *value;
	ret = DIO_init(PIN3,Port_D,IN);
	ret = DIO_Read(PIN3,Port_D,value);
}
void TRAFF_DIO_024(){
	Status ret;
	uint8_t *value;
	ret = DIO_init(PIN5,Port_A,OUT);
	ret = DIO_Read(PIN5,Port_A,value);
}
void TRAFF_DIO_025(){
	Status ret;
	uint8_t *value;
	ret = DIO_Read(8,Port_A,value);
}
void TRAFF_DIO_026(){
	Status ret;
	uint8_t *value;
	ret = DIO_Read(15,Port_B,value);
}
void TRAFF_DIO_027(){
	Status ret;
	uint8_t *value;
	ret = DIO_Read(PIN3,PORT_E,value);
}

void TRAFF_DIO_028(){
	Status ret;
	ret = DIO_init(PIN0,Port_A,OUT);
	ret = DIO_Toggle(PIN0,Port_A);
}
void TRAFF_DIO_029(){
	Status ret;
	ret = DIO_init(PIN1,Port_B,OUT);
	ret = DIO_Toggle(PIN1,Port_B);
}
void TRAFF_DIO_030(){
	Status ret;
	ret = DIO_init(PIN2,Port_C,OUT);
	ret = DIO_Toggle(PIN2,Port_C);
}
void TRAFF_DIO_031(){
	Status ret;
	ret = DIO_init(PIN3,Port_D,OUT);
	ret = DIO_Toggle(PIN3,Port_D);
}
void TRAFF_DIO_032(){
	Status ret;
	ret = DIO_init(PIN5,Port_A,IN);
	ret = DIO_Toggle(PIN5,Port_A);
}
void TRAFF_DIO_033(){
	Status ret;
	ret = DIO_Toggle(8,Port_A);
}
void TRAFF_DIO_034(){
	Status ret;
	ret = DIO_Toggle(15,Port_B);
}
void TRAFF_DIO_035(){
	Status ret;
	ret = DIO_Toggle(PIN3,PORT_E);
}