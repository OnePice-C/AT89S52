#include <stdio.h>
#include <AT89x52.h>
#include <math.h>

unsigned char DL;
void dlay(unsigned int time)
{
	int i;
	for(i=0;i<time;i++);
}
void main(void)
{
	int i;
	P1=0xFF;
	while(1)
	{
		 DL=0xFF;
		for(i=0;i<9;i++)
		{
			   P1=DL;
			   DL=DL<<1;
			   dlay(200000);

		}

	}
}