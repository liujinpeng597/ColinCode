#pragma once
#include <graphics.h>
//定义移动方向
enum class Direction {
	RIGHT = 0,
	UP = 1,
	LEFT = 2,
	DOWN = 3
};

//蛇结点
struct SnakeNode {
	int x, y;
	SnakeNode* next;
	SnakeNode* prev;
	SnakeNode(int _x,int _y):x(_x),y(_y),next(nullptr){}
};

class Snake {
public:
	//构造函数
	Snake();
	//析构函数
	~Snake();
	//初始化
	void Init();
	//绘制整条蛇
	void Draw() const;
	//移动一步
	void Move();
	//吃苹果后边长
	void Grow();
	//改变方向 需要做防反
	void ChangeDirection(Direction newDir);
	//获取蛇头坐标
	int GetHeadX() const;
	int GetHeadY() const;
	//检查某个坐标是否与蛇身重和,苹果不能生在蛇身上
	bool IsOnBody(int x,int y,bool checkHead = true) const;
	//碰撞检测
	bool CheckCollisionWithWall(int windowWidth, int windowHeight) const;
	//是否咬到自己
	bool CheckCollisionWithSelf() const;
private:
	SnakeNode* m_head;//蛇头
	SnakeNode* m_tail;//蛇尾
	Direction m_dir;//当前移动方向
	int m_size;//像素大小

	IMAGE m_headImg[4];//存储四个方向的蛇头
	IMAGE m_bodyImg;//存储蛇身子

	void ClearBody();//清理链表内存函数
};