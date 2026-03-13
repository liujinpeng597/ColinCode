//#include<iostream>
//#include<vector>
//using namespace std;
//
//void InsertSort(vector<int>& nums)
//{
//	int len = nums.size();
//	if (len <= 1)return;
//	//无序部分
//	for (int i = 1; i < len; i++)
//	{
//		//倒序遍历有序数组
//		int j = i - 1;
//		while (j >= 0 && nums[j] > nums[i])
//		{
//			//有序元素向右移动
//			nums[j + 1] = nums[j];
//			j--;
//		}
//		//无序元素放入
//		nums[j + 1] = nums[i];
//	}
//}
//
//void InsertSort2(vector<int>& nums)
//{
//	int len = nums.size();
//	if (len <= 1)return;
//	//无序部分
//	for (int i = 1; i < len; i++)
//	{
//		int wx = nums[i];
//		//倒序遍历有序数组
//		for (int j = i - 1; j >= 0; j--)
//		{
//			//比较
//			if (nums[j] > wx)
//			{
//				//有序数组向右移动一位
//				nums[j + 1] = nums[j];
//				if (j == 0)
//				{
//					nums[0] = wx;
//					break;
//				}
//			}
//			else
//			{
//				//放入有序数组
//				nums[j + 1] = wx;
//				break;
//			}
//		}
//	}
//}
//
//void Printf(vector<int>& nums)
//{
//	for (int v : nums)
//	{
//		cout << v << " ";
//	}
//}
//int main()
//{
//	vector<int>nums = { 6,3,2,9,8,1,0 };
//
//	InsertSort2(nums);
//	Printf(nums);
//	return 0;
//}
//
//void InsertSort3(vector<int>& nums) {
//	int len = nums.size();
//	for (int i = 1; i < len; i++) {
//		int j = i - 1;
//		while (j >= 0 && nums[j] > nums[i]) {
//				nums[j+1] = nums[j];
//				j--;
//		}
//		nums[j + 1] = nums[i];
//	}
//}