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
		p = L;  //pָ��ͷ���

		while (p->next != L)  //pû����ͷ
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


//(08)��pre_e����cur_e��ǰ����
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

//(09)��next_e����cur_e�ĺ�̡�
Status NextElem_DuL(DuLinkList L, LElemType_DC cur_e, LElemType_DC e);

//(10)����L��ָ���i������ָ�롣
DuLinkList GetElemPtr_DuL(DuLinkList L, int i);

//(11)�㷨2.18����L��i��λ��֮ǰ����e��
Status	ListInsert_DuL(DuLinkList L, int i, LElemType_DC e);

//(12)�㷨2.19��ɾ��L��i��λ�õ�ֵ������e���ա�
Status ListDelete_DuL(DuLinkList L, int i, LElemType_DC *e);

//(13)��Visit��������L��
void ListTreaverse_DuL(DuLinkList L, void(Visit)(LElemType_DC));


#endif // !DUALCYCLEIMPLEMENT_H''
