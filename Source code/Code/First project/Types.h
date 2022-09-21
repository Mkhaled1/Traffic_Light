/*
 * Types.h
 *
 * Created: 9/6/2022 10:19:47 PM
 *  Author: Moataz
 */ 


#ifndef TYPES_H_
#define TYPES_H_


#define NULL 0 /** Define NULL in the program*/

/**Define the true Value*/
#define TRUE 0xAA  
//*Define the False value*/
#define FALSE 0x55 

/**
 * @brief Enum showing the state of the function
 * 
 */
typedef enum Status{
	Ok,
	Not_ok
	}Status;


typedef unsigned char uint8_t;
typedef unsigned int uint16_t;


#endif /* TYPES_H_ */