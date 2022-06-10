#include <stdio.h>
#include <math.h>
#include <AT89x52.h>

#define RS P0_0
#define RW P0_1
#define EE P0_2

unsigned char dl;
unsigned char mes[32];
void delay(unsigned int time)
{
	int i;
	for(i=0;i<time;i++);
}
unsigned read_key(void)
{
	unsigned char du_lieu[4]={0xFE, 0xFD, 0xFB, 0xF7}, key, keys; 
	int i;
	for(i=0;i<4;i++)
	{
		P0 = du_lieu[i];  
	    keys =(P0&0xF0); 
		if(i==0)
		{
			switch (keys)
			{
				case 0x70: key=1; return key;
				case 0xB0: key=2; return key;
				case 0xD0: key=3; return key;
				case 0xE0: key=10; return key;
			}

		}
		if(i==1)
		{
			switch(keys)
			{
				case 0x70: key=4; return key;
				case 0xB0: key=5; return key;
				case 0xD0: key=6; return key;
				case 0xE0: key=11; return key;
			}
		}
		if(i==2)
		{
			switch(keys)
			{
				case 0x70: key=7; return key;
				case 0xB0: key=8; return key;
				case 0xD0: key=9; return key;
				case 0xE0: key=12; return key;
			}
		}
	 	if(i==3)
		{
			switch(keys)
			{
				case 0x70: key=13; return key;
				case 0xB0: key=0; return key;
				case 0xD0: key=15; return key;
				case 0xE0: key=14; return key;
			}
		}
	}
}

void busy_lcd(void)
{
	unsigned char du_lieu;
	while(1)
	{
		P2=0xFF;
		RS=0;
		RW=1;
		EE=1;
		du_lieu=P2;
		delay(1000);
		EE=0;
		if((du_lieu & 0x80)==0);
		break;
	}
}

void  write_cmd_lcd(void)
{
		busy_lcd();  
	    RW = 0;       
		RS = 0; 
	    EE = 1;    
	    P2 =cmd;   
	    EE = 0; 
}
void lcd_gotoxy (unsigned char x, unsigned char y)
{
	 if(y==0)      
	  write_cmd_lcd(0x80+x);
	  if(y==1) 
	  write_cmd_lcd(0xc0+x);
}
void init_lcd (void) 
 {   
    write_cmd_lcd(0x38); 
    write_cmd_lcd(0x0C); 
	  write_cmd_lcd(0x06); 
	  write_cmd_lcd(0x01); 
	  write_cmd_lcd(0x02);
}
void write_du_lieu_lcd(char du_lieu) 
 {    if(du_lieu=='\n')
    {     write_cmd_lcd(0xC0);
	       return; 
    }  
			   if(du_lieu=='\1') 
			     {   
				   write_cmd_lcd(0x01);  
				     return; 
			     }    
					 busy_lcd();
				     RW = 0; 
				     RS = 1; 
				     EE = 1; 
				     P2   = du_lieu; 
				     EE = 0; 
   }  
 
void write_str_lcd(char *str) 
 {   while(*str)
    {    write_du_lieu_lcd(*str);
	    str++; 
		  }
		  } void main (void) 
		   { 
		     P0 = 0x00;  
		    P2  = 0x00;  
			 P3 = 0x00;   
			  init_lcd(); 
			    while(1)  
				 {  
				  dl = read_key();
				  sprintf(&mes[0],”\1 %d”, dl);
				    write_str_lcd(&mes[0]); 
					   delay(1000); 
					      }  
						  } 