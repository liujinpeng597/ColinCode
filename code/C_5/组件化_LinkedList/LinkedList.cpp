#include"linkedlist.h"

PLinkedList createLinkedList()
{
	PLinkedList newList = (PLinkedList)malloc(sizeof(LinkedList));
	newList->header = NULL;
	newList->ender = NULL;
	newList->size = 0;
	return newList;
}

PNode createNode(void* data)
{
	PNode newNode = (PNode)malloc(sizeof(Node));
	newNode->prev = NULL;
	newNode->next = NULL;
	newNode->data = data;
	return newNode;
}

void add(PLinkedList list, void* data)
{
	PNode newnode = createNode(data);
	if (list->size == 0)
	{
		list->header = list->ender = newnode;
		list->size = 1;
	}
	else
	{
		list->ender->next = newnode;
		newnode->prev = list->ender;
		list->ender = newnode;
		list->size++;
	}
}

void insert(PLinkedList list, int index, void* data)
{
	//空或者尾部
	if (list->size == 0 || index >= list->size)
	{
		add(list, data);
		return;
	}
	PNode newnode = createNode(data);
	//头部
	if (index <= 0)
	{
		newnode->next = list->header;
		list->header->prev = newnode;
		list->header = newnode;
	}
	//中间
	else
	{
		PNode p = findNode(list,index);
		PNode q = p->prev;
		newnode->next = p;
		p->prev = newnode;
		q->next = newnode;
		newnode->prev = q;
	}
	list->size++;
}

void* removeIndex(PLinkedList list, int index) {
	if (list->size == 0 || list == NULL)return NULL;
    PNode p = findNode(list, index);
	if (p == NULL)return NULL;
	if (list->size == 1) {
		list->header = NULL;
		list->ender = NULL;
	}
	else if (index <= 0) {
		list->header = p->next;
	}
	else if (index >= list->size-1) {
		list->ender = p->prev;
	}
	else {
		p->prev->next = p->next;
		p->next->prev = p->prev;
	}
	list->size--;
	void* data = p->data;
	free(p);
	return data;
}

void* get(PLinkedList list, int index)
{
	PNode p = findNode(list, index);
	return p!=NULL?p->data:NULL;
}

PNode findNode(PLinkedList list, int index)
{
	PNode p = list->header;
	for (int i = 0; i < index && i<list->size; i++)
	{
		p = p->next;
	}
	return p;
}

void set(PLinkedList list, int index, void* newdata)
{
	PNode p = findNode(list,index);
	if (p != NULL) 
	{
		p->data = newdata;
	}
}

int size(PLinkedList list)
{
	return list->size;
}

void clear(PLinkedList list)
{
	PNode p = list->header;
	PNode q = NULL;
	while (p != NULL) {
		q = p;
		p = p->next;
		free(q);
		list->size--;
	}
	list->header = list->ender = NULL;
}

void iterator(PLinkedList list)
{
	list->nextNode = list->header;
}

int hasNext(PLinkedList list)
{
	return list->nextNode!=NULL;
}

void* next(PLinkedList list)
{
	void* t = list->nextNode->data;
	list->nextNode = list->nextNode->next;
	return t;
}

void push(PLinkedList list, void* data)
{
	add(list, data);
}

void* pop(PLinkedList list)
{
	return removeIndex(list,list->size-1);
}

void addFirst(PLinkedList list, void* data)
{
	insert(list, 0, data);
}

void addLast(PLinkedList list, void* data)
{
	add(list, data);
}

void* removeFirst(PLinkedList list)
{
	return removeIndex(list,0);
}

void* removeLast(PLinkedList list)
{
	return removeIndex(list,list->size-1);
}
