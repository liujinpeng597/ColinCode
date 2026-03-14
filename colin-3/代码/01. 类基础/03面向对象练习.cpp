//#include<iostream>
//#include<easyx.h>
//#include<conio.h>
//#include<Windows.h>
//#define DIRECT_UP 72
//#define DIRECT_DOWN 80
//#define DIRECT_LEFT 75
//#define DIRECT_RIGHT 77
//#define BASE_SPEED 2    
//#define MAX_SPEED 6     
//#define ACCELERATION 0.2 
//#define KEY_ESC 27
//#define JUMP_KEY 32     
//#define JUMP_POWER 12   
//#define GRAVITY 0.8     
//#define FLOOR_Y 300     
//#define FRAME_DELAY 16  
//using namespace std;
//
//class people
//{
//public:
//    IMAGE m_imgUp;
//    IMAGE m_imgDown;
//    IMAGE m_imgLeft;
//    IMAGE m_imgRight;
//
//    float m_x;
//    float m_y;
//    float m_originalY;
//    int m_direct;
//    float m_jumpSpeed;
//    float m_moveSpeed;
//    bool m_isJumping;
//    bool m_isMovingLeft;
//    bool m_isMovingRight;
//
//public:
//    people()
//    {
//        ::initgraph(600, 600);
//        ::setbkcolor(RGB(255, 255, 255));
//        ::cleardevice();
//
//        // 加载图片（请确保路径正确）
//        ::loadimage(&m_imgUp, L"./res/res/Up.bmp");
//        ::loadimage(&m_imgDown, L"./res/res/Down.bmp");
//        ::loadimage(&m_imgLeft, L"./res/res/Left.bmp");
//        ::loadimage(&m_imgRight, L"./res/res/Right.bmp");
//
//        m_x = 300;
//        m_y = FLOOR_Y;
//        m_originalY = FLOOR_Y;
//        m_direct = DIRECT_RIGHT;
//        m_jumpSpeed = 0;
//        m_moveSpeed = 0;
//        m_isJumping = false;
//        m_isMovingLeft = false;
//        m_isMovingRight = false;
//    }
//
//    ~people()
//    {
//        ::closegraph();
//    }
//
//public:
//    void show()
//    {
//        ::BeginBatchDraw();
//        ::cleardevice();
//
//        // 根据方向显示图片
//        if (m_direct == DIRECT_UP)
//            ::putimage((int)m_x, (int)m_y, &m_imgUp);
//        else if (m_direct == DIRECT_DOWN)
//            ::putimage((int)m_x, (int)m_y, &m_imgDown);
//        else if (m_direct == DIRECT_LEFT)
//            ::putimage((int)m_x, (int)m_y, &m_imgLeft);
//        else if (m_direct == DIRECT_RIGHT)
//            ::putimage((int)m_x, (int)m_y, &m_imgRight);
//
//        ::EndBatchDraw();
//    }
//
//    // 处理按键按下
//    void onKeyDown(int key)
//    {
//        if (key == DIRECT_LEFT)
//        {
//            m_isMovingLeft = true;
//            m_direct = DIRECT_LEFT;
//        }
//        else if (key == DIRECT_RIGHT)
//        {
//            m_isMovingRight = true;
//            m_direct = DIRECT_RIGHT;
//        }
//        else if (key == JUMP_KEY && !m_isJumping)
//        {
//            m_isJumping = true;
//            m_jumpSpeed = -JUMP_POWER;
//        }
//    }
//
//    // 处理按键释放
//    void onKeyUp(int key)
//    {
//        if (key == DIRECT_LEFT)
//            m_isMovingLeft = false;
//        else if (key == DIRECT_RIGHT)
//            m_isMovingRight = false;
//    }
//
//    // 更新移动状态
//    void updateMovement()
//    {
//        // 加速阶段
//        if (m_isMovingLeft)
//        {
//            m_moveSpeed -= ACCELERATION;
//            if (m_moveSpeed < -MAX_SPEED)
//                m_moveSpeed = -MAX_SPEED;
//        }
//        else if (m_isMovingRight)
//        {
//            m_moveSpeed += ACCELERATION;
//            if (m_moveSpeed > MAX_SPEED)
//                m_moveSpeed = MAX_SPEED;
//        }
//        // 减速阶段
//        else
//        {
//            if (m_moveSpeed > 0)
//            {
//                m_moveSpeed -= ACCELERATION * 1.5;
//                if (m_moveSpeed < 0) m_moveSpeed = 0;
//            }
//            else if (m_moveSpeed < 0)
//            {
//                m_moveSpeed += ACCELERATION * 1.5;
//                if (m_moveSpeed > 0) m_moveSpeed = 0;
//            }
//        }
//
//        // 应用水平移动
//        m_x += m_moveSpeed;
//        // 边界检查
//        if (m_x < 0) m_x = 0;
//        if (m_x > 540) m_x = 540;
//    }
//
//    // 优化跳跃曲线
//    void updateJump()
//    {
//        if (m_isJumping)
//        {
//            float gravityFactor = (m_jumpSpeed < 0) ? 0.8f : 1.2f;
//            m_jumpSpeed += GRAVITY * gravityFactor;
//
//            m_y += m_jumpSpeed;
//
//            if (m_y >= m_originalY)
//            {
//                m_y = m_originalY;
//                m_isJumping = false;
//                m_jumpSpeed = 0;
//            }
//        }
//    }
//
//    void run()
//    {
//        show();
//        while (1)
//        {
//            // 处理按键（支持持续按键）
//            if (_kbhit())
//            {
//                int key = ::_getch();
//
//                // 方向键的特殊处理（先收到0xE0前缀，再收到实际键值）
//                if (key == 0xE0)  // 方向键前缀码
//                {
//                    key = ::_getch();  // 获取实际方向键值
//
//                    // 持续按键检测
//                    if (key == DIRECT_LEFT || key == DIRECT_RIGHT)
//                    {
//                        onKeyDown(key);
//
//                        // 启动一个简单的定时器来处理按键释放
//                        // 实际项目中建议使用多线程或键盘钩子
//                        Sleep(10);
//                        if (!_kbhit())  // 如果没有继续按键，视为释放
//                        {
//                            onKeyUp(key);
//                        }
//                    }
//                }
//                else if (key == KEY_ESC)
//                {
//                    if (MessageBox(nullptr, L"确定退出吗?", L"提示", MB_OKCANCEL) == IDOK)
//                        break;
//                }
//                else if (key == JUMP_KEY)
//                {
//                    onKeyDown(key);
//                    onKeyUp(key);  // 跳跃键按一次即释放
//                }
//            }
//            else
//            {
//                // 没有按键时，重置移动状态
//                m_isMovingLeft = false;
//                m_isMovingRight = false;
//            }
//
//            // 每帧更新移动和跳跃状态
//            updateMovement();
//            updateJump();
//            show();
//            Sleep(FRAME_DELAY);
//        }
//    }
//};
//
//int main()
//{
//    people peo;
//    peo.run();
//    return 0;
//}
