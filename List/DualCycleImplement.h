#ifndef DUALCYCLEIMPLEMENT_H
#define DUALCYCLEIMPLEMENT_H

#include "DualCycleLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

Status InitList_DuL(DuLinkList *L)
{
	*L = (DuLinkList)malloc(sizeof(DuLNode));
	if (!(*L))
		exit(OVERFLOW);

	(*L)->next = (*L)->prior = *L;

	return OK;
}

Status ClearList_DuL(DuLinkList L)
{
	DuLinkList p, q;
	p = L->next;

	while (p != L)
	{
		q = p->next;
		free(p);
		p = q;
	}
	L->next = L->prior = L;
	return OK;
}

void DestroyList_DuL(DuLinkList *L)
{
	ClearList_DuL(*L);

	free(*L);

	*L = (DuLinkList)NULL;
}

Status ListEmpty_DuL(DuLinkList L)
{
	if (L && L->next == L && L->prior == L)
		return TRUE;
	else
		return FALSE;
}


int ListLength_DuL(DuLinkList L)
{
	DuLinkList p;
	int count;

	if (L)
	{
		count = 0;
		p = L;  //p指向头结点

		while (p->next != L)  //p没到表头
		{
			count++;
			p = p->next;
		}
	}

	return count;
}


Status GetElem_DuL(DuLinkList L, int i, LElemType_DC  *e)
{
	DuLinkList p;
	int count;

	if (L)
	{
		count = 1;
		p = L->next;

		while (p != L && count < i)
		{
			count++;
			p = p->next;
		}

		if (p != L)
		{
			*e = p->data;
			return OK;
		}
	}
	return ERROR;
}


int LocateElem_DuL(DuLinkList L, LElemType_DC e, Status(Compare)(LElemType_DC, LElemType_DC))
{
	DuLinkList p;
	int count;

	if (L)
	{
		count = 1;
		p = L->next;

		while (p != L && !Compare(e, p->data))
		{
			count++;
			p = p->next;
		}

		if (p != L)
			return count;
	}

	return 0;
}


//(08)用pre_e接收cur_e的前驱。
Status PriorElem_DuL(DuLinkList L, LElemType_DC cur_e, LElemType_DC *pre_e)
{
	DuLinkList p;
	if (p)
	{
		p = L->next;


		while (p != L && p->data != cur_e)
			p = p->next;

		if (p != L && p->prior != L)  //P
		{
			*pre_e = p->prior->data;

			return OK;
		}
	}

	return ERROR;
}

//(09)用next_e接收cur_e的后继。
Status NextElem_DuL(DuLinkList L, LElemType_DC cur_e, LElemType_DC *next_e)
{
	DuLinkList p;

	if (L)
	{
		p = L->next;
		while (p != L && p->data != cur_e)
			p = p->next;

		if (p != L && p->next != L)
		{
			*next_e = p->next->data;
			return OK;
		}
	}//if

	return ERROR;
}

//(10)返回L中指向第i个结点的指针。
DuLinkList GetElemPtr_DuL(DuLinkList L, int i)
{
	int count;
	DuLinkList p;

	if (i > 0 && L)
	{
		count = 1;
		p = L->next;
		while(count <i && p!=L)
		{
			count++;
			p = p->next;
		}
		if (p != L)
			return p;
	}
	return (DuLinkList)NULL;
}

//(11)算法2.18：在L第i个位置之前插入e。
Status	ListInsert_DuL(DuLinkList L, int i, LElemType_DC e)
{
	DuLinkList p, s;

	if (i<1 || i>ListLength_DuL(L) + 1) return ERROR;

	//p为第i个结点的指针
	p = GetElemPtr_DuL(L, i);
	if (!p) p = L;  //若P=NULL，说明i=ListLength_DuL（L）+1, 令p指向头指针

	s = (DuLinkList)malloc(sizeof(DuLinkList));
	if (!s) exit(OVERFLOW);
	s->data = e;

	//插入操作
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;

	return OK;
}

//(12)算法2.19：删除L第i个位置的值，并用e接收。
Status ListDelete_DuL(DuLinkList L, int i, LElemType_DC* e)
{
	DuLinkList p;

	if (!(p = GetElemPtr_DuL(L, i))) return ERROR;	

	*e = p->data;

	//删除
	p->prior->next = p->next;
	p->next->prior = p->prior;

	free(p);
	p = (DuLinkList)NULL;

	return OK;
}

//(13)用Visit函数访问L。
void ListTreaverse_DuL(DuLinkList L, Status(Visit)(LElemType_DC))
{
	DuLinkList p;

	p = L->next;

	while (p != L && Visit(p->data)) p = p->next;
}


#endif // !DUALCYCLEIMPLEMENT_H''
