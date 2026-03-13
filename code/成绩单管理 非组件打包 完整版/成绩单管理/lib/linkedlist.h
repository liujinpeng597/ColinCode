#pragma once
#include <stdio.h>
#include <stdlib.h>
#include"datatype.h"

/*创建链表*/
PLinkedList createLinkedList();
/*创建节点*/
PNode createNode(  void * data);

 /*增加新的节点*/
void add(PLinkedList  list ,  void * data);
 
/*在某节点的位置上插入新节点*/
void insert(PLinkedList  list ,int index,  void * data);

/*删除 指定 下标的节点*/
void* removeIndex(PLinkedList  list ,int index);

/*删除等于参数的首个节点*/
void removeData(PLinkedList  list ,  void* data, Compare fun);

/*某下标对应的 节点*/
void* get(PLinkedList  list ,int index);
/*找到节点*/
PNode findNode(PLinkedList  list ,int index);

/*某下标对应的 节点数据进行更新 */
void set(PLinkedList  list ,int index,  void* newdata);

/*某数据对应的下标*/
int indexOf(PLinkedList  list , void* data,Compare fun );

/*节点数量*/
int size(PLinkedList  list );

/*清空链表*/
void clear(PLinkedList  list );

 /*迭代器*/
//产生新的迭代器
void iterator(PLinkedList list);
//是否有下一个节点
int hasNext(PLinkedList list);
//取得下一个节点数据
void* next(PLinkedList list);

/*实现栈stack的功能：LIFO：last in first out */
/* 入栈*/
void push(PLinkedList  list ,  void* data);

/*出栈*/
void* pop(PLinkedList  list );

/*实现队列queue的功能：FIFO：first in first out */
void addFirst(PLinkedList  list ,  void* data);
void addLast(PLinkedList  list ,  void* data);
void* removeFirst(PLinkedList  list   );
void* removeLast(PLinkedList  list  );

 
