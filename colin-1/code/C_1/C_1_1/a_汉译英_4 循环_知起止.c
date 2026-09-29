#include<stdio.h>

/* 中高风险密接的人——隔离期 */
int main(){

	int day = 1;

	 for(;;){
		 if (day <= 14 + 7){
             printf("隔离第%d天\n",day);
		 }
		 else {
			 break;
		 }
		 day++;
	 }
	 printf("隔离结束！");
	 return 0;
}