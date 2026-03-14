#include<iostream>
using namespace std;

void OpenRefrigerator() {
	cout << "用手抓住冰箱门把手" << endl;
	cout << "缓慢打开门" << endl;
	cout << "拉到一定大的角度" << endl;
}


//参数1： 指向大象的指针，参数2：冰箱的高度，参数3：大象的高度
void PushElephant(int* pEle, int& heightRefrig, int& heightEle) {
	cout << "找到冰箱的最大格子" << endl;
	if (heightRefrig < heightEle) {    //比较高度，如果冰箱高度小于大象高度，则压缩大象
		cout << "压缩一下大象" << endl;
		heightEle = 5;   //大象高度压缩到5
	}
	pEle = &heightEle;   //冰箱中指向大象的指针，指向了大象
	cout << "大象放到冰箱里" << endl;
}


void CloseRefrigerator() {
	cout << "开始推动冰箱门" << endl;
	cout << "继续推动冰箱门" << endl;
	cout << "冰箱门严丝合缝" << endl;
}





int main() {
	int heightEle = 10;   //大象的高度

	int heightRefrig = 10;//冰箱的高度
	int* pEle = nullptr;//冰箱装的东西

	//--------开始打开冰箱--.
	OpenRefrigerator();
	//结束打开冰箱
	//--------开始装大象--.
	PushElephant(pEle, heightRefrig, heightEle);
	//结束装大象- ===
	//--开始关闭冰箱I
	CloseRefrigerator();
	//结束关闭冰箱





	return 0;
}