//#include<iostream>
//using namespace std;
////vector 动态数组(可扩展空间的数组,不固定的,动态的)
//
//class DynamicArray {
//private:
//	int* m_parr; //指向底层的数组
//	int m_len; //当前长度
//	int m_capacity; //最大容量
//public:
//	//构造函数
//	DynamicArray(int len = 0) :m_len(len), m_capacity(len), m_parr(nullptr) {
//		if (len > 0) {
//			m_parr = new int[len](); //指定默认初始化值,整形为0
//		}
//	}
//	//析构函数
//	~DynamicArray() {
//		if (m_parr) {
//			delete[] m_parr;
//			m_parr = nullptr;
//		}
//		m_len = m_capacity = 0;
//	}
//	//尾部删除(效率更高)
//	void pop_back() {
//		if (m_len > 0) {
//			--m_len;
//		}
//	}
//	//尾添加
//	void push_back(int v) {
//		if (m_len >= m_capacity) {//满了需要扩容
//			//按照1.5倍扩容
//			int tmpCapa = m_capacity * 3 / 2;
//			m_capacity = m_capacity + 1 > tmpCapa ? m_capacity + 1 : tmpCapa;//两者比较取其大 
//
//			//申请新的大数组
//			int* tmpArray = new int[m_capacity]();
//			for (int i = 0; i < m_len; i++) {
//				tmpArray[i] = m_parr[i]; //遍历拷贝旧元素到新空间
//			}
//			tmpArray[m_len++] = v; //在结尾添加新元素
//
//			delete[] m_parr;//释放旧空间
//			m_parr = tmpArray;//接管新的空间
//		}
//		else {//没有满
//			m_parr[m_len++] = v;
//		}
//	}
//	//遍历
//	void show(){
//		if (m_len <= 0) {
//			cout << "动态数组为空" << endl;
//		}
//		else {
//			for (int i = 0; i < m_len; i++) {
//				cout << m_parr[i] << " ";
//			}
//			cout << endl;
//		}
//	}
//	//是否为空
//	bool isEmpty() {
//		return m_len == 0 ? true : false;
//	}
//	//获取长度
//	int getLen() {
//		return m_len;
//	}
//	//获取容量
//	int getCapacity() {
//		return m_capacity;
//	}
//	//首元素迭代器
//	int* begin(){
//		return m_parr; //首元素地址
//	}
//	//尾元素迭代器
//	int* end() {
//		return &m_parr[m_len];//有效尾元素的下一个元素的地址
//	}
//};
//
//int main() {
//	DynamicArray a1;
//	cout << a1.getLen() << "," << a1.getCapacity() << endl;
//	a1.show();
//	//添加元素
//	for (int i = 1; i < 8; i++) {
//		a1.push_back(i);
//	}
//	//范围for循环遍历需要迭代器
//	for (int v : a1) {
//		cout << v << " ";
//	}
//
//	return 0;
//}