#include<iostream>
using namespace std;

//如果在无进位的情况下 把两个数异或就能求出两个数相加的值
//如果在有进位的情况下 位与可以找到进位的数字
int add(int num1, int num2)
{
	if (num2 == 0) {
		return num1;
	}
	return add(num1 ^ num2 , (num1 & num2)<<1);
}

int main()
{
	cout<<add(-2, 16)<<endl;
	return 0;
}