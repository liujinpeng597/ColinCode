#include "login.h"
#include <stdio.h>
#include <conio.h>
#include"loadcom.h"
#include"crud.h"
#include"order.h"
#include "data_manage.h"
void loginInput(char user[], char password[])
{
	printf("输入账号：");
	gets_s(user, 20);
	printf("输入密码：");
	getMarkcode(password, 20);
	//去掉首尾部空格
	rightTrim(leftTrim(user));
}
char* getMarkcode(char* password, size_t size)
{
	char pwd;
	//pwd = getch();
	//putchar('*');
	int count = 0;
	do
	{
		pwd = _getch();
		if (pwd == '\b')//删除上一个
		{
			if (count >= 1)
			{
				count--;
				putchar('\b');
				putchar(' ');
				putchar('\b');
			}
		}
		else if (pwd == '\r')//结束密码输入
		{
			break;
		}
		else
		{
			password[count++] = pwd;
			putchar('*');
		}
	} while (count < size - 1);
	password[count] = '\0';
	return password;
}
int login(char user[], char password[])
{
	if (strcmp(user, "colin") == 0
		&& strcmp(password, "123456") == 0)
	{
		return LOGIN_SUCCESS;
	}
	return LOGIN_ERR;
}

void showTeacherMenu()
{
	printf("\n-------数据管理---------\n");
	printf("*   r.显示所有学生  *\n");
	printf("*   a.增加学生成绩  *\n");
	printf("*   u.修改学生成绩  *\n");
	printf("*   d.删除学生成绩  *\n");
	printf("\n-----综合排序---------\n");
	printf("*   m.数学排名  *\n");
	printf("*   e.英语排名  *\n");
	printf("*   c.语文排名  *\n");
	printf("*   s.总成绩排名  *\n");
	printf("\n-----数据维护---------\n");
	printf("*   i.导入数据  *\n");
	printf("*   p.导出数据  *\n");
	printf("-------------------\n");
	printf("*   q.退出系统  *\n");
	printf("-------------------\n");
}
void optTeacherMenu()
{
	char menuID;//menu菜单 ID编号
	do
	{
		printf("指令/>");
		menuID = _getche();
		switch (menuID)
		{
		case 'r':
		case 'R':
			printf("*****按学号顺序显示*****\n");
			stuNumOrder();
			break;
		case 'a':
		case 'A':
			printf("*****增加新数据*****\n");
			addNewScore();
			break;
		case 'u':
		case 'U':
			printf("*****修改数据*****\n");
			updateScore();
			break;
		case 'd':
		case 'D':
			printf("*****删除数据*****\n");
			deleteScore();
			break;
		case 'm':
		case 'M':
			printf("*****数学排名*****\n");
			mathOrder();
			break;
		case 'e':
		case 'E':
			printf("*****英语排名*****\n");
			englishOrder();
			break;
		case 'c':
		case 'C':
			printf("*****语文排名*****\n");
			chineseOrder();
			break;
		case 's':
		case 'S':
			printf("*****总成绩排名*****\n");
			allScoreOrder();
			break;
		case 'i':
		case 'I':
			printf("*****导入数据*****\n");
			showImportUI();
			break;
		case 'p':
		case 'P':
			printf("*****导出数据ing*****\n");
			showExportUI();
			break;
		case 'q':
		case 'Q':
			quit();
			break;
		default:
			printf("无此指令\n");
			showTeacherMenu();
			break;
		}
	} while (!(menuID == 'Q' || menuID == 'q'));
}
void quit()
{
	printf("\n正在退出系统\n");
	iterator(listScore);
	while (hasNext(listScore))
	{
		free(next(listScore));
	}
	clear(listScore);
	free(listScore);
}
