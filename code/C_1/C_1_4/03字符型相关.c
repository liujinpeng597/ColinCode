/*
  知识点列表：
  1 类型关键字
  2 命名规范
  3 
  4 字节大小与数据范围
  5 溢出现象
  6 
  7 
  8 
  9 
  10 打印格式
*/
#include<stdio.h>
int main03()
{
	//字符的原理
	//char wz1 = 'B';
	//printf("字符影像 %c 字符编码%hhd\n", wz1, wz1);
	//char wz2 = 98;
	//printf("字符影像 %c 字符编码%hhd\n", wz2, wz2);
	//char ch1 = 'A';
	//char ch2 = '65';
	//char ch3 = '\102';
	//char ch4 = '\x42';
	//printf("ABCD\n");
	//printf("\102\103\x44\x45\n");
	//wchar_t hz = L'张';//L 宽字符的前缀
	//printf("He\12llo %c Wor\xald.\n", 10);
	//printf("math\tcn\ten\t\n");
	//printf("100\t100\t100\t\n");
	//printf("100\t100\t100\t\n");
	//printf("\a");
	//printf("how are\b\b you\n");
	//printf("how are\r you\n");
	//printf("\\ \" \' %%\n");
	//int n = '8';
	//printf("%d",n - '0');
	char ch=0;
	while (ch != '\n') {
		scanf_s("%c", &ch,1);
		printf("%c", ch);
	}

	return 0;
	
}