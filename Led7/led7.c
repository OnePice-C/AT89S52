#include <AT89x52.h>
#include <stdio.h>
#include <math.h>

#define DV P2_0
#define CH P2_1
#define TR P2_2
#define NG P2_3

#define H1 P1_0
#define H2 P1_1
#define H3 P1_2
#define H4 P1_3

#define C1 P1_7
#define C2 P1_6
#define C3 P1_5
#define C4 P1_4


unsigned char dl[10]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
unsigned dv,ch,tr,ng;
unsigned char key;

void KT(void)
{							  
	  H1=0; H2=H3=H4=1;
	  if(!C1) key=1;
	  if(!C2) key=2;
	  if(!C3) key=3;
	  if(!C4) key=10;

	  H1=H3=H4=1; H2=0;
	  if(!C1) key=4;
	  if(!C2) key=5;
	  if(!C3) key=6;
	  if(!C4) key=11;

	  H3=0; H2=H1=H4=1;
	  if(!C1) key=7;
	  if(!C2) key=8;
	  if(!C3) key=9;
	  if(!C4) key=12;

	  H4=0; H2=H3=H1=1;
	  if(!C1) key='*';
	  if(!C2) key=0;
	  if(!C3) key='#';
	  if(!C4) key=13;
}

void delay(int time)
{
	int i,t;
	for(i=0;i<time;i++)
	{
	   for(t=0;t<100;t++);
	}
}
void read_led(int i)
{	
		ng=i/1000;
		tr=(i%1000)/100;
		ch=(i%100)/10;
		dv=(i%100)%10;

  	  	P2=0x01;
		P3=dl[dv];
		delay(10);

		P2=0x02;
		P3=dl[ch];
		delay(10);
		P2=0x04;
		P3=dl[tr];
		delay(10);
		P2=0x08;
		P3=dl[ng];
		delay(10);
}

void main(void)
{
	while(1)
	{
	KT();
	if(key==1)
	{
	read_led(1);
	}
	}
}
