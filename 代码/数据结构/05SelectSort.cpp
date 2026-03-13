//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
////最小索引
//void selectSort(vector<int>& nums)
//{
//	int len = nums.size();
//	for (int i = 0; i < len; i++)
//	{
//		int minindex = i;
//		for (int j = i; j < len - i; j++)
//		{
//			if (nums[j] < nums[minindex])
//			{
//				minindex = j;
//			}
//		}
//		swap(nums[i], nums[minindex]);
//	}
//}
//
////最大索引
//void selectSort2(vector<int>& nums)
//{
//	int len = nums.size();
//	for (int i = 0; i < len-1; i++)
//	{
//		int maxindex = 0;
//		for (int j = 0; j < len - i; j++)
//		{
//			if (nums[j] > nums[maxindex])
//			{
//				maxindex = j;
//			}
//		}
//		swap(nums[len - 1 - i], nums[maxindex]);
//	}
//}
//
//void myPrint(vector<int>&nums)
//{
//	for (int v:nums)
//	{
//		cout << v << " ";
//	}
//	cout << endl;
//}
//
//int main()
//{
//	vector<int>nums = { 8,3,6,9,1,10,12,15,19 };
//	selectSort2(nums);
//	myPrint(nums);
//	return 0;
//}