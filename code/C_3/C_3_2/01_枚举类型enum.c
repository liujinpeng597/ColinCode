#include<stdio.h>

//方式1： enum 枚举名称 { 内容1,  内容2, 内容3,... };

//方式2： enum 枚举名称 { 内容1=整数,  内容2=整数, 内容3=整数, ...};

int main01()
{
	enum fang_xiang { N, S, W, E };
    //int  age = 5;
	//enum fang_xiang fx = S;
	typedef enum fang_xiang FX;
	FX fx = S;

	typedef enum week { MON = 1, THU, WED, THR, FRI, SAT, SUN = 0 } WEEK;
	if (fx == N) {

	}
	switch (fx) {
	case N:
		break;
	case S:
		break;
	case W:
		break;
	case E:
		break;
	default:
		break;
	}
	return 0;
}