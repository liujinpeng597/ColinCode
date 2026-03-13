#pragma once
#define LOGIN_ERR 0
#define LOGIN_SUCCESS 1

/*
登录输入
参数：user账号的存放处
	pwd密码密码的存放处
*/
void loginInput(char user[], char pwd[]);
/*以掩码的形式输入密码*/
char* getMarkcode(char* password, size_t size);
/*登录验证*/
int login(char user[], char pwd[]);

/*显示教师菜单*/
void showTeacherMenu();

/*处理 教师的菜单功能*/
void optTeacherMenu();

/*退出系统*/
void quit();
