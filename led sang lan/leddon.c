
// sang lan tu 0 => 7
// tat dan 0 => 7
 /*
#include<AT89x52.h>
#include<stdio.h>
#include<math.h>

unsigned char dl;
void tre(unsigned int tg)
{
 	unsigned int i;
	for(i=0;i<tg;i++);
}
void main(void)
{
	int i;
	P0=0xFA;
		dl=0x00;
		while(1)
		{
		for(i=0;i<9;i++)
		{
			P0=dl;
		
			dl=dl<<1 | 0x01;
			tre(20000);
		}
		for(i=0;i<9;i++)
		{
			P0=dl;
			//tuy y doi chieu huong sang lan
			dl=dl<<1;
			tre(20000);
		}
		}
}
*/

// sang lan dan tu 7 => 0
//tat lan dan tu 7 => 0


#include<AT89x52.h>
#include<stdio.h>
#include<math.h>

unsigned char dl;
void tre(unsigned int tg)
{
 	unsigned int i;
	for(i=0;i<tg;i++);
}
void main(void)
{
	int i;
	P0=0xFA;
		dl=0x00;
		while(1)
		{
		for(i=0;i<9;i++)
		{
			P0=dl;
			// tat dan tu 0.7 ->0.0 => 0x80
			//tat dan tu 0.0 -> 0.7 => 0x01
			dl=dl>>1 | 0x80;
			tre(20000);
		}
		for(i=0;i<9;i++)
		{
			P0=dl;
			//tuy y doi chieu huong sang lan.
			dl=dl>>1;
			tre(20000);
		}
		}
}


//sang lan tu 2 ben vao giua


