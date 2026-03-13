#include"collections.h"
#include<stdlib.h>
#include<time.h>

void addAll__(PLinkedList list1, PLinkedList list2)
{
	iterator(list2);
	while (hasNext(list2))
	{
		add(list1, next(list2));
	}
}

void* max__(PLinkedList list, Compare fun)
{
	if (list->size == 0)
	{
		return NULL;
	}
	void* maxValue = list->header->data;
	PNode p = list->header->next;
	while (p != NULL)
	{
		if (fun(maxValue,p->data) < 0)
		{
			maxValue = p->data;
		}
		p = p->next;
	}
	return maxValue;

	return nullptr;
}

void swap__(PLinkedList list, int i, int j)
{
	PNode pi = findNode(list, i);
	PNode pj = findNode(list, j);
	void* t;
	t = pi->data;
	pi->data = pj->data;
	pj->data = t;
}

void sort__(PLinkedList list, Compare fun)
{
	PNode psuo = list->header;
	for (int suo = 0; suo < list->size - 1; suo++)
	{
		PNode pbi = psuo->next;
		for (int bi = suo + 1; bi < list->size; bi++, pbi = pbi->next)
		{
			if (fun(psuo->data, pbi->data) > 0)
			{
				void* t;
				t = psuo->data;
				psuo->data = pbi->data;
				pbi->data = t;
			}
		}
	}
}

int binarySearch__(PLinkedList list, void* find, Compare fun)
{
	int left = 0;
	int right = list->size - 1;
	int mid;
	do
	{
		mid = (left + right) / 2;
		void* midValue = get(list, mid);
		int r = fun(midValue, find);
		if (r==0)
		{
			return mid;
		}
		else if (r>0)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	} while (left <= right);
	return -1;
}

void shuffle__(PLinkedList list)
{
	srand((unsigned)time(NULL));
	for (int ci = 0; ci < size(list); ci++)
	{
		int sja = rand() % list->size;
		int sjb = rand() % list->size;
		if (sja != sjb)
		{
			swap__(list, sja, sjb);
		}
	}
}

void reverse__(PLinkedList list)
{
	PNode pi = list->header;
	PNode pj = list->ender;
	for (int i = 0, j = list->size - 1; i < j; i++, j--) 
	{
		void* t;
		t = pi->data;		pi->data = pj->data;
		pj->data = t;

		pi = pi->next;
		pj = pj->prev;
	}
}

