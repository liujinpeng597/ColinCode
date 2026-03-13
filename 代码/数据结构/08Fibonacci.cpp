//#include<iostream>
//using namespace std;
//
//int fibonacci(int n)
//{
//	if (n == 0)
//	{
//		return 0;
//	}
//	else if (n == 1)
//	{
//		return 1;
//	}
//	return fibonacci(n - 1) + fibonacci(n - 2);
//}
//
//int fibonacci2(int n)
//{
//	int a, b, c;
//	for(int i = 3;i<=n;i++)
//	{
//		if (i==3)
//		{
//			a = 1;
//			b = 1;
//			c = a + b;
//		}
//		else
//		{
//			a = b;
//			b = c;
//			c = a + b;
//		}
//	}
//	return c;
//}
//
//
//
//int main()
//{
//	//cout << "fibonacci: " << fibonacci(50) << endl;
//	cout << "fibonacci2: " << fibonacci2(48) << endl;
//	return 0;
//}