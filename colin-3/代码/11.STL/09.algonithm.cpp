//#include<iostream>
//#include<list>
//#include<vector>
//#include<map>
//#include<algorithm>
//using namespace std;
//
//void oddAddOne(int& v)
//{
//	if (v % 2 == 1)
//	{
//		++v;
//	}
//}
//
//void show(int v)
//{
//	cout << v << "  ";
//}
//
//void show_map(pair<char, string>pr)
//{
//	cout << pr.first << "-" << pr.second << " ";
//}
//
//void show_map2(pair<int, char>pr)
//{
//	cout << pr.first << "-" << pr.second << " ";
//}
//
//int main()
//{
//	list<int> v{ 3,8,1,0 };
//	//迭代器 for(type val:containers)
//	::for_each(v.begin(), v.end(), &show);  //左闭右开
//	cout << endl;
//
//	map<char, string>m{ {'1',"11"},{'a',"aa"},{'6',"66"},{'c',"cc"} };
//	::for_each(m.begin(), m.end(), &show_map);
//	cout << endl;
//
//	::for_each(m.begin(), ++ ++m.begin(), &show_map);
//	cout << endl;
//
//	::for_each(v.begin(), v.end(), &oddAddOne);
//	::for_each(v.begin(), v.end(), &show);
//	cout << endl;
//
//	vector<int>vec{ 4,1,4,0,7,4 };
//	cout << ::count(vec.begin(), vec.end(), 4) << endl;
//
//	cout << ::count(vec.begin(), vec.begin() + 4, 4) << endl; //指定范围内统计   2
//
//	vector<int>vec2{ 4,1,4,0,7,5 };
//
//	//cout << ::equal(vec.begin(), vec.end(), vec2.begin()) << endl;  //0
//	cout << ::equal(vec.begin(), vec.end() - 1, vec2.begin()) << endl;  //1
//
//	vector<int>vec3{ 4,1,4,0 };
//	//注意：如果被比较的范围小，程序异常
//	//cout << ::equal(vec.begin(), vec.end() - 1, vec3.begin()) << endl;
//
//	vector<int>::iterator it = ::find(vec3.begin(), vec3.end(), 1);
//	cout << *it << endl;  //1
//
//	it = ::find(vec3.begin(), vec3.end(), 11);
//
//	if (it == vec3.end())
//	{
//		cout << "没找到" << endl;
//	}
//
//	it = ::find(vec3.begin(), vec3.begin() + 3, 11);
//	if (it == vec3.begin() + 3) //判断是否找到，比较的是范围的为，而不是容器的尾
//	{
//		cout << "没找到" << endl;
//	}
//	else
//	{
//		cout << "找到了:" << *it << endl;  //找到了:0
//	}
//
//
//	vector<int>vec4{ 5,1,3,8,0 };
//	::sort(vec4.begin(), vec4.end()); //默认升序
//	::for_each(vec4.begin(), vec4.end(), &show); //0  1  3  5  8
//	cout << endl;
//
//	::sort(vec4.begin(), vec4.end(), greater<int>());
//	::for_each(vec4.begin(), vec4.end(), &show); //8  5  3  1  0
//	cout << endl;
//
//	::sort(vec4.begin(), vec4.begin() + 3, less<int>());  //less：升序
//	::for_each(vec4.begin(), vec4.end(), &show); //3  5  8  1  0
//	cout << endl;
//
//
//	v.sort();  //特定容器的排序
//	//::sort(v.begin(), v.end()); //为何不能排序：链表迭代器，不支持随机访问，而2sort要求随机访问。
//
//	list<int>v1{ 1,2,3 };
//	list<int>v2{ 1,2,4 };
//	list<int>lstMax = max(v1, v2);
//	::for_each(lstMax.begin(), lstMax.end(), &show); //1  2  4
//	cout << endl;
//
//	list<int> v3{ 1,3 };
//	lstMax = max(v1, v3);
//	::for_each(lstMax.begin(), lstMax.end(), &show); //1  3
//	cout << endl;
//
//	map<int, char>mm1{ {1,'b'} };
//	map<int, char>mm2{ {2,'a'} };
//
//	map<int, char>mMin = ::min(mm1, mm2);
//	::for_each(mMin.begin(), mMin.end(), &show_map2);  //1-b
//	cout << endl;
//
//
//	return 0;
//}