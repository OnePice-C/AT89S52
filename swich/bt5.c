#include <AT89x52.h>
#include <stdio.h>
#include <math.h>

#define sw0 P1_0
#define sw1 P1_1
#define sw2 P1_2
#define sw3 P1_3
#define sw4 P1_4
#define sw5 P1_5
#define sw6 P1_6
#define sw7 P1_7

#define d0 P2_0
#define d1 P2_1
#define d2 P2_2
#define d3 P2_3
#define d4 P2_4
#define d5 P2_5
#define d6 P2_6
#define d7 P2_7


unsigned delay(unsigned int time)
{
	int i;
	for(i=0;i<time;i++);
}

void main(void)
{
	int i;
	P2=0xFF;
	P1=0xFF;
	if(sw0)
	
	 	for(i=0;i<2;i++)
		{
			d0=~d0;
			delay(100000);
		}
	
     if(sw1)
	
	 	for(i=0;i<4;i++)
		{
	     	d1=~d1;
			delay(100000);
		}
	
	if(sw2)
	
	 	for(i=0;i<6;i++)
		{
			d2=~d2;
			delay(100000);
		}
	
	if(sw3)
	
	 	for(i=0;i<8;i++)
		{
			d3=~d3;
			delay(100000);
		}
	
	if(sw4)
	
	 	for(i=0;i<10;i++)
		{
			d4=~d4;
			delay(100000);
		}
	
	if(sw5)
	
	 	for(i=0;i<12;i++)
		{
			d5=~d5;
			delay(100000);
		}
	
	if(sw6)
	
	 	for(i=0;i<14;i++)
		{
			d6=~d6;
			delay(100000);
		}

	if(sw7)
	
	 	for(i=0;i<16;i++)
		{
			d7=~d7;
			delay(100000);
		}
	
}
