#include"FoeList.h"
#include<typeinfo>
#include"FoeBig.h"
#include"FoeMid.h"
#include"FoeSma.h"
#include"../ConFig/Config.h"

FoeList::FoeList() {}
FoeList::~FoeList() {
	for (Foe* p : m_lstFoe)
	{
		if (p)
		{
			delete p;
		}
	}
	for (Foe* p : m_lstBoomFoe)
	{
		if (p)
		{
			delete p;
		}
	}
}
void FoeList::showAll() {
	for (Foe* p : m_lstFoe)
	{
		if (p)
		{
			p->show();
		}
	}
	for (Foe* p : m_lstBoomFoe)
	{
		if (p)
		{
			p->show();
		}
	}
}
void FoeList::moveAll() {
	list<Foe*>::iterator it = m_lstFoe.begin();
	while (it != m_lstFoe.end())
	{
		if (*it)//如果指针不为空
		{
			//运行期类型识别：PTTI,
			//typeid();
			//返回的是，包含类型信息常量。可以用于判断比较。

			//根据敌人飞机类型不同，传递不同的步长
			if (typeid(**it) == typeid(FoeBig)) {
				(*it)->move(3);
			}
			else if (typeid(**it) == typeid(FoeMid)) {
				(*it)->move(6);
			}
			else if (typeid(**it) == typeid(FoeSma)) {
				(*it)->move(8);
			}

			//判断是否出界
			if ((*it)->m_y >= BACK_H)
			{
				delete(*it);

				it = m_lstFoe.erase(it);
				continue;
			}

		}
		++it;
	}
}