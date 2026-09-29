//#include<iostream>
//#include<vector>
//using namespace std;
//
//bool BinaryChop(vector<int>& nums, int target, int begin, int end)
//{
//	if (begin > end)return false;
//
//	//获得mid
//	int mid;
//	mid = begin + (end - begin) / 2;/*(begin + end) / 2;*/
//	//比较
//	if (target == nums[mid])
//	{
//		return true;
//	}
//	else if (target < nums[mid])
//	{
//		//左半部分查找
//		BinaryChop(nums, target, begin, mid - 1);
//	}
//	else
//	{
//		//右半部分查找
//		BinaryChop(nums, target, mid + 1, end);
//	}
//}
//
//bool BinaryChop2(vector<int>& nums, int target, int begin, int end)
//{
//	if (begin > end)return false;
//	int mid;
//
//	while (begin <= end)
//	{
//		mid = begin + (end - begin) / 2;
//		//比较
//		if (target == nums[mid])
//		{
//			return true;
//		}
//		else if (target < nums[mid])
//		{
//			//左半部分
//			end = mid - 1;
//		}
//		else
//		{
//			//右半部分
//			begin = mid + 1;
//		}
//	}
//	return false;
//}
//
//
//
//int main()
//{
//	vector<int>nums = { 10,20,30,40,50,60,70 };
//	cout << BinaryChop2(nums, 80, 0, 6) << endl;
//	return 0;
//}