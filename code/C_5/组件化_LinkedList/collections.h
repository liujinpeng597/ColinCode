#pragma once
#include "linkedlist.h"

/*将链表2 追加到链表1的后面*/
void  addAll__(PLinkedList list1, PLinkedList list2);
/*返回最大数据域*/
void*  max__(PLinkedList list,Compare fun);
/*返回最小数据域*/
void*  min__(PLinkedList list,Compare fun);
/*交换 两个下标对应的数据域*/
void swap__(PLinkedList list, int i, int j);
/*对链表 按 Compare比较规则 进行排序 */
void sort__(PLinkedList list,Compare fun );
/*使用折半查找思路 查询某key数据的下标*/
int binarySearch__(PLinkedList list,   void * key, Compare fun);
/*打乱链表的顺序*/
void shuffle__(PLinkedList list);
/*对链表成员进行首尾倒置*/
void  reverse__(PLinkedList list);
/*把复合fun比较规则的数据域 替换成新的数据域*/
void replaceAll__(PLinkedList list,  void *oldVal,   void *newVal, Compare fun  );
	 