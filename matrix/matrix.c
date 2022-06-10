#include <AT89x52.h>
#include <stdio.h>
#include <math.h>

#define H1 P1_0
#define H2 P1_1
#define H3 P1_2
#define H4 P1_3

#define C1 P1_7
#define C2 P1_6
#define C3 P1_5
#define C4 P1_4

unsigned char key;
unsigned char code_hang[8]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80}; // check cot

unsigned char code_cot[100]=
{
	0xC3,0x81,0x3C,0x3C,0x3C,0x3C,0x81,0x3C,  //A 
	0xFF,0xE1,0xDD,0xDD,0xC1,0xBD,0xBD,0xC1,  //B  
	0xFF,0xC3,0xBD,0xFD,0xFD,0xFD,0xBD,0xC3,  //C 
	0xFF,0xC1,0xBD,0xBD,0xBD,0xBD,0xBD,0xC1,  //D 
    0xFF,0xC1,0xFD,0xFD,0xE1,0xFD,0xFD,0x81,  //E 

};
void KT(void)
{							  
	  H1=0; H2=H3=H4=1;
	  if(!C1) key=1;
	  if(!C2) key=2;
	  if(!C3) key=3;
	  if(!C3) key=10;

	  H1=H3=H4=1; H2=0;
	  if(!C1) key=4;
	  if(!C2) key=5;
	  if(!C3) key=6;
	  if(!C3) key=11;

	  H3=0; H2=H1=H4=1;
	  if(!C1) key=7;
	  if(!C2) key=8;
	  if(!C3) key=9;
	  if(!C3) key=12;

	  H4=0; H2=H3=H1=1;
	  if(!C1) key='*';
	  if(!C2) key=0;
	  if(!C3) key='#';
	  if(!C3) key=13;
}
void delay(int time)
{
	int i;
	for(i=0;i<time;i++);
}

void main(void)
{
	int i,j;
	P1=0x00;
	while(1)
	{
	    KT();
		if(key==1)
		{
			for(i=0;i<200;i++)
			{
				for(j=0;j<8;j++)
				{
					P2=code_hang[j];
					P3=code_cot[j];
					delay(100);	
				}
			}	
		}
	}

}
