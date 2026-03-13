#include "collections.h"
#include "string.h"
int main()
{
	PLinkedList list1 = createLinkedList();
	add(list1, "one");
	add(list1, "two");
	add(list1, "three");
	PLinkedList list2 = createLinkedList();
	add(list2, "python");
	add(list2, "java");
	add(list2, "c++");
	addAll__(list1, list2);

	reverse__(list1);
	//swap__(list1, 1, 2);
	//shuffle__(list1);
	/*const char* mv = (const char*)max__(list1, worldLenth);
	printf("最大字符串:%s\n", mv);*/

	sort__(list1, wordCmp);
	int xb = binarySearch__(list1, "java",wordCmp);
	printf("所在下标:%d\n", xb);
	//遍历列表
	iterator(list1);
	while (hasNext)
	{
		const char* str = (const char*)next(list1);
		puts(str);
	}
	return 0;
}

int worldLenth(void* v1, void* v2)
{
	const char* p1 = (const char*)v1;
	const char* p2 = (const char*)v2;
	return strlen(p1) - strlen(p2);
}

int wordCmp(void* v1, void* v2)
{
	const char* pl = (const char*)v1; 
	const char* p2 = (const char*)v2;

	return strcmp(pl, p2);
}