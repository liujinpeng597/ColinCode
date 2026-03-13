#include <stdio.h>
 
struct AA 
{
	int a; 
	short c; 
	char b; 
}  ;

struct HH  
{
	int a; 
	short c; 
	char b; 
	short d; 
	char e; 
	short f;
}  ;

struct HH2
{
	int a; 
	short c; 
	short d; 
	char e; 
	char b; 
	short f;
}  ;

struct FF1
{
	char a[5]; 
	char *e;
}  ;

struct FF2
{
	char a[5]; 
	char *e;
}  ;
int main05()
{
	//测试不同结构体的空间大小
	printf("%d\n",sizeof(struct AA));
	 
	
	//结构对齐原则的启示   

	return 0;
}