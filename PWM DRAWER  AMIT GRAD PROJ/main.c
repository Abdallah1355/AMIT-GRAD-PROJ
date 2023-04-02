/*
* PWM DRAWER  AMIT GRAD PROJ.c
*
* Created: 3/24/2023 2:18:36 PM
* Author : abdal
*/

#include <avr/io.h>
#include <stdlib.h>
#include "DIO.h"
#include "GLCD.h"
#include <string.h>
#include <stdio.h>



int main ( )
{
	unsigned int a,b,c,high,period;
	char frequency[14],duty_cy[7],PER[10];
	
	GLCD_Init();
	PORTD = 0xFF;
	
	while(1)
	{
		TCCR1A = 0;
		TCNT1=0;
		TIFR = (1<<ICF1);                  	/* Clear ICF (Input Capture flag) flag */
		
		TCCR1B = 0x41;  	                /* Rising edge, no prescaler */
		while ((TIFR&(1<<ICF1)) == 0);
		a = ICR1;  		                    /* Take value of capture register */
		TIFR = (1<<ICF1);                 	/* Clear ICF flag */
		
		TCCR1B = 0x01;  	                /* Falling edge, no prescaler */
		while ((TIFR&(1<<ICF1)) == 0);
		b = ICR1;  		                    /* Take value of capture register */
		TIFR = (1<<ICF1);  	                /* Clear ICF flag */
		
		TCCR1B = 0x41;  	                /* Rising edge, no prescaler */
		while ((TIFR&(1<<ICF1)) == 0);
		c = ICR1;  		                    /* Take value of capture register */
		TIFR = (1<<ICF1);  	                /* Clear ICF flag */
		
		TCCR1B = 0;  		                /* Stop the timer */
		
		if(a<b && b<c)  	               /* Check for valid condition,
		to avoid timer overflow reading */
		{
			high=b-a;
			period=c-a;
			
			u32 freq= F_CPU/period;            /* Calculate frequency */
			freq=freq/1000;
			
			/* Calculate duty cycle */
			f32 duty_cycle =((f32) high /(f32)period)*100;
			ltoa(freq,frequency,10);
			
			char fr[100]="Freq: ";
			char hz[5]=" KHZ";
			strcat(fr,frequency);
			strcat(fr,hz);
			
			itoa((int)duty_cycle,duty_cy,10);
			char du[100]="Duty: ";
			char perc[5]=" %";
			strcat(du,duty_cy);
			strcat(du,perc);
			
			f32 time =(1/(f32)freq);
			
			
			floatingpart(time);
			GLCD_String(0,fr);
			GLCD_String(2,du);
			
			
			char a [40];
			char arrow[10];
			
			/* printing time arrow*/
			strcat(arrow,"<-");
			
			for (u32 j=0;j<6;j++)
			{
				strcat(arrow,"-");	
			}
			strcat(arrow,"->");		
			GLCD_String(6,arrow);
	
				/* printing square wave */
			for (u32 i = 0;i<2;i++)
			{
				for (u32 j=0;j<(duty_cycle/10);j++)
				{
					strcat(a,"-");
				}
				for (u32 k=0;k<(10-(duty_cycle/10));k++)
				{
					strcat(a,"_");
				}
			}
			
			GLCD_String(7,a);
			
			
		}
		
		else
		{
			GLCD_ClearAll();
			GLCD_String(1,"OUT OF RANGE!!");
		}
		
		_delay_ms(100000);
		GLCD_ClearAll();
	}

}


