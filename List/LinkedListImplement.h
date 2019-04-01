#ifndef  LINKEDLISTIMPLEMENT_H
#define  LINKEDLISTIMPLEMENT_H

#include "SinglyLinkedList.h" /*线性表数据结构*/


Status InitList_L(LinkList *L)
{
	(*L) = (LinkList)malloc(sizeof(LNode));
	if (!(*L))
		exit(OVERFLOW);

	(*L)->next = (LNode *)NULL;

	return OK;
}


Status ClearList_L(LinkList L)
{
	LinkList pre, p;

	if (!L)
		return ERROR;

	pre = L->next;

	while (pre)
	{
		p = pre->next;
		free(pre);
		pre = p;
	}

	L->next = (LNode *)NULL;

	return OK;
}

void DestroyList_L(LinkList *L)
{
	LinkList p = *L;
	while (p)
	{
		p = (*L)->next;
		free(p);
		(*L) = p;
	}
}

Status ListEmpty_L(LinkList L)
{
	if (L != NULL && L->next == NULL)
		return TRUE;
	else
		return FALSE;
}

int ListLength_L(LinkList L)
{
	LinkList p;
	int i;
	if (L)
	{
		i = 0;
		p = L->next;
		while (p)
		{
			++i;
			p = p->next;
		}
	}

	return i;
}

Status GetElem_L(LinkList L, int i, LElemType_L *e)
{
	int j = 1;
	LinkList p = L->next;

	while (p &&j < i)
	{
		++j;
		p = p->next;
	}

	if (!p || j > i)
		return ERROR;

	*e = p->data;

	return OK;
}

int LocateElem_L(LinkList L, LElemType_L e, Status(Compare)(LElemType_L, LElemType_L))
{
	LinkList p = L->next;
	int i = 1;

	if (!L)
		return -1;

	while (p)
	{
		if (Compare(e, p->data))
			return i;
		else
			p = p->next;

		++i;
	}

	return 0;
}

/* 银行排队算法中，此处两个函数不能直接使用，原因是结构不能直接比较 */
Status PriorElem_L(LinkList L, LElemType_L cur_e, LElemType_L *pre_e)
{
	LinkList p, suc;
	if (L)
	{
		p = L->next;
		if (p->data != cur_e) //第一个结点无前驱
		{
			while (p->next)
			{
				suc = p->next;
				if (suc->data == cur_e)
				{
					*pre_e = p->data;
					return OK;
				}//if
				p = suc;
			}
		}
	}
}

Status NextElem_L(LinkList L, LElemType_L cur_e, LElemType_L *next_e)
{
	LinkList p, suc;

	if (L)
	{
		p = L->next;
		while (p && p->next)
		{
			suc = p->next;

			if (suc && p->data == cur_e)
			{
				*next_e = suc->data;
				return OK;
			}//if

			if (suc)
				p = suc;
			else
				break;
		}
	}
	return ERROR;
}

Status ListInsert_L(LinkList L, int i, LElemType_L e)
{
	LinkList p = L, s;
	int j = 0;

	while (p && j < i - 1)
	{
		p = p->next;
		++j;
	}

	if (!p || j > i - 1)
		return ERROR;

	s = (LinkList)malloc(sizeof(LNode));
	if (!s)
		exit(OVERFLOW);

	s->data = e;
	s->next = p->next;
	p->next = s;

	return OK;
}


Status ListDelete_L(LinkList L, int i, LElemType_L *e)
{
	LinkList pre = L, p;
	int j = 1;

	while (pre->next && j < i)    //寻找第i个结点，并令pre指向其前驱 
	{
		pre = pre->next;
		++j;
	}

	if (j > i || !pre->next)  //删除位置不合理
		return ERROR;

	p = pre->next;
	*e = p->data;
	pre->next = p->next;
	free(p);

	return OK;
}


Status ListTreaverse_L(LinkList L, void(Vist)(LElemType_L))
{
	LinkList p;

	if (L)
	{
		p = L->next;
		printf("[ ");
		while (p)
		{
			Vist(p->data);
			p = p->next;
		}
		printf("]\n");
		return OK;
	}
	return ERROR;
}

Status CreateList_HL(FILE *fp, LinkList *L, int n)
{
	LinkList p;
	LElemType_L temp;
	int i;

	*L = (LinkList)malloc(sizeof(LNode));
	if (!(*L))
		exit(OVERFLOW);
	(*L)->next = NULL;

	/*for (i = 1; i <= n; ++i)
	{
		if (Scanf(fp, "%d", &temp) == 1)
		{
			p = (LinkList)malloc(sizeof(LNode));
			if (!p)
				exit(OVERFLOW);
			p->data = temp;
			p->next = (*L)->next;
			(*L)->next = p;
		}
		else
			perror("IO");
	}*///for

	return OK;
}

#if 0
Status CreateList_TL(FILE *fp, LinkList *L, int n)
{
	int i;
	LinkList p, q;
	LElemType_L temp;

	(*L) = (LinkList)malloc(sizeof(LNode));
	if (!(*L))
		exit(OVERFLOW);
	(*L)->next = NULL;

	/*for (i = 1, q = (*L); i <= n; ++i)
	{
		if (Scanf(fp, "%d", &temp) == 1)
		{
			p = (LinkList)malloc(sizeof(LNode));
			if (!p)
				exit(OVERFLOW);
			p->data = temp;
			q->next = p;
			q = q->next;
		}
		else
			return ERROR;
	}*/
	q->next = NULL;
	return OK;
}
#endif

/*不使用文件的插入*/ 
Status CreateList_H(LinkList *L )
{
	*L = (LinkList)malloc(sizeof(LNode));
	if (!(*L))
		exit(OVERFLOW);

	LNode *p = *L, *s;
	p->next = NULL;

	LElemType_L temp;

	scanf("%d", &temp);

	while (temp != 9999)
	{
		s = (LNode *)malloc(sizeof(LNode));
		s->data = temp;
		s->next = p->next;
		p->next = s;

		scanf("%d", &temp);
	}
	return OK;
}
Status CreateList_T(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(LNode));
	if (!(*L))
		exit(OVERFLOW);

	LNode *p = *L, *s;
	LElemType_L temp;
	scanf("%d", &temp);

	while (temp != 999)
	{
		s = (LNode *)malloc(sizeof(LNode));

		s->data = temp;
		s->next = NULL;
		p->next = s;
		p = s;

		scanf("%d", &temp);
	}
	p->next = NULL;

	return OK;
}

Status CreateList_NFN(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(LNode));
	if (!(*L))
		exit(OVERFLOW);

	LNode *s;
	LElemType_L temp;
	scanf("%d", &temp);
	(*L)->data = temp;
	(*L)->next = NULL;

	scanf("%d", &temp);
	while (temp != 9999)
	{
		s = (LNode *)malloc(sizeof(LNode));
		s->data = temp;
		s->next = (*L)->next;

		(*L)->next = s;

		scanf("%d", &temp);
	}
}

#endif // ! LINKEDLISTIMPLEMENT_H
