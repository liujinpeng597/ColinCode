#include <stdio.h>
/*
´òÓ¡5×é£º24678
*/
int main202 ()
{
	int zu,shu;
	for (  zu=1;zu<=5;zu++)
	{
		for (  shu=2;shu<=8;shu+=2)
		{
			printf("%i ",shu);
			if (shu==6) 
			{
				printf("%i ",shu+1);
			} 
			if (shu==8) 
			{
				printf("\n");
			} 
		}
	}
	return 0;
} 