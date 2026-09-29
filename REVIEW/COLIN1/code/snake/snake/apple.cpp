#include "apple.h"
#include <stdlib.h>

//构造函数 苹果
Apple::Apple() {
	m_size = 30;
	m_x = -100;
	m_y = -100;
}

//初始化函数
void Apple::Init() {
	//加载图片
	loadimage(&m_img,_T("she/apple.bmp"),m_size,m_size);
}

void Apple::Generate(int windowWidth, int windowHeight) {
	//计算出每行每列都有多少格子
	int cols = windowWidth / m_size - 2;
	int rows = windowHeight / m_size - 2;

	//rand() % cols能在格子范围内随机生成 *m_size 苹果实际位置
	m_x = (rand() % cols + 1) * m_size;
	m_y = (rand() % rows + 1) * m_size;
}

//向屏幕上随机生成的位置绘制苹果
void Apple::Draw() const {
	putimage(m_x, m_y, &m_img);
}

//得到X坐标
int Apple::GetX() const {
	return m_x;
}

//得到Y坐标
int Apple::GetY() const {
	return m_y;
}

