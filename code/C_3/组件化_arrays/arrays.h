#pragma once
/*
功能：交换数组某两个下标对应的值 
参数：arr 数组名  length 数组长度  asc升降序
返回值：无
*/
void swap(int arr[], int index,int otherIndex);
/*
功能：对数组排序
参数：arr 数组名  length 数组长度  asc升降序
返回值：无
*/
void sort(int arr[] ,int length,int asc);
/*
功能：折半查找 
参数：arr 数组名  length 数组长度  n 寻找的数据
返回值：n在数组arr中的下标，<0代表没找到
*/
int binarySearch( int arr[] ,int length,int n );
/*
功能：得到数组中的最大值
参数：arr 数组名  length 数组长度  
返回值：最大整数
*/
int max_( int arr[] ,int length  );
/*
功能：得到数组中的最小值 
参数：arr 数组名  length 数组长度 
返回值：最小整数
*/
int min_( int arr[]  ,int length );
/*
功能：累计数组的和
参数：arr 数组名  length 数组长度  
返回值：和
*/
int sum( int arr[] ,int length  );
/*
功能：计算数组的平均值
参数：arr 数组名  length 数组长度 
返回值：平均值
*/
double avg( int arr[], int length );

/*
功能：翻转（首尾倒置）数组成员
参数：arr 数组名  length 数组长度 
返回值：无
*/
void reserveArray( int arr[], int length );
/*
功能：打乱数组成员的排序
参数：arr 数组名  length 数组长度   
返回值：无
*/
void shuffle( int arr[], int length );
/*
功能：给数组所有成员赋同一个指定的值
参数：arr 数组名  length 数组长度  num 统一赋的值
返回值：无
*/
void fill(int arr[], int length,int num);
/*
功能： 数组复制
参数：from数据来源数组  
      fromPos 开始的下标 
	  to数据复制的目标数组 
	  toPos目标数组的位置
	  length 复制的成员长度
返回值：无
*/
void arrayCopy(int from[] ,int fromPos, int to[] ,int toPos, int length);

