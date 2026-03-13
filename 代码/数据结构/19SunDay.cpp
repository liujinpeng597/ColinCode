//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//int SunDay(string& src, string& match)
//{
//	int len1 = src.size();
//	int len2 = match.size();
//	if (len1 == 0 || len2 == 0)return -1;
//	//获得next数组
//	vector<int>next(256, -1);
//	for (int i = 0; i < len2; i++)
//	{
//		next[match[i]] = i;
//	}
//	//匹配
//	int i = 0;
//	int j = 0;
//	int k = i;
//	while (i < len1 && j < len2)
//	{
//		if (src[i] == match[j])
//		{
//			i++;
//			j++;
//		}
//		else
//		{
//			if (k + len2 < len1)
//			{
//				i = k + len2 - next[src[k + len2]];
//				j = 0;
//				k = i;
//			}
//			else
//			{
//				return -1;
//			}
//		}
//	}
//	//检查
//	if (j == len2)
//	{
//		return k;
//	}
//	else
//	{
//		return -1;
//	}
//}
//
//
//
//int main()
//{
//	return 0;
//}