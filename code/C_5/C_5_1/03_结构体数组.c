#include <stdio.h>
/*定义一个结构体*/
typedef struct book {
	char bookName[50];
	char writer[30];
	double price;
	int year;
}BOOK, *P_BOOK;
int main03  ()
{
	/*创建结构体数组变量*/
	BOOK books[4] = { {"三体","刘慈欣",58.6,2015},
					 {"C语言从入门到放弃","谭浩强",28.6,2000},
					 {"活着","余华",16.5,2000},
					 {"论持久战","毛主席",66.8,2000} };

	struct book* p1 = books;
	BOOK* p2 = books + 1;
	P_BOOK p3 = &books[3];

	(*p1).price = 40;
	p1->price = 38.6;
	for (int suo = 0; suo < 3; suo++) {
		for (int bi = suo + 1; bi < 4; bi++) {
			if (books[suo].year > books[bi].year
				|| books[suo].year == books[bi].year
				&& books[suo].price < books[bi].price) {
				BOOK t;
				t = books[suo]; books[suo] = books[bi]; books[bi] = t;     
			}
		}
	}
	/*为结构体成员赋值 用.操作符*/
	for (int i = 0; i < 4; i++) {
		printf("%-20s,%-10s,%.1f,%d", books[i].bookName,
			books[i].writer,
			books[i].price,
			books[i].year);
	}
	return 0;
}