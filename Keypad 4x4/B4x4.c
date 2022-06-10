#include <AT89x52.h>
#include <stdio.h>
#include <math.h>

unsigned char dl;
unsigned char key;
#define H1 P1_0
#define H2 P1_1
#define H3 P1_2
#define H4 P1_3

#define C1 P1_7
#define C2 P1_6
#define C3 P1_5
#define C4 P1_4

void delay(unsigned int time)
{
	int i;
	for(i=0;i<time;i++);
}
void BN(void)
{
	int i, dl=255;
		for(i=0;i<255;i++)
		{
		P2=dl;
		dl--;
		delay(20000);
		}
}

void NT (void)
{
		int i;
    	P2=0xFA;
		dl=0x00;
	
		{
		for(i=0;i<9;i++)
		{
			P2=dl;
			// tat dan tu 0.7 ->0.0 => 0x80
			//tat dan tu 0.0 -> 0.7 => 0x01
			dl=dl<<1 | 0x01;
			delay(20000);
		}
		for(i=0;i<9;i++)
		{
			P2=dl;
			//tuy y doi chieu huong sang lan.
			dl=dl>>1;
			delay(20000);
		}
		}
}

void KT (void)
{
	H1=0;H2=H3=H4=1;
	 if(!C1) key=1;
	 if(!C2) key=2;
	 if(!C3) key=3;
	 if(!C4) key='A';

	H2=0;H1=H3=H4=1;
	 if(!C1) key=4;
	 if(!C2) key=5;
	 if(!C3) key=6;
	 if(!C4) key='B';

	H3=0;H2=H1=H4=1;
 	 if(!C1) key=7;
	 if(!C2) key=8;
	 if(!C3) key=9;
	 if(!C4) key='C';

	H4=0;H2=H3=H1=1;
	 if(!C1) key='*';
	 if(!C2) key=0;
	 if(!C3) key='#';
	 if(!C4) key='D';
}
void main(void)
{
     int i;
     P2=0xFF;

      KT();
	  if(key==2)
	   {
	   		BN();		
	   }
	  if (key=='A')
	  {
			NT();
	  }

}
