#include<stdio.h>
#include<stdlib.h>
 
int main01()
{
	//1 查看文件帮助文档 了解参数

	//2 用r只读模式打开文件流 
	FILE* readFile = fopen("d:\\bbb.txt","rb"); 
	
	if (readFile)//如果文件打开成功
	{
		fclose(readFile);//关闭文件流。
		readFile=NULL;//释放文件指针。
		printf("文件存在\n");
	}
	else
	{
		printf("文件不存在\n");
	}
	//3 用w只写模式 打开并创建文件
	FILE* pf = fopen("d:\\myfile\\黑名单.txt", "wt");
	if (pf != NULL)
	{
		puts("创建成功");
		fclose(pf);
		pf = NULL;
	}
	else
	{
		puts("创建失败");
	}
	//4 给文件改名：已有名字，新的名字
	 
	//5 删除文件：
	int r = remove("d:\\myfile\\黑名单.txt");
	printf("%d\n", r);
	 
	return 0;
}