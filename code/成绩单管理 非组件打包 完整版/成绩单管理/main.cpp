#include <stdio.h>
#include"login.h"
#include"crud.h"
int main()
{
	printf("*******欢迎使用成绩单管理系统********\n");
	char user[20];
	char pwd[20];
	loginInput(user, pwd);
	switch (login(user, pwd))
	{
	case LOGIN_SUCCESS:
		showTeacherMenu();
		initData();
		optTeacherMenu();
		break;
	case LOGIN_ERR:
		printf("\n非法用户 请离开\n");
		return 0;
	default:
		break;
	}
	return 0;
}
