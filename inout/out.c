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
	P0=0xFF;
	while(1)
	{
		dl=0xFF;
		for(i=0;i<9;i++)
		{
			P0=dl;
			dl=dl<<1;
			tre(20000);
		}
	}
}