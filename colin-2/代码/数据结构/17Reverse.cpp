//#include<iostream>
//#include<string>
//using namespace std;
//
//string replaceTheSpaces(string str)
//{
//	string buffer_str;
//	
//	/*for (int i = 0; i < str.size(); i++)
//	{
//		if (str[i] != ' ')
//		{
//			buffer_str += str[i];
//		}
//		else
//		{
//			buffer_str += "lucky";
//		}
//	}*/
//
//	for (char c : str)
//	{
//		if (c != ' ')
//		{
//			buffer_str += c;
//		}
//		else
//		{
//			buffer_str += "lucky";
//		}
//	}
//	return buffer_str;
//}
//
//string reserveStr(string str)
//{
//	string buffer_str;
//	string word;
//	for (char c : str)
//	{
//		if (c != ' ')
//		{
//			word += c;
//		}
//		else
//		{
//			if (!buffer_str.empty())
//			{
//				buffer_str = word + " " + buffer_str;
//			}
//			else
//			{
//				buffer_str = word;
//			}
//			word.clear();
//		}
//	}
//	if (!buffer_str.empty())
//	{
//		buffer_str = word + " " + buffer_str;
//	}
//	else
//	{
//		buffer_str = word;
//	}
//	word.clear();
//	return buffer_str;
//}
//
//void Reverse(string& str, int begin,int end)
//{
//	//交换
//	while (begin < end)
//	{
//		swap(str[begin], str[end]);
//	}
//}
//void ReverseString(string& str)
//{
//	int len = str.size();
//	if (len == 0)return;
//
//	//整体翻转
//	Reverse(str, 0, len - 1);
//	//单词反转
//	int i = 0;
//	int j = 0;
//	while (j < len)
//	{
//		//过滤空格
//		while (str[i] == ' ')
//		{
//			i++;
//		}
//		j = i;
//		while (str[j] != ' ' && str[j] != '\0')
//		{
//			j++;
//		}
//	}
//	Reverse(str, i, j - 1);
//	i = j;
//}
//
//int main()
//{
//	//string str = "we  are really  good friends.";
//	string str2 = "Here lies Arthur,king once, king to be";
//	//cout << replaceTheSpaces(str) << endl;
//	cout << reserveStr(str2) << endl;;
//	return 0;
//}