//#include "snake.h"
//#include <tchar.h> // 包含 _T() 宏
//
//Snake::Snake() {
//    m_head = nullptr;
//    m_dir = Direction::RIGHT; // 默认朝右移动
//    m_size = 30;              // 对应 30×30 的像素网格
//}
//
//Snake::~Snake() {
//    ClearBody(); // 防止内存泄漏
//}
//
//void Snake::ClearBody() {
//    SnakeNode* curr = m_head;
//    while (curr != nullptr) {
//        SnakeNode* nextNode = curr->next;
//        delete curr;
//        curr = nextNode;
//    }
//    m_head = nullptr;
//}
//
//void Snake::Init() {
//    ClearBody(); // 如果是重开游戏，先清空旧的蛇身
//
//    // 1. 加载图片素材 (规格强行缩放到 30x30)
//    // 假设 head0=上, head1=下, head2=左, head3=右
//    loadimage(&m_headImg[0], _T("she/head0.bmp"), m_size, m_size);
//    loadimage(&m_headImg[1], _T("she/head1.bmp"), m_size, m_size);
//    loadimage(&m_headImg[2], _T("she/head2.bmp"), m_size, m_size);
//    loadimage(&m_headImg[3], _T("she/head3.bmp"), m_size, m_size);
//    loadimage(&m_bodyImg, _T("she/body.bmp"), m_size, m_size);
//
//    // 2. 初始化初始长度为 3 节的蛇（头插法构建：蛇头在 (150, 90)，蛇身依次往左）
//    m_dir = Direction::RIGHT;
//    m_head = new SnakeNode(150, 90);
//    m_head->next = new SnakeNode(120, 90);
//    m_head->next->next = new SnakeNode(90, 90);
//}
//
//void Snake::ChangeDirection(Direction newDir) {
//    // 防止 180 度直接回头（比如正在向右走时，不能突然按左）
//    if (m_dir == Direction::UP && newDir == Direction::DOWN)  return;
//    if (m_dir == Direction::DOWN && newDir == Direction::UP)    return;
//    if (m_dir == Direction::LEFT && newDir == Direction::RIGHT) return;
//    if (m_dir == Direction::RIGHT && newDir == Direction::LEFT)  return;
//
//    m_dir = newDir;
//}
//
//void Snake::Grow() {
//    // 1. 根据当前移动方向计算新蛇头的坐标
//    int newX = m_head->x;
//    int newY = m_head->y 
//
//    switch (m_dir) {
//    case Direction::UP:    newY -= m_size; break;
//    case Direction::DOWN:  newY += m_size; break;
//    case Direction::LEFT:  newX -= m_size; break;
//    case Direction::RIGHT: newX += m_size; break;
//    }
//
//    // 2. 链表头插法：创建新节点，成为新的蛇头
//    SnakeNode* newHead = new SnakeNode(newX, newY);
//    newHead->next = m_head;
//    m_head = newHead;
//}
//
//void Snake::Move() {
//    // 移动 = 先长长一节，再删除尾巴
//    Grow();
//
//    // 遍历链表找到倒数第二个节点
//    SnakeNode* curr = m_head;
//    while (curr->next != nullptr && curr->next->next != nullptr) {
//        curr = curr->next;
//    }
//
//    // 删除最后一个尾节点
//    if (curr->next != nullptr) {
//        delete curr->next;
//        curr->next = nullptr;
//    }
//}
//
//void Snake::Draw() const {
//    if (m_head == nullptr) return;
//
//    // 1. 绘制蛇头（根据当前方向选择对应的图片）
//    int dirIndex = static_cast<int>(m_dir);
//    putimage(m_head->x, m_head->y, &m_headImg[dirIndex]);
//
//    // 2. 遍历链表，绘制所有的蛇身
//    SnakeNode* curr = m_head->next;
//    while (curr != nullptr) {
//        putimage(curr->x, curr->y, &m_bodyImg);
//        curr = curr->next;
//    }
//}
//
//int Snake::GetHeadX() const {
//    return m_head ? m_head->x : 0;
//}
//
//int Snake::GetHeadY() const {
//    return m_head ? m_head->y : 0;
//}
//
//bool Snake::IsOnBody(int x, int y, bool checkHead) const {
//    SnakeNode* curr = checkHead ? m_head : m_head->next;
//    while (curr != nullptr) {
//        if (curr->x == x && curr->y == y) {
//            return true;
//        }
//        curr = curr->next;
//    }
//    return false;
//}
//
//bool Snake::CheckCollisionWithWall(int windowWidth, int windowHeight) const {
//    if (m_head == nullptr) return false;
//
//    // 你的墙壁刚好是 1 个网格的厚度，也就是 30 像素。
//    // 所以安全的黄色区域是 x 在 [30, 570) 之间，y 在 [30, 570) 之间。
//    // 只要小于 30（撞到左/上墙），或者大于等于 570（撞到右/下墙），都算撞墙！
//
//    return (m_head->x < 30 ||                       // 撞到左边的墙
//        m_head->x >= windowWidth - 30 ||        // 撞到右边的墙
//        m_head->y < 30 ||                       // 撞到上面的墙
//        m_head->y >= windowHeight - 30);        // 撞到下面的墙
//}
//
//
//bool Snake::CheckCollisionWithSelf() const {
//    if (m_head == nullptr) return false;
//    // 检查蛇头是否与后续的蛇身节点碰撞
//    return IsOnBody(m_head->x, m_head->y, false);
//}
