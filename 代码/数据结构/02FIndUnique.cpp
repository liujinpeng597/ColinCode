//#include<iostream>
//#include<vector>
//using namespace std;
//
//void findUnique(vector<int>nums)
//{
//	int len = nums.size();
//	if (len<=0)return;
//	int result = 0;//任何数与0异或都等于他本身
//	for (int v : nums)
//	{
//		result ^= v;
//	}//计算出所有数按位异或的结果result
//	//-----------------------------
//	int mask = 1;//找到从右数第一个1的位置
//	while ((result & mask) == 0)//mask(2) = 0001;  result(2) = 0100; 如果按位与等于0就说明mask的1和result的1没对齐
//	{
//		mask <<= 1;//所以每次进入循环都会将mask左移 mask(2) = 0010; mask(3)=0100;直到mask = result = 0100;循环结束
//	}
//	//-----------------------------
//	int num1 = 0, num2 = 0;//进行分组 num1,num2用于储存两个只出现一次的数
//	//因为分组之后 会是这样的情形
//	//1. 7 6 6 7 5; 1组按位异或得到5
//	//0. 1 8 3 3 8; 0组安慰异或得到1
//	for (int v : nums)//循环遍历数组
//	{																						//  0  1  0  0 
//		if ((mask & v) == 0)//如果mask(2) = 0100;按位与数组中的元素arr[1] == 0;说明arr[i]在x  1  x  x中第三位不为1
//		{																					//    ↑	
//			num1 ^= v;//将num1按位异或arr[i];												第三位
//		}
//		else//反之说明arr[i]在x1xx中第三位为1;
//		{
//			num2 ^= v;//将num2按位异或arr[i]
//		}
//	}
//	cout << num1 << " " << num2 << endl;
//}
//
//int main()
//{
//	//int arr[] = { 1,7,6,8,3,6,7,3,8,5 };//定义一个数组arr
//	//int len = sizeof(arr) / sizeof(int);//计算出arr的长度
//	vector<int>nums = { 1,7,6,8,3,6,7,3,8,5 };
//	findUnique(nums);
//
//	vector<int>num2;
//	num2.push_back(10);
//	num2.push_back(20);
//	num2.emplace_back(30);
//	for (int v : num2)
//	{
//		cout << v << " ";
//	}
//	cout << endl;
//
//	vector<int>num3(10, 0);
//	for (int v : num3)
//	{
//		cout << v << " ";
//	}
//	cout << endl;
//
//	vector<int>num4(5);
//
//	return 0;
//}