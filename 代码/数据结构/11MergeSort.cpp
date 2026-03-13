//#include<iostream>
//#include<vector>
//using namespace std;
//
//void merge(vector<int>&nums,int left,int mid,int right) {
//	int n1 = mid - left + 1;
//	int n2 = right - mid;
//	vector<int> L(n1), R(n2);
//	for (int i = 0; i < n1; i++) {
//		L[i] = nums[left + i];
//	}
//	for (int i = 0; i < n2; i++) {
//		R[i] = nums[mid + 1 + i];
//	}
// 
//	int i = 0, j = 0, k = 0;
//	while (i < n1 && j < n2) {
//		if (L[i] < R[j]) {
//			nums[k] = L[i];
//			i++;
//		}
//		else {
//			nums[k] = R[j];
//			j++;
//		}
//		k++;
//	}
// 
//	while (i < n1) {
//		 nums[k] = L[i];
//		 i++;
//		 k++;
//	}
//	while (j < n2) {
//		nums[k] = R[j];
//		j++;
//		k++;
//	}
//}
//
//void mergeSort(vector<int>& nums,int left,int right) {
//	if (left < right) {
//		int mid = (right - left + 1) / 2;
//		mergeSort(nums, left, mid);
//		mergeSort(nums, mid, right);
//		merge(nums, left, mid, right);
//	}
//}
//
//void printArray(const vector<int>& nums) {
//	for (int num : nums) {
//		cout << num << " ";
//	}
//	cout << endl;
//}
//
//int main() {
//	vector<int>nums = { 12,11,13,5,6,7 };
//	printArray(nums);
//	mergeSort(nums, 0, nums.size() - 1);
//	printArray(nums);
//	return 0;
//}