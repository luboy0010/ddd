#include <REGX52.H>
#include "Delay.h"

int num[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7f,0x6F};

void LIGHT(unsigned char a,b)
{
	if(a==1)
		{
			P2_4=1;
			P2_3=1;
			P2_2=1;
		}
	else if(a==2)
			{
				P2_4=1;
				P2_3=1;
				P2_2=0;	
			}
	else if(a==3)
			{
				P2_4=1;
				P2_3=0;
				P2_2=1;	
			}
	else if(a==4)
			{
				P2_4=1;
				P2_3=0;
				P2_2=0;
			}
	else if(a==5)
			{
				P2_4=0;
				P2_3=1;
				P2_2=1;
			}
	else if(a==6)
			{
				P2_4=0;
				P2_3=1;
				P2_2=0;
			}
	else if(a==7)
			{
				P2_4=0;
				P2_3=0;
				P2_2=1;
			}
	else if(a==8)
			{
				P2_4=0;
				P2_3=0;
				P2_2=0;
			}
	P0=num[b];
	Delay(1);
	P0=0x00;			
}