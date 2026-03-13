//#include<iostream>
//#include<vector>
//using namespace std;
//
//int Find(vector<int>& nums, int begin, int end)//填坑法
//{
//	int tmp = nums[begin];
//
//	while (begin < end)
//	{
//		//从右向左遍历找比标准值小的
//		while (end > begin)
//		{
//			if (nums[end] < tmp)
//			{
//				//填入左边的坑
//				nums[begin] = nums[end];
//				begin++;
//				break;
//			}
//			end--;
//		}
//
//		//从左向右找比标准值大的
//		while (begin < end)
//		{
//			if (nums[begin] > tmp)
//			{
//				//填入右边坑
//				nums[end] = nums[begin];
//				end--;
//				break;
//			}
//			begin++;
//		}
//	}
//	nums[begin] = tmp;
//	return begin;
//}
//
//int Find2(vector<int>& nums, int begin, int end)
//{
//	int small = begin;
//	//遍历数组
//	for (begin; begin < end; begin++)
//	{
//		if (nums[begin] < nums[end])
//		{
//			swap(nums[small++], nums[begin]);
//		}
//	}
//	//标准值放入
//	swap(nums[small], nums[end]);
//}
//
//
//void QuickSort(vector<int>& nums, int begin, int end)
//{
//	if (begin >= end)return;
//
//	//确定标准值的位置
//	int s = Find2(nums, begin, end);
//
//	//根据标准值的位置将数据分成两部分 各部分快速排序
//	QuickSort(nums, begin, s - 1);
//	QuickSort(nums, s + 1, end);
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
//	QuickSort(nums, 0, nums.size() - 1);
//	Printf(nums);
//	return 0;
//}
//
//int Find3(vector<int>nums,int begin,int end) {
//	int temp = nums[begin];
//	while (begin < end) {
//		while (begin < end) {
//			if (nums[end] < temp) {
//				nums[begin] = nums[end];
//				begin++;
//				break;
//			}
//			end--;
//		}
//		while (begin < end) {
//			if (nums[begin] > temp) {
//				nums[end] = nums[begin];
//				end--;
//				break;
//			}
//			begin++;
//		}
//	}
//	nums[begin] = temp;
//	return begin;
//}