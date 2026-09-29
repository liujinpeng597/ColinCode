#pragma once
#include <graphics.h>
#include "snake.h"
#include "apple.h"

class Game {
public:
    Game();
    ~Game(); // 析构函数：负责关闭图形窗口

    // 初始化游戏（窗口、图片、随机种子、蛇和苹果）
    void Init();

    // 启动游戏主循环
    void Run();

private:
    // 处理键盘输入
    void ProcessInput();

    // 更新游戏状态（蛇移动、吃苹果判断、死亡检测）
    void Update();

    // 渲染游戏画面（双缓冲绘图）
    void Render();

    // 游戏结束提示界面
    void ShowGameOver();

private:
    int m_width;         // 窗口宽度 (600)
    int m_height;        // 窗口高度 (600)
    bool m_isGameOver;   // 标志位：游戏是否结束
    int m_score;         // 当前得分
    int m_delayMs;       // 蛇移动的延迟毫秒数（控制速度，值越小越快）

    Snake m_snake;       // 蛇对象
    Apple m_apple;       // 苹果对象
    IMAGE m_bgImg;       // 背景图片 bg.bmp
};
