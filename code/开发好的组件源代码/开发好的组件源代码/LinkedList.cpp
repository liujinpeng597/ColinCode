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
    PNode  newNode = (PNode)malloc(sizeof(Node));
    newNode->prev = NULL;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void add(PLinkedList list, void* data)
{
     PNode newNode = createNode(data);
    if ( list->size==0)//空链表
    {
        list->header = newNode;
        list->ender = newNode;
        list->size = 1;
    }
    else
    {
        newNode->prev = list->ender;
        list->ender->next = newNode;

        list->ender = newNode;
        list->size++;
    }
}

void insert(PLinkedList list, int index, void* data)
{
    if (list->size==0 //空链表 尾部添加
        || index>=list->size)
    {
        add(list, data);
        return;
    }
    //中间插入
    PNode newNode = createNode(data);
    if ( index <=0)
    {
        newNode->next = list->header;
        list->header->prev = newNode;
        list->header = newNode;
    }
    else
    {
         PNode p = findNode(list, index);
        PNode q = p->prev;
        newNode->next = p;
        p->prev = newNode;
        q->next = newNode;
        newNode->prev = q;
    }
    list->size++;
}

void* removeIndex(PLinkedList list, int index)
{
    PNode p = NULL;//p指向被删节点
    if (list->size==0)//空链表
    {
        return NULL;
    }
    else if (list->size==1)
    {
        p = list->header;
        list->header = list->ender = NULL;
    }
    else if ( index<=0 )//删除头部
    {
        p = list->header;
        list->header = p->next;
        list->header->prev = NULL;
    }
    else if ( index >= list->size-1)//删除尾部
    {
        p = list->ender;
        list->ender = p->prev;
        list->ender->next = NULL;
    }
    else
    {
        p = findNode(list, index);
        PNode q = p->prev;
        PNode m = p->next;
        q->next = m;
        m->prev = q;
    }
  
    if (p!=NULL)
    {
        void* tmp = p->data;
        list->size--;
        free(p);
        return tmp;
    }
    return NULL;
}

void removeData(PLinkedList list, void* data, Compare fun)
{
    int i = indexOf(list, data, fun);
    if (i>=0)
    {
        removeIndex(list, i);
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
    while ( p!=NULL)
    {
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
    return list->nextNode != NULL;
}

void* next(PLinkedList list)
{
    void * tmp =  list->nextNode->data;
    //为下一个做好准备
    list->nextNode =list->nextNode->next;
    return tmp;
}

void push(PLinkedList list, void* data)
{
    add(list, data);
}

void* pop(PLinkedList list)
{
    return removeIndex(list,list->size-1);
}

void* get(PLinkedList list, int index)
{
    
    PNode p = findNode(list, index);
    return p!=NULL ? p->data : NULL;
}

PNode findNode(PLinkedList list, int index)
{
    PNode p = list->header;
    for (int i = 0; i < index && p != NULL; i++)
    {
        p = p->next;
    }
    return p;
}

void set(PLinkedList list, int index, void* newdata)
{
  PNode p = findNode(list, index);
  if (p!=NULL)
  {
      p->data = newdata;
  }
}

int indexOf(PLinkedList list, void* data, Compare fun)
{
    PNode p = list->header;
    for (int i=0 ;i<list->size ;i++ )
    {
        if ( fun(p->data,data)==0 )
        {
            return i;
        }
    }
    return -1;
}


void addFirst(PLinkedList  list, void* data)
{
    insert(list, 0, data);
}
void addLast(PLinkedList  list, void* data)
{
    add(list, data);
}
void* removeFirst(PLinkedList  list)
{
    return removeIndex(list, 0);
}
void* removeLast(PLinkedList  list)
{
    return removeIndex(list, list->size - 1);
}