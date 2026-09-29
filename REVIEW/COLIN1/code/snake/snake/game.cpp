#include "game.h"
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <tchar.h>
#include <stdio.h>

Game::Game() {
    // 600x600 刚好可以容纳 20x20 个 30 像素大小的网格
    m_width = 600;
    m_height = 600;
    m_isGameOver = false;
    m_score = 0;
    m_delayMs = 150;    // 刷新间隔为 150 毫秒（速度适中）
}

Game::~Game() {
    closegraph(); // 退出时关闭 EasyX 窗口
}

void Game::Init() {
    // 1. 设置随机种子
    srand((unsigned int)time(NULL));

    // 2. 初始化窗口
    initgraph(m_width, m_height);

    // 3. 加载背景图
    loadimage(&m_bgImg, _T("she/bg.bmp"), m_width, m_height);

    // 4. 初始化蛇和苹果的资源
    m_snake.Init();
    m_apple.Init();

    // 5. 生成第一个苹果（确保生成的位置不踩在蛇身上）
    do {
        m_apple.Generate(m_width, m_height);
    } while (m_snake.IsOnBody(m_apple.GetX(), m_apple.GetY()));

    m_isGameOver = false;
    m_score = 0;
}

void Game::Run() {
    Init();

    // 记录上一次更新游戏逻辑的时间
    DWORD lastTime = GetTickCount();

    // 游戏主循环
    while (!m_isGameOver) {
        // 1. 实时捕获键盘输入
        ProcessInput();

        // 2. 控制蛇的移动速率：每隔 m_delayMs 毫秒才移动一步
        DWORD currentTime = GetTickCount();
        if (currentTime - lastTime >= (DWORD)m_delayMs) {
            Update();

            if (m_isGameOver) {
                break;
            }

            lastTime = currentTime;
        }

        // 3. 渲染画面
        Render();

        // 稍微休眠，降低 CPU 占用率
        Sleep(10);
    }

    // 循环结束后显示 Game Over
    ShowGameOver();
}

void Game::ProcessInput() {
    // 使用 EasyX 非阻塞消息响应键盘
    ExMessage msg;
    while (peekmessage(&msg, EX_KEY)) {
        if (msg.message == WM_KEYDOWN) {
            switch (msg.vkcode) {
            case VK_UP:
            case 'W':
            case 'w':
                m_snake.ChangeDirection(Direction::UP);
                break;
            case VK_DOWN:
            case 'S':
            case 's':
                m_snake.ChangeDirection(Direction::DOWN);
                break;
            case VK_LEFT:
            case 'A':
            case 'a':
                m_snake.ChangeDirection(Direction::LEFT);
                break;
            case VK_RIGHT:
            case 'D':
            case 'd':
                m_snake.ChangeDirection(Direction::RIGHT);
                break;
            }
        }
    }
}

void Game::Update() {
    // 1. 预测蛇头移动一步后的新位置
    int nextX = m_snake.GetHeadX();
    int nextY = m_snake.GetHeadY();
    int size = 30; // 网格大小

    // 注意：这里方向判断需要与 snake.cpp 一致
    // 假设蛇头按照当前方向向前推一步
    // (由于方向放在 Snake 内部，我们直接检查移动后是否吃苹果，或者通过比较蛇头与苹果位置)

    // 最优雅的逻辑：
    // 我们判断：如果蛇头【刚好在苹果的位置】，说明刚刚那一步踩上了苹果！
    // 但为了让蛇平滑增长，我们计算蛇头按当前方向走一步是否会遇到苹果：

    // 简便方法：先让蛇正常移动或增长
    // 我们检查：如果蛇头【移动前的位置 + 一步】等于苹果的位置：
    // 在这里我们直接让蛇做位置检测：

    // 逻辑判定：
    // 如果蛇移动后的新位置正好是苹果，那么调用 Grow()，否则调用 Move()
    // 为了知道新位置，我们可以比较蛇头与苹果：
    bool willEatApple = false;

    // 简化的判断：直接移动后再看，或者提前预测
    // 这里采用提前预测：
    // 如果蛇当前正朝苹果走，并且只差 1 格距离：
    // 更简单的写法：直接在 Snake 增加一个预测函数，或者直接在下面做简单距离计算

    // 这里我们直接用 Snake 的移动逻辑：
    // 如果 (蛇头位置 == 苹果位置)，说明刚才一步吃到了苹果
    // 重新写这部分逻辑会非常直观：

    // 我们先让蛇正常 Move()：
    m_snake.Move();

    // 移动后检查蛇头是否和苹果重合
    if (m_snake.GetHeadX() == m_apple.GetX() && m_snake.GetHeadY() == m_apple.GetY()) {
        // 吃到了！让蛇增长一节（相当于补充刚才删掉的尾巴）
        m_snake.Grow();
        m_score += 10;   // 加 10 分

        // 重新生成新的苹果（保证不在蛇身上）
        do {
            m_apple.Generate(m_width, m_height);
        } while (m_snake.IsOnBody(m_apple.GetX(), m_apple.GetY()));
    }

    // 2. 碰撞检测：检查是否撞墙或咬到自己
    if (m_snake.CheckCollisionWithWall(m_width, m_height) || m_snake.CheckCollisionWithSelf()) {
        m_isGameOver = true;
    }
}

void Game::Render() {
    // 开启双缓冲绘图，彻底解决画面闪烁问题！
    BeginBatchDraw();

    // 1. 画背景图片
    putimage(0, 0, &m_bgImg);

    // 2. 画苹果
    m_apple.Draw();

    // 3. 画蛇
    m_snake.Draw();

    // 4. 绘制得分文字
    TCHAR scoreStr[32];
    _stprintf_s(scoreStr, _T("Score: %d"), m_score);
    settextcolor(BLACK);
    setbkmode(TRANSPARENT);
    settextstyle(20, 0, _T("Consolas"));
    outtextxy(40, 40, scoreStr);

    // 刷新缓冲区，把画面一次性贴出来
    EndBatchDraw();
}

void Game::ShowGameOver() {
    // 提示 Game Over 文字
    settextcolor(RED);
    settextstyle(40, 0, _T("黑体"));
    outtextxy(m_width / 2 - 100, m_height / 2 - 40, _T("GAME OVER"));

    TCHAR finalScore[64];
    _stprintf_s(finalScore, _T("Final Score: %d"), m_score);
    settextstyle(24, 0, _T("Consolas"));
    outtextxy(m_width / 2 - 80, m_height / 2 + 10, finalScore);

    // 等待玩家按任意键退出
    _getch();
}
