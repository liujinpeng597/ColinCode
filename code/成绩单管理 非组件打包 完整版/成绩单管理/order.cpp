#include "order.h"
#include "loadcom.h"
#include "crud.h"
int ruleStuNumOrder(void* s1, void* s2)
{
	P_Score ps1 = (P_Score)s1;
	P_Score ps2 = (P_Score)s2;
	return  strcmp(ps1->stuNum, ps2->stuNum);
}
void stuNumOrder()
{
	sort__(listScore, ruleStuNumOrder);
	showAllScore();
}
int ruleMathOrder(void* s1, void* s2)
{
	P_Score ps1 = (P_Score)s1;
	P_Score ps2 = (P_Score)s2;
	if (ps2->math == ps1->math)
	{
		return strcmp(ps1->stuNum, ps2->stuNum);
	}
	return ps2->math - ps1->math;
}

void mathOrder()
{
	sort__(listScore, ruleMathOrder);
	showAllScore();
}

int ruleEnglishOrder(void* s1, void* s2)
{
	P_Score ps1 = (P_Score)s1;
	P_Score ps2 = (P_Score)s2;
	if (ps2->english == ps1->english)
	{
		return strcmp(ps1->stuNum, ps2->stuNum);
	}
	return ps2->english - ps1->english;
}

void englishOrder()
{
	sort__(listScore, ruleEnglishOrder);
	showAllScore();
}

int ruleChineseOrder(void* s1, void* s2)
{
	P_Score ps1 = (P_Score)s1;
	P_Score ps2 = (P_Score)s2;
	if (ps2->chinese == ps1->chinese)
	{
		return strcmp(ps1->stuNum, ps2->stuNum);
	}
	return ps2->chinese - ps1->chinese;
}

void chineseOrder()
{
	sort__(listScore, ruleChineseOrder);
	showAllScore();
}

int ruleAllScoreOrder(void* s1, void* s2)
{
	P_Score ps1 = (P_Score)s1;
	P_Score ps2 = (P_Score)s2;
	int s1Sum = ps1->math + ps1->english + ps1->chinese;
	int s2Sum = ps2->math + ps2->english + ps2->chinese;

	if (s1Sum == s2Sum)
	{
		return strcmp(ps1->stuNum, ps2->stuNum);
	}
	return s2Sum - s1Sum;
}

void allScoreOrder()
{
	sort__(listScore, ruleAllScoreOrder);
	showAllScore();
}
