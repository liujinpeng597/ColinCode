#include"collections.h"
#include<time.h>
void addAll__(PLinkedList list1, PLinkedList list2)
{
	iterator(list2);
	while ( hasNext(list2))
	{
		add(list1, next(list2));
	}
}

void* max__(PLinkedList list, Compare fun)
{
	void* maxValue = list->header->data;
	PNode p = list->header->next;
	while (p)
	{
		if ( fun(maxValue, p->data)<0)
		{
			maxValue = p->data;
		}
		p = p->next;
	}
	return maxValue;
}

void* min__(PLinkedList list, Compare fun)
{
	void* minValue = list->header->data;
	PNode p = list->header->next;
	while (p)
	{
		if (fun(minValue, p->data) > 0)
		{
			minValue = p->data;
		}
		p = p->next;
	}
	return minValue;
}

void swap__(PLinkedList list, int i, int j)
{
	PNode pi = findNode(list, i);
	PNode pj = findNode(list, j);
	if (pi&&pj)
	{
		void* t;
		t = pi->data;
		pi->data = pj->data;
		pj->data = t;
	}
}

void sort__(PLinkedList list, Compare fun)
{
	 
	PNode pSuo = list->header;
	for (int suo = 0; suo < size(list) - 1; suo++,pSuo=pSuo->next)
	{
		PNode pBi = pSuo->next;
		for (int bi = suo + 1; bi < size(list); bi++,pBi=pBi->next)
		{
		 
			if (fun(pSuo->data, pBi->data) > 0)
			{
				void* t;
				t = pSuo->data;
				pSuo->data = pBi->data;
				pBi->data = t;
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
		//mid	=(left + right) / 2;
		mid = (left + right) >> 1;
		void* midValue = get(list, mid);
		int r = fun(midValue, find);
		if (r==0)
		{
			 
			return mid;
		}
		else if ( r > 0 )
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
	for ( int ci = 0; ci<size(list);ci++ )
	{
		int a = rand() % size(list);
		int b = rand() % size(list);
		swap__(list, a, b);
	}

}

void reverse__(PLinkedList list)
{
	PNode pi = list->header;
	PNode pj = list->ender;
	for (int i=0,j=list->size-1 ;i<j ; i++,j--)
	{
		void* t;
		t = pi->data;
		pi->data = pj->data;
		pj->data = t;

		pi = pi->next;
		pj = pj->prev;
	}
}

void replaceAll__(PLinkedList list, void* oldVal, void* newVal, Compare fun)
{
	PNode p = list->header;
	while (p)
	{
		if ( fun(p->data,oldVal)==0)
		{
			p->data = newVal;
		}

		p = p->next;
	}
}
