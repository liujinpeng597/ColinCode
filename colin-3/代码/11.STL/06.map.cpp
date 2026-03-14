//#include<iostream>
//#include<map>
//using namespace std;
//
//int main() {
//	map<char, int>m{
//		{'d',1},
//		{'r',2},
//		{'a',3}
//	};
//	map<char, int>::iterator it = m.begin();
//	while (it != m.end()) {
//		//first:键值 second:实值
//		cout << it->first << "-" << it->second << " ";
//		++it;
//	}
//	cout << endl;
//
//	//map 并没有push,pop方法。
//	m['a'] = 4;  //当键值存在的时,就是通过键值修改实值
//	m['c'] = 5;  //如果键值不存在,添加元素
//
//	m.insert(pair<char, int>('u', 6));
//	it = m.begin();
//	while (it != m.end()) {
//		//first:键值 second:实值
//		cout << it->first << "-" << it->second << " ";
//		++it;
//	}
//	cout << endl;
//
//	//当键值存在的时候,插入失败,不会修改实值
//	//如果插入失败,返回的是键值已经存在的元素的迭代器
//	//如果插入成功,返回新插入元素的迭代器
//
//	pair<map<char,int>::iterator,bool> pr = m.insert(pair<char, int>('u', 7));
//
//	it = m.begin();
//	while (it != m.end()) {
//		//first:键值 second:实值
//		cout << it->first << "-" << it->second << " ";
//		++it;
//	}
//	cout << endl;
//
//	if (pr.second) {//插入成功
//		cout << "成功" << endl;
//	}
//	else {//插入失败
//		cout << "失败" << endl;
//	}
//
//	cout << pr.first->first << "-" << pr.first->second << endl;
//
//	//删除 erase
//	//按照位置删除
//	//it = m.begin(); 迭代器并不是随机访问迭代器
//	it = ++ ++m.begin();
//	it = m.erase(it);
//	for (pair<char, int>pr : m) {
//		cout << pr.first << "-" << pr.second << " ";
//	}
//	cout << endl;
//	cout << it->first << "-" << it->second << endl;
//
//	//按照键值删除
//	it = m.find('c'); //按照键值查找元素,如果键值存在,则返回对应元素的迭代器
//	it = m.erase(it);
//	for (pair<char, int>pr : m) {
//		cout << pr.first << "-" << pr.second << " ";
//	}
//	//it.first = '3'; 键值不允许修改
//	it->second = 30;
//
//	//m.count(); //按照键值统计元素的数量,可判断某个键值是否存在
//	cout << m.count('a') << "-------" << m.count('b') << endl;
//	for (pair<char, int>pr : m) {
//		cout << pr.first << "-" << pr.second << " ";
//	}
//	cout << endl;
//
//	m.upper_bound('b'); //返回大于传递键值的元素
//	cout << it->first << "-" << it->second << endl; //r-2
//
//	m.lower_bound('b');//键值不存在,只能取大于
//
//	return 0;
//}