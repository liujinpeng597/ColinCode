#include "snake.h"
#include <tchar.h> // 包含 _T() 宏

Snake::Snake() {
   //初始化
    this->m_head = nullptr;
    this->m_tail = nullptr;
    //方向默认向右
    this->m_dir = Direction::RIGHT;
    //蛇像素大小
    this->m_size = 30;

}

Snake::~Snake() {
    ClearBody();
}

void Snake::ClearBody() {
    SnakeNode* cur = this->m_head;
    while (cur) {
        SnakeNode* nextNode = cur->next;
        delete cur;
        cur = nextNode;
    }
    //蛇头制空
    this->m_head = nullptr;
}

void Snake::Init() {
    //初始化一个长度为3的蛇
    //加载图片
    loadimage(&m_headImg[0],_T("she/head0.bmp"),m_size,m_size);
    loadimage(&m_headImg[1], _T("she/head1.bmp"), m_size, m_size);
    loadimage(&m_headImg[2], _T("she/head2.bmp"), m_size, m_size);
    loadimage(&m_headImg[3], _T("she/head3.bmp"), m_size, m_size);
    loadimage(&m_bodyImg, _T("she/body.bmp"), m_size, m_size);
    //初始化蛇身子
    //初始化方向
    m_dir = Direction::RIGHT;
    m_head = new SnakeNode(150,90);
    m_head->next = new SnakeNode(120, 90);
    m_head->next->next = new SnakeNode(90, 90);

    m_head->next->prev = m_head;
    m_head->next->next->prev = m_head->next;

    m_tail = m_head->next->next;
    m_tail->next = nullptr;

}

void Snake::ChangeDirection(Direction newDir) {
    //当前蛇向右 不能突然向左
    if (newDir == Direction::LEFT && m_dir == Direction::RIGHT)return;
    if (newDir == Direction::RIGHT && m_dir == Direction::LEFT)return;
    if (newDir == Direction::DOWN&& m_dir == Direction::UP)return;
    if (newDir == Direction::UP && m_dir == Direction::DOWN)return;
    m_dir = newDir;
}

void Snake::Grow() {
    //计算即将增长到某位置
    int newX = m_head->x;
    int newY = m_head->y;
    switch (m_dir) {
    case Direction::LEFT: newX -= m_size; break;
    case Direction::RIGHT:newX += m_size; break;
    case Direction::DOWN:newY += m_size; break;
    case Direction::UP:newY -= m_size; break;
    }
    //新坐标创建新头
    SnakeNode* newHead = new SnakeNode(newX, newY);
    //头插
    newHead->next = m_head;
    m_head->prev = newHead;
    m_head = newHead;
}

void Snake::Move() {
    //头增
    Grow();
    //尾删
    m_tail = m_tail->prev;
    delete m_tail->next;
    m_tail->next = nullptr;

}

void Snake::Draw() const {
    //渲染 putimage
    //绘制蛇头
    //得到蛇头方向
    int dirIndex = static_cast<int>(m_dir);
    putimage(m_head->x, m_head->y, &m_headImg[dirIndex]);
    //绘制蛇身
    SnakeNode* cur = m_head->next;
    while (cur) {
        putimage(cur->x, cur->y, &m_bodyImg);
        cur = cur->next;
    }
}

int Snake::GetHeadX() const {
    return m_head->x;
}

int Snake::GetHeadY() const {
    return m_head->y;
}

bool Snake::IsOnBody(int x, int y, bool checkHead) const {
    SnakeNode* cur = checkHead ? m_head : m_head->next;
    while (cur) {
        if (x == cur->x && y == cur->y)return true;
        cur = cur->next;
    }
    return false;
}

bool Snake::CheckCollisionWithWall(int windowWidth, int windowHeight) const {
    return (m_head->x >= windowWidth - 30
        || m_head->x < 30
        || m_head->y < 30
        || m_head->y >= windowHeight - 30);
}


bool Snake::CheckCollisionWithSelf() const {
    return IsOnBody(m_head->x, m_head->y, false);
}
