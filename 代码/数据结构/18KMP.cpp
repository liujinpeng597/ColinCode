//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//void GetNext(string& match, vector<int>& next)
//{
//	next[0] = 0;
//
//	//遍历串
//	int len = match.length();
//	int i = 1;
//	int j = i - 1;
//	while (i < len)
//	{
//		if (match[i] == match[next[j]])
//		{
//			next[i] = next[j] + 1;
//			i++;
//			j = i - 1;
//		}
//		else if (next[j] == 0)
//		{
//			next[i] = 0;
//			i++;
//			j = i - 1;
//		}
//		else
//		{
//			j = next[j] - 1;
//		}
//	}
//}
//
//int KMP(string& src, string& match)
//{
//	int len1 = src.length();
//	int len2 = match.length();
//	if (len1 == 0 || len2 == 0)return -1;
//
//	//获得next数组
//	vector<int>next(len2);
//	GetNext(match, next);
//
//	//匹配
//	int i = 0;
//	int j = 0;
//	while (i < len1 && j < len2)
//	{
//		//比较
//		if (src[i] == match[j])
//		{
//			i++;
//			j++;
//		}
//		else
//		{
//			if (j == 0)
//			{
//				i++;
//			}
//			else
//			{
//				//匹配串跳转
//				j = next[j - 1];
//			}
//		}
//	}
//
//	//检查匹配串走完了嘛
//	if (j == len2)
//	{
//		return i - j;
//	}
//	else
//	{
//		return -1;
//	}
//}
//
//int main()
//{
//	string src = "abcdabcdabca";
//	string match = "abca";
//	cout << KMP(src, match) << endl;
//	return 0;
//}