/*
 * GLCD.h
 *
 * Created: 3/26/2023 9:03:03 PM
 *  Author: abdal
 */ 


#ifndef GLCD_H_
#define GLCD_H_

#include "clock.h"
#include "DIO.h"
#include "Std_Types.h"
#include "BitMath.h"
#include <avr/io.h>					/* Include AVR std. library file */
#include <util/delay.h>				/* Include defined delay header file */
#include <stdio.h>					/* Include standard i/o library file */


#define Data_Port			PORTA	/* Define data port for GLCD */
#define Command_Port		PORTB	/* Define command port for GLCD */
#define Data_Port_Dir		DDRA	/* Define data port for GLCD */
#define Command_Port_Dir	DDRB	/* Define command port for GLCD */

#define RS					PB2		/* Define control pins */
#define RW					PB1
#define EN					PB0
#define CS1					PB4
#define CS2					PB5
#define RST					PB6

#define TotalPage			8
#define SCREEN_WIDTH		128
#define SCREEN_HEIGHT	    64


void GLCD_Command(char Command);
void GLCD_Data(char Data);
void GLCD_Init();
void GLCD_ClearAll();
void GLCD_String(char page_no, char *str);
void floatingpart(f32 data);




#endif /* GLCD_H_ */