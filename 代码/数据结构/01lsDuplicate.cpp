//#include<iostream>
//#include<algorithm>
//using namespace std;
//
//bool check(int arr[], int len)
//{
//	for (int i = 0; i < len;)
//	{
//		//判断数组中第i个元素与i是否相同
//		if (arr[i] != i)//如果不同
//		{
//			//判断数组中第arr[i]个元素与arr[i](下标)是否相同
//			if (arr[arr[i]] == arr[i])//如果相同
//			{
//				return false;//返回false 因为数组中第i个元素与第arr[i]个元素相同
//			}
//			else//如果不同
//			{
//				//交换数组中第arr[i]个和第i个的元素
//
//				int temp;
//				//1------------------
//				/*temp = arr[arr[i]];
//				arr[arr[i]] = arr[i];
//				arr[i] = temp;*/
//
//				//2------------------
//				/*temp = arr[i];
//				arr[i] = arr[arr[i]];
//				arr[temp] = temp;*/
//
//				//3------------------
//				/*arr[i] = arr[i] ^ arr[arr[i]];
//				arr[arr[i]] = arr[i] ^ arr[arr[i]];
//				arr[i] = arr[i] ^ arr[arr[i]];*/
//
//				//4------------------
//				swap(arr[i], arr[arr[i]]);
//			}
//		}
//		else//如果相同
//		{
//			i++;//向后遍历
//		}
//	}
//	return true;
//}
//
//int main()
//{
//	//如果函数中有重复元素就报错
//	int arr[] = { 1, 3, 2, 0 };
//	int len = sizeof(arr) / sizeof(int);
//	if (!check(arr, len))cout << "错误！" << endl;
//	return 0;
//}
//
