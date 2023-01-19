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
	int step=0;//ÒÆ¶¯Î»Êý
	P2=~(0x01);
	while(1)
		{	
			
			if(P3_0==0)
				{
					Delay(20);
					while(P3_0==0);
					Delay(20);
					
					
					step++;
					if(step>=8)
						step=0;
					P2=~(0x01<<step);
					
				}
			if(P3_1==0)
				{
					Delay(20);
					while(P3_1==0);
					Delay(20);
					
					step--;
					if(step<=-1)
						step=7;
					P2=~(0x01<<step);
					
				}	
		}
}