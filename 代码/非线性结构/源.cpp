#include <iostream>
#include <vector>
using namespace std;

// 合并两个有序子数组
void merge(vector<int>& arr, int left, int mid, int right) {
    // 计算左右子数组的大小
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // 创建临时数组
    vector<int> L(n1), R(n2);

    // 复制数据到临时数组
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // 合并临时数组回原数组
    int i = 0;     // 左子数组的起始索引
    int j = 0;     // 右子数组的起始索引
    int k = left;  // 合并后数组的起始索引

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // 复制剩余的元素
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// 归并排序主函数
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        // 找到中间点
        int mid = left + (right - left) / 2;

        // 分别排序左右两部分
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // 合并已排序的两部分
        merge(arr, left, mid, right);
    }
}

// 辅助函数：打印数组
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// 主函数示例
int main() {
    vector<int> arr = { 12, 11, 13, 5, 6, 7 };

    cout << "排序前的数组: ";
    printArray(arr);

    mergeSort(arr, 0, arr.size() - 1);

    cout << "排序后的数组: ";
    printArray(arr);

    return 0;
}
