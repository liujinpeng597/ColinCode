#include<stdio.h>
#include"linkedlist.h"

int main000()
{
	/*PLinkedList stack = createLinkedList();
	push(stack, "车");
	push(stack, "马");
	push(stack, "炮");
	const char* qz;
	qz = (const char*)pop(stack);
	puts(qz);
	qz = (const char*)pop(stack);
	puts(qz);
	qz = (const char*)pop(stack);
	puts(qz);*/
	PLinkedList queue = createLinkedList();
	addLast(queue, "aa");
	addLast(queue, "bb");
	addLast(queue, "dd");
	//出队列
	const char* qz;
	qz = (const char*)removeFirst(queue);
	puts(qz);
	qz = (const char*)removeFirst(queue);
	puts(qz);
	qz = (const char*)removeFirst(queue);
	puts(qz);
	qz = (const char*)removeFirst(queue);
	puts(qz);
	return 0;
}