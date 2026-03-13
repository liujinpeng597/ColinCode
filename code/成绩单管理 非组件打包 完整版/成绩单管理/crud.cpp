#define  _CRT_SECURE_NO_WARNINGS
#include "crud.h"
#include <conio.h>
#define SHOW_TABLE_FIELD printf("\n%-8s%-10s%6s%6s%6s\n", "姓名", "学号", "数学", "英语", "语文");
#define SHOW_TABLE_ONE_LINE(POINTER) printf("%-8s%-10s%6d%6d%6d\n", POINTER->name, POINTER->stuNum,POINTER->math, POINTER->english, POINTER->chinese);
/*成绩单 列表*/
PLinkedList listScore;

void initData()
{
	listScore = createLinkedList();
	//加载文件的数据 到 链表
	FILE* p = fopen("./data.db", "rb");
	if (p != NULL)
	{
		P_Score ps = (P_Score)malloc(sizeof(SCORE));
		while (ps && fread(ps, sizeof(SCORE), 1, p) > 0)
		{
			add(listScore, ps);
			ps = (P_Score)malloc(sizeof(SCORE));
		}
		free(ps);
		fclose(p);
		p = NULL;
	}
}

P_Score createScore(const char* name, const char* stuNum,
	int math, int english, int chinese)
{
	P_Score p = (P_Score)malloc(sizeof(SCORE));
	strcpy(p->name, name);
	strcpy(p->stuNum, stuNum);
	p->math = math;
	p->english = english;
	p->chinese = chinese;
	p->del = 0;
	return p;
}
P_Score inputNewScore()
{
	//键盘输入一组数据
	char name[28];//姓名
	char stuNum[20];//学号
	int math;
	int english;
	int chinese;
	printf("\n请输入姓名：");
	gets_s(name, 28);
	trimAll(name);
	printf("请输入学号：");
	gets_s(stuNum, 20);
	trimAll(stuNum);

	printf("请输入数学成绩：");
	scanf_s("%d", &math);
	printf("请输入英语成绩：");
	scanf_s("%d", &english);
	printf("请输入语文成绩：");
	scanf_s("%d", &chinese);
	//清除键盘缓冲区
	setbuf(stdin, NULL);
	return createScore(name, stuNum, math, english, chinese);
}

void appendToFile(P_Score ps)
{
	FILE* p = fopen("./data.db", "ab");
	if (p != NULL)
	{
		//二进制文件的写入
		fwrite(ps, sizeof(SCORE), 1, p);
		fclose(p);
		p = NULL;
	}
}

void addNewScore()
{
	P_Score newScore = inputNewScore();
	printf("是否保存新数据<Y/N>?");
	char yes = getchar();
	//清除键盘缓冲区
	setbuf(stdin, NULL);
	if (yes == 'Y' || yes == 'y')
	{
		add(listScore, newScore);
		appendToFile(newScore);
		printf("保存成功\n");
	}
	else
	{
		free(newScore);
		newScore = NULL;
	}
}

void updateScore()
{

	int index;
	P_Score ps = queryOneScore(&index);
	if (ps == NULL)
	{
		printf("没有此学生的数据\n");
		return;
	}
	//展示
	SHOW_TABLE_FIELD
		SHOW_TABLE_ONE_LINE(ps)
		setbuf(stdin, NULL);
	printf("\n*****准备更新学号为：%s的数据*****\n", ps->stuNum);
	printf("** 0:更新学号：\n");
	printf("** 1:更新姓名：\n");
	printf("** 2:更新数学：\n");
	printf("** 3:更新英语：\n");
	printf("** 4:更新语文：\n");
	printf("** y:保存更新：\n");
	printf("** n:取消更新：\n");
	char updateMenuID;
	SCORE temp;
	memcpy(&temp, ps, sizeof(SCORE));

	do
	{
		printf("更新操作选项/>");
		updateMenuID = _getche();
		switch (updateMenuID)
		{
		case '0':
			printf("新的学号：");
			gets_s(temp.stuNum, 20);
			break;
		case '1':
			printf("新的姓名：");
			gets_s(temp.name, 28);
			break;
		case '2':
			printf("新的数学成绩：");
			scanf_s("%d", &temp.math);
			break;
		case '3':
			printf("新的英语成绩：");
			scanf_s("%d", &temp.english);
			break;
		case '4':
			printf("新的语文成绩：");
			scanf_s("%d", &temp.chinese);
			break;
		case 'y':
		case 'Y':
			memcpy(ps, &temp, sizeof(SCORE));
			//保存到文件
			updateToFile(ps, index);
			printf("数据更新保存成功\n");
			return;
		}
		setbuf(stdin, NULL);
	} while (!(updateMenuID == 'n' || updateMenuID == 'N'));
}

void deleteScore()
{
	int index;
	P_Score ps = queryOneScore(&index);
	if (ps == NULL)
	{
		printf("没有此学生的数据\n");
		return;
	}
	//展示
	SHOW_TABLE_FIELD
		SHOW_TABLE_ONE_LINE(ps)
		setbuf(stdin, NULL);
	printf("确认删除吗？<Y/N>");
	char yes = getchar();
	setbuf(stdin, NULL);
	if (yes == 'Y' || yes == 'y')
	{
		ps->del = 1;//数据做了逻辑删除
		//保存到文件
		updateToFile(ps, index);
	}
}

P_Score queryOneScore(int* const index)
{
	printf("请输入学号：");
	char stuNum[20];
	gets_s(stuNum, 20);

	iterator(listScore);
	*index = -1;
	int i = 0;
	while (hasNext(listScore))
	{
		P_Score p = (P_Score)next(listScore);
		if (strcmp(p->stuNum, stuNum) == 0)
		{
			*index = i;
			return p;
		}
		i++;
	}
	return NULL;
}

void updateToFile(P_Score p, int index)
{
	FILE* file = fopen("./data.db", "r+b");
	if (file)
	{
		fseek(file, index * sizeof(SCORE), SEEK_SET);
		fwrite(p, sizeof(SCORE), 1, file);
		fclose(file);
	}
}

void showAllScore()
{
	//printf("\n姓名 学号 数学 英语 语文\n");
	SHOW_TABLE_FIELD
		iterator(listScore);
	while (hasNext(listScore))
	{
		P_Score p = (P_Score)next(listScore);
		if (p->del == 0)
		{
			SHOW_TABLE_ONE_LINE(p)
		}
	}
}
