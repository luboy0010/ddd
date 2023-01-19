#include<REGX52.H>

int num[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7f,0x6F};

void Delay(unsigned int a)		//@12.000MHz
{
	for(;a>0;a--)
		{
			unsigned char i, j;
			i = 2;
			j = 239;
			do
			{
				while (--j);
			} while (--i);
		}
}

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

void main()
{
	
	while(1)
	{
		LIGHT(7,1);
		LIGHT(8,0);
		Delay(1000);
		LIGHT(8,9);
		Delay(1000);
		LIGHT(8,8);
		Delay(1000);
		LIGHT(8,7);
		Delay(1000);
		LIGHT(8,6);
		Delay(1000);
		LIGHT(8,5);
		Delay(1000);
		LIGHT(8,4);
		Delay(1000);
		LIGHT(8,3);
		Delay(1000);
		LIGHT(8,2);
		Delay(1000);
		LIGHT(8,1);
		Delay(1000);
	}
}