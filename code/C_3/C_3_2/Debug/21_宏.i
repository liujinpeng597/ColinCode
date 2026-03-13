#line 1 "C:\\Users\\24191\\Desktop\\科林明伦\\C_3\\C_3_2\\21_宏.c"

#line 1 "C:\\Users\\24191\\Desktop\\科林明伦\\C_3\\C_3_2\\a.h"
#pragma once

extern int a;

void fun_a(void);
#line 3 "C:\\Users\\24191\\Desktop\\科林明伦\\C_3\\C_3_2\\21_宏.c"
#line 1 "C:\\Users\\24191\\Desktop\\科林明伦\\C_3\\C_3_2\\b.h"
#pragma once

extern int b;

void fun_b(void);
#line 4 "C:\\Users\\24191\\Desktop\\科林明伦\\C_3\\C_3_2\\21_宏.c"










int main()
{
	


	
	
	

	


	    
	
	
	
    
    
	typedef int bool;
	bool sex = 1;

	
    
    
	int arr[] = { 7,9,8,3,6,9,5,2,8,7 };
	int len1 = (sizeof(arr) / sizeof(arr[0]));
	int len2 = (sizeof(arr) / sizeof(int));

	double score[] = { 78,68,59.5,100,99.5 };
	int len3 = (sizeof(score) / sizeof(score[0]));
	int len4 = (sizeof(arr) / sizeof(double));
	
	 
	return 0;
}
