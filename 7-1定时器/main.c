#include <REGX52.H>
#include <INTRINS.H>
#include "DELAY.H"
#include "LCD1602.H"
#include "Timer0.h"
#include "matrixkey.h"

unsigned int keynum=0,ledmode=0;

void main()
{	
	P2=0xFE;
	Timer0_Init();
	while(1)
		{
			keynum=matrixkey();
			if(keynum)
				{
					if(keynum==1)
						{
							ledmode++;
							if(ledmode>=2)ledmode=0;
						}
				}
		}
}

void Timer0_Routine() interrupt 1
{	
	static unsigned int T0count=0;
	TL0 = 0x66;		//设置定时初值
	TH0 = 0xFC;
	T0count++;
	if(T0count>=500)
		{
			T0count=0;
			if(ledmode==0)
				P2=_crol_(P2,1);
			if(ledmode==1)
				P2=_cror_(P2,1);
		}
}	