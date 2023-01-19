
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