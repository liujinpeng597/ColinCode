#include "apple.h"
#include<stdlib.h>
int appleLie = 5;
int appleHang = 4;

void newApple(void)
{
	//Ëæ»úÆ»¹ûÎ»ÖÃ£º
	appleLie = rand() % 14 + 3;
	appleHang = rand() % 14+ 3;
}
