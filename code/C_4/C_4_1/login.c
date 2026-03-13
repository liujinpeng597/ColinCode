#include<stdio.h>
#include<string.h>
#include<conio.h>
char* get_mark(char str[], size_t size);
int mainlogin() {
	char user[30];//用户账号
	char password[20];//密码
	puts("***欢迎使用***");
	printf("账号：");
	gets_s(user, 30);
	printf("密码：");
	get_mark(password, 20);
	if (strcmp("colin", user) == 0
		&& strcmp("123456", password) == 0)
	{
		puts("欢迎。。。。");
	}
	else
	{
		puts("非法闯入。。。。");
	}
}

char* get_mark(char str[], size_t size)
{
	int pwd;
	int count = 0;
	do {
		pwd = getch();
		//判断是否输入的是回车
		if (pwd == '\r') {
			break;
		}
		//判断是否输入的是退格
		else if (pwd == '\b') {
			if (count >= 1) {
				putchar('\b');
				putchar(' ');
				putchar('\b');
				count--;
			}
		}
		else {
			putchar('*');
			str[count++] = pwd;
		}
	} while (count < size - 1);
	str[count] = '\0';
	return str;
}
