#include <stdio.h>
int main01()
{
	/*定义一个结构体
	 
	//*创建结构体变量*/
    typedef enum card_type {SFZ=1,JSZ,XSZ} CARD_TYPE;
	struct stu_info {
		int stuNum;
		CARD_TYPE cardType;
		char cardNum[20];
		char stuName[30];
		char sex;
	}s1, s2;
	/*创建结构体变量并赋初值*/
	//int a, b=8, c;//创建变量· 并初始值
	//scanf_s("%d",&a);//键盘赋值
	struct stu_info s3 = { 3,SFZ,"20320220","zhangsan","M"},
		s4 = { .stuName = "lisi",.cardType = SFZ,.stuNum = 4 };
	scanf_s("%d%d%s%s %c", &s1.stuNum, &s1.cardType,
		s1.cardNum, 20,
		s1.stuName, 30
		, &s1.sex, 1);
	/*存取结构体成员值 用.操作符*/
	return 0;
}