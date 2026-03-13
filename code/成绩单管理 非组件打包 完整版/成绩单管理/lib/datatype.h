#pragma once
/*链表内部的节点类型*/
typedef struct node
{
	struct node* prev;//前一个节点指针
	void* data;//数据域指针
	struct node* next;//下一个节点指针
} Node, * PNode;

/*链表管理类型*/
typedef struct
{
	PNode header;//头节点
	PNode ender;//尾部节点
	int size;//当前节点总数
	PNode nextNode;//迭代器的下一个节点

}LinkedList, * PLinkedList;

/*用于比较数据域大小的函数指针类型*/
typedef  int(*Compare)(void*, void*);
