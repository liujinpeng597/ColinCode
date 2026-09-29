#pragma once
#include <graphics.h>
class Apple {
public:
	//构造函数,初始化苹果
	Apple();

	void Init();

	//随机生成苹果的位置
	//传入窗口的宽度和高度,确保苹果生成在屏幕内部并对其网格
	void Generate(int windowWidth, int windowHeight);

	//绘制苹果
	void Draw() const;

	//获取苹果坐标
	int GetX() const;
	int GetY() const;
private:
	int m_x;
	int m_y;
	int m_size;//苹果占的格子大小
	IMAGE m_img;//存储苹果图标
};