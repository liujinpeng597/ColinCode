#include "linkedlist.h"
#include "string.h"

int main01()
{
	//创建链表
	PLinkedList list = createLinkedList();
	//向链表中 加入用户数据
	add(list, "peach");
	add(list, "apple");
	add(list, "grape");
	add(list, "orange");
	///*insert(list, 2, "C++");
	//insert(list, 0, "java");
	//insert(list, 10, "python");*/
	//const char* str = (const char*)removeIndex(list, 2);
	//puts(str);
	//PLinkedList list2 = createLinkedList();
	set(list, 1, "APPLE");
	for (int i = 0; i < size(list); i++)
	{
		const char* str = (const char*)get(list, i);
		puts(str);
	}

	iterator(list);
	while (hasNext)
	{
		const char* str = (const char*)next(list);
		puts(str);
	}

	clear(list);
	free(list);
	return 0;
}