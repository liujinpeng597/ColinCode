#include <stdio.h>
 
typedef struct book
{
	int price;
	char* name; 
} Book;
typedef struct  
{
	int age;
	char *name;
	struct
	{
		int price;
		char* name;
		struct page
		{
			int pageNum;
			char word[100];
		}pages[5];
	} book;
}  Student;

int main08()
{
	Student s={  20,"张三",{12,"如来神掌"} };
	
	printf("书名：%s\n",s.book.name);//得到嵌套结构体内的成员，继续  .  运算
	printf("价格：%d\n",s.book.price);
	return 0;
}