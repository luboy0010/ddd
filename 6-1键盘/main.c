#include <REGX52.H>
#include "LCD1602.H"
#include "Delay.h"
#include "matrixkey.h"



void main()
{
	unsigned int keynum;
	unsigned int password[8]={0,5,2,0,1,3,1,4},putin[8]={0};
	unsigned int count=0,Try=0,i=0;
	LCD_Init();
	LCD_ShowString(1,1,"PASSWORD:");
	LCD_ShowString(2,1,"00000000");
	while(1)
		{
			keynum=matrixkey();
			if((keynum>=1)&&(keynum<=10)&&(count<=7)&&Try<=5)
				{
					keynum=keynum%10;
					putin[count]=keynum;
					LCD_ShowNum(2,count+1,putin[count],1);
					count++;
				}
			if(keynum==11&&Try<=5)
				{
					for(i=0;i<=7;i++)
						{
							if((password[i])!=(putin[i]))
								{
									count=0;
									LCD_Init();
									LCD_ShowString(1,1,"ERROR");
									Try++;
									Delay(5000);
									LCD_ShowString(1,1,"PASSWORD:");
									LCD_ShowString(2,1,"00000000");
									break;
								}
							if(i==7)
								{
									LCD_Init();
									LCD_ShowString(1,1,"GOODBYE");
									LCD_ShowString(2,1,"GOODBYE");
								}	
						}
				}
			if(keynum==12&&Try<=5)
				{
					for(i=0;i<=7;i++)
						{
							putin[i]=0;
						}
					count=0;	
					LCD_ShowString(1,1,"PASSWORD:");
					LCD_ShowString(2,1,"00000000");	
				}
			if(keynum==13&&Try<=5&&count>0)
				{
					count--;
					LCD_ShowString(1,1,"PASSWORD:");
					LCD_ShowString(2,1,"00000000");
					for(i=0;i<count;i++)
						{
							LCD_ShowNum(2,i+1,putin[i],1);
						}
				}
		}
}