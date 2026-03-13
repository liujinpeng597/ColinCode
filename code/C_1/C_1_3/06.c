#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*
人机猜数游戏
由计算机“想”一个四位数，请人猜这个四位数是多少。人输入四位数字后，计算机首先判断这四位数字中有几位是猜对了，并且在对的数字中又有几位位置  也是对的，将结果显示出来，给人以提示，请人再猜，直到人猜出计算机所想的四位数是多少为止
*/
int main()
{
	int num = 0;
	
	srand((unsigned)time(NULL));//随机数初始化
	num= rand()%9000+1000;//产生随机的四位数

	int guess = 0;
	int count = 0;

	while (guess != num) {
		printf("请输入你猜测的数字(四位):_____\b\b\b\b\b");
		scanf_s("%4d",&guess);
		count++;

		int caibi = 0;

		if (count == 10)
		{
			printf("都猜这么多次了,叫爸爸给你看密码/笑哭\n");
			printf("是否需要密码?\n");
			printf("1.需要，但得叫爸爸\n");
			printf("2.不服,继续干\n");
			int select = 0;
			scanf_s("%d", &select);
			if (select == 1) {
				printf("这是密码:%d\n", num);
				caibi = 1;
			}
			else if (select == 2) {
				printf("好好好,继续吧\n");
			}
		}

		if (guess == num) {
			if (count == 1) {
				printf("牛逼！真有狗点子，一次就让你猜对了！\n",count);
			}
			else if(count>1 && count <=10){
				printf("有点实力啊！猜对用了%d次！\n", count);
			}
			else{
				if (caibi = 1)
				{
					printf("乖儿子,多亏有爸爸的帮助");
				}
				printf("还得练啊,猜%d次!\n",count);
			}
			break;
		}
		else if(guess>num){
			printf("猜大了，请重新猜！\n");
			continue;
		}
		else {
			printf("猜小了，请重新猜！\n");
			continue;
		}
	}
	return 0; 
}