#include<stdio.h>
#include<string.h>

int main()
{
	//扩展类型
	struct student {
		char sex; 
		int age;  
		float score;
	};
	union data {
		int i;
		char c;
		float f;
	};
	int arr[5];
	int* p;
	//struct和union的区别

	//结构体对齐补齐的含义
	struct student stu;
	union data data1;
	printf("student结构体所占内存%d\n", sizeof(stu));
	printf("data共用体所占内存%d\n", sizeof(data1));
	//union使用时的注意事项
	return 0;
}