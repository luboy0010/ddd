#include<REGX52.H>

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


void main()
{
	unsigned char a=0;
	while(1)
		{
			if(P3_1==0)
				{
					Delay(20);
					while(P3_1==0);
					Delay(20);
					
					a++;
					P2=~a;
				}
			
		}
}	