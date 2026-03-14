//#include<iostream>
//#include<vector>
//using namespace std;
//
//void show(vector<int>vec) {
//	for (int v : vec) {
//		cout << v << " ";
//	}
//	cout << endl;
//}
//
//int main() {
//	//初始化vector
//	//默认值为0
//	vector<int>vec(3/*使用量*/, 7/*初始化赋值*/);
//	cout << "vec.size()" << vec.size() << "," << "vec.capacity()" << vec.capacity() << endl;
//	show(vec);
//
//	//初始化列表方式初始化
//	vector<int>vec2{ 5,1,2,0 };
//	show(vec2);
//
//	//用数组初始化vector容器
//	int arr[5] = { 1,2,3,4,5 };
//	vector<int>vec3(arr+1,arr+4);
//	show(vec3);
//	vec3.push_back(0);
//
//	vector<int>::iterator it = vec3.begin();
//	while (it != vec3.end()) {
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	vec3.pop_back();
//	cout << "vec3.size():" << vec3.size() << " " << "vec3.capacity():" << vec3.capacity() << endl;
//	
//	it = vec3.begin() + 2; //vector迭代器支持随机访问 是随机访问类型的迭代器
//	it = vec3.insert(it,10);
//	show(vec3);
//	cout << "*it:"<< *it << endl;
//
//	it = vec3.begin() + 1;
//	it = vec3.erase(it); //返回删除的下一个 如果不是end则是有效的
//	show(vec3);
//	cout << "*it:" << *it << endl;
//	//删除后会失效,指向的也是下一个元素,系统自动把迭代器设置为失效
//
//	//有元素位置的移动(没有扩容的情况下)。
//	vector<int>v4{ 1,2,3,4,5,6 };
//	vector<int>::iterator it1 = v4.begin() + 1;
//	vector<int>::iterator it2 = v4.begin() + 4;
//	
//	v4.erase(v4.begin() + 3);
//	cout << *it << endl;
//	//cout<<*it2<<endl;  //会失效
//
//	//扩容都会失效
//	vector<int>v5{ 1,2,3,4,5,6 };
//	it1 = v5.begin() + 1;
//	it2 = v5.begin() + 4;
//	cout << *it1 << "," << *it2 << endl;
//	v5.push_back(70);
//	//cout<<*it1<<endl;
//	//cout<<*it2<<endl;
//
//	cout << v5.size() << "," << v5.capacity() << endl;
//	v5.clear();
//	cout << v5.size() << "," << v5.capacity() << endl;
//
//	v5.resize(4/*重新指定使用量大小，如果没有超过容量，则不扩容*/, 10/*如果增加使用量,元素默认为10*/);
//	cout << v5.size() << "," << v5.capacity() << endl;
//	show(v5);
//
//	//如何缩容
//	v5.shrink_to_fit();//减少到与使用量相等
//	cout << v5.size();
//
//	vector<int>(3).swap(v5);//交换容量和使用量
//	cout << v5.size() << "," << v5.capacity() << endl;
//	return 0;
//}