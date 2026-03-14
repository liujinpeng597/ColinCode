//#include<iostream>
//#include<list>
//using namespace std;
//
//
//
//int main()
//{
//	list<int> lst{ 1,2,3,4 };
//	list<int>::iterator it = lst.begin();  //正向迭代器
//	while (it != lst.end())
//	{
//		cout << *it << "  "; //1  2  3  4
//		++it;
//	}
//	cout << endl;
//
//	it = lst.end();
//	while (it != lst.begin())
//	{
//		--it;
//		cout << *it << "  "; //4  3  2  1
//	}
//	cout << endl;
//
//	list<int>::reverse_iterator itRev = lst.rbegin();
//	while (itRev != lst.rend())  //反向的尾
//	{
//		cout << *itRev << "  ";  //4  3  2  1
//		++itRev;
//	}
//	cout << endl;
//
//	itRev = lst.rbegin();
//	while (itRev != lst.rend())
//	{
//		if (*itRev == 2)
//		{
//			//itRev转为正向迭代器
//			it = --itRev.base();  //向正向偏移一位
//
//			lst.erase(it);
//			break;
//		}
//		++itRev;
//	}
//	cout << endl;
//
//	itRev = lst.rbegin();
//	while (itRev != lst.rend())  //反向的尾
//	{
//		cout << *itRev << "  ";  //4  3  1
//		++itRev;
//	}
//	cout << endl;
//
//
//
//	return 0;
//}