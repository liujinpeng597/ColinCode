#include"GunnerList.h"
#include"../Config/Config.h" 

GunnerList::GunnerList(){}
GunnerList::~GunnerList() {
	for (Gunner* &p : m_lstGun) {
		if (p) {
			delete p;
			p = nullptr;
		}
	}
}
void GunnerList::showAll() {
	for (Gunner*& p : m_lstGun) {
		if (p) {
			p->show();
		}
	}
}
void GunnerList::moveAll() {
	//遍历每一个炮弹判断是否出界 出界删除
	list<Gunner*>::iterator it = m_lstGun.begin();
	while (it != m_lstGun.end()) {
		if (*it) {
			(*it)->move();

			//判断是否出界
			if ((*it)->m_y <= -GUNNER_H) {
				delete(*it);
				it = m_lstGun.erase(it); //删除迭代器指向的节点 ，默认会失效 可以接一下返回值（删除节点的下一个结点）
			}
		}
		++it; // p = p->next;移动到下一个结点
	}
}