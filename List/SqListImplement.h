#ifndef  SQLISTIMPLEMENT_H
#define  SQLISTIMPLEMENT_H

#include "SequenceList.h"


Status InitList_Sq(SqList *L)
{
	(*L).elem = (LElemType_Sq *)malloc(LIST_INI_SIZE * sizeof(LElemType_Sq));
	if (!(*L).elem)
		exit(OVERFLOW);				 //分配内存失败

	(*L).length = 0;				 //初始化顺序表长度为0
	(*L).listsize = LIST_INI_SIZE;   //顺序表初始内存分配量

	return OK;
}


void ClearList_Sq(SqList *L)
{
	(*L).length = 0;
}


void DestroyList_Sq(SqList *L)
{
	free((*L).elem);

	(*L).elem = NULL;
	(*L).length = 0;
	(*L).listsize = 0;
}


Status ListEmpty_Sq(SqList L)
{
	return L.length == 0 ? TRUE : FALSE;
}


int ListLength_Sq(SqList L)
{
	return L.length;
}


Status GetElem_Sq(SqList L, int i, LElemType_Sq *e)
{
	if (i<1 || i>L.length)
		return ERROR;
	else
		*e = L.elem[i - 1];

	return OK;
}


int LocateElem_Sq(SqList L, LElemType_Sq e, Status(Compare)(LElemType_Sq, LElemType_Sq))
{
	int pos = 1;

	while (pos <= L.length && !Compare(e, L.elem[pos - 1]))
		++pos;

	if (pos <= L.length)
		return pos;
	else
		return 0;
}


Status PriorElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *pre_e)
{
	int i = 1;

	if (cur_e != L.elem[0])  //第一个结点无前驱
	{
		while (i < L.length && L.elem[i] != cur_e)
			++i;

		if (i < L.length)
		{
			*pre_e = L.elem[i - 1];
			return OK;
		}
	}

	return ERROR;
}


Status NextElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *next_e)
{
	int i = 0;

	if (L.elem[L.length - 1] != cur_e)
	{
		while (i < L.length - 1 && L.elem[i] != cur_e)
			++i;

		if (i < L.length - 1)
		{
			*next_e = L.elem[i + 1];
			return OK;
		}
	}

	return ERROR;
}


Status ListInsert_Sq(SqList *L, int i, LElemType_Sq e)
{
	LElemType_Sq *newbase, *p, *q;

	if (i<1 || i>(*L).length + 1)
		return ERROR;	             //i值不合法

	if ((*L).length >= (*L).listsize)   //若存储空间已满，需开辟新空间 
	{
		newbase = (LElemType_Sq *)realloc((*L).elem, ((*L).listsize + LIST_INCREASEMENT) * sizeof(LElemType_Sq));
		if (!newbase)
		{
			exit(OVERFLOW);
			printf("chucuo");
		}

		(*L).elem = newbase;
		(*L).listsize += LIST_INCREASEMENT;
	}

	q = &(*L).elem[i - 1];
	p = &(*L).elem[(*L).length - 1];

	for (; p >= q; --p)
	{
		*(p + 1) = *p;
	}

	*q = e;
	(*L).length++;

	return OK;
}


Status ListDelete_Sq(SqList *L, int i, LElemType_Sq *e)
{
	if (i<1 || i>(*L).length)
		return ERROR;

	LElemType_Sq *p = L->elem + i - 1, //p为被删除元素的位置 
		*q = L->elem + (*L).length - 1;  //表尾元素位置 

	*e = *p;

	for (++p; p <= q; ++p)
		*(p - 1) = *p;     //被删元素之后的元素左移

	L->length--;           //表长减1

	return OK;

}

//(12)用visit函数访问顺序表L。
Status ListTraverse_Sq(SqList L, void(Vist)(LElemType_Sq))
{
	int i;
	printf("[ ");
	for (i = 0; i < L.length; i++)
		Vist(L.elem[i]);
	printf("]");

	return OK;
}

#endif // ! 

