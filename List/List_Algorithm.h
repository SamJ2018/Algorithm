#ifndef LIST_ALGORITHM_H
#define LIST_ALGORITHM_H

#include "AlgorithmPrototype.h"


void Union(SqList *La, SqList Lb)
{
	int La_len, Lb_len;
	int i;
	LElemType_Sq e;

	La_len = ListLength_Sq(*La);
	Lb_len = ListLength_Sq(Lb);

	for (i = 1; i <= Lb_len; ++i)
	{
		GetElem_Sq(Lb, i, &e);

		if (!LocateElem_Sq(*La, e, equal))
			ListInsert_Sq(La, ++La_len, e);
	}
}

Status equal(LElemType_Sq e1, LElemType_Sq e2)
{
	return e1 == e2 ? TRUE : FALSE;
}


void MergeSeList_1(SqList La, SqList Lb, SqList *Lc)
{
	int La_len, Lb_len;
	int i, j, k;
	LElemType_Sq ai, bj;

	i = j = 1;    k = 0;

	InitList_Sq(Lc);//³õÊ¼»¯Lc

	La_len = ListLength_Sq(La);
	Lb_len = ListLength_Sq(Lb);

	while (i <= La_len && j <= Lb_len)
	{
		GetElem_Sq(La, i, &ai);
		GetElem_Sq(Lb, j, &bj);

		if (ai <= bj)
		{
			ListInsert_Sq(Lc, ++k, ai);
			++i;
		}
		else
		{
			ListInsert_Sq(Lc, ++k, bj);
			++j;
		}
	}//while

	while (i <= La_len)
	{
		GetElem_Sq(La, i++, &ai);
		ListInsert_Sq(Lc, ++k, ai);
	}

	while (j <= Lb_len)
	{
		GetElem_Sq(Lb, j++, &bj);
		ListInsert_Sq(Lc, ++k, bj);
	}
}


Status del_Min_Sq(SqList *L, LElemType_Sq *e)
{
	int len = ListLength_Sq(*L);
	if (len == 0)
		return ERROR;

	LElemType_Sq Min = L->elem[0];
	int i, pos;

	for (i = 1; i < len; i++)
	{
		if (L->elem[i] < Min)
		{
			pos = i;
			Min = L->elem[i];
		}
	}
	*e = Min;
	L->elem[pos] = L->elem[len - 1];

	L->length--;

	return OK;
}


void Reverse_Sq(SqList *L)
{
	int len = ListLength_Sq(*L);
	for (int i = 0; i < len / 2; i++)
	{
		LElemType_Sq temp = L->elem[i];
		L->elem[i] = L->elem[len - 1 - i];
		L->elem[len - 1 - i] = temp;
	}
}


void del_x_Sq_1(SqList *L, LElemType_Sq x)
{
	int len = ListLength_Sq(*L);

	for (int i = 1; i <= len; i++)
	{
		if (L->elem[i - 1] == x)
			ListDelete_Sq(L, i, &x);
	}
}

void del_x_Sq_2(SqList *L, LElemType_Sq x)
{
	int len = L->length;
	int pos = 0, count = 0;

	while (pos < len)
	{
		if (L->elem[pos] == x)
			count++;
		else
			L->elem[pos - count] = L->elem[pos];

		++pos;
	}

	L->length -= count;
}

void del_x_Sq_3(SqList *L, LElemType_Sq x)
{
	int i = 0, pos = 0;

	while (i < L->length)
	{
		if (L->elem[i] != x)
			L->elem[pos++] = L->elem[i];
		++i;
	}

	L->length = pos;
}


Status del_s_t(SqList *L, LElemType_Sq s, LElemType_Sq t)
{
	if (L->length == 0 || s >= t)
		return ERROR;

	int i, j;

	for (i = 0; i < L->length && L->elem[i] < s; ++i);
	if (i >= L->length)
		return ERROR;

	for (j = i; j < L->length && L->elem[j] <= t; ++j);

	for (; j < L->length; ++j, ++i)
		L->elem[i] = L->elem[j];

	L->length = i;

	return OK;
}


Status del_s_t_2(SqList *L, LElemType_Sq s, LElemType_Sq t)
{
	if (s >= t || L->length == 0)
		return ERROR;

	int count = 0, i = 0;
	while (i < L->length)
	{
		if (L->elem[i] >= s && L->elem[i] <= t)
			count++;
		else
			L->elem[i - count] = L->elem[i];

		i++;
	}

	L->length -= count;

	return OK;
}


Status del_same_sq(SqList *L)
{
	if (L->length == 0)
		return ERROR;

	int i = 1, pos = 0;

	for (; i < L->length; i++)
	{
		if (L->elem[i] != L->elem[pos])
			L->elem[++pos] = L->elem[i];
	}

	L->length = pos + 1;

	return OK;
}


Status Reverse_Sq_2(SqList *L, int left, int right)
{
	if (left >= right || right >= L->length)
		return ERROR;

	int mid = (left + right) / 2;
	for (int i = 0; i <= mid - left; i++)
	{
		LElemType_Sq temp = L->elem[left + i];
		L->elem[left + i] = L->elem[right - i];
		L->elem[right - i] = temp;
	}
}

void Exchange(SqList *L, int m, int n)
{
	Reverse_Sq_2(L, 0, m + n - 1);
	Reverse_Sq_2(L, 0, n - 1);
	Reverse_Sq_2(L, n, m + n - 1);
}


void Find_X_Sq(SqList *L, LElemType_Sq x)
{
	int low = 0, high = L->length - 1, mid;

	while (low <= high)
	{
		mid = (low + high) >> 1;
		if (L->elem[mid] == x)
			break;
		else if (L->elem[mid] > x)
			high = mid - 1;
		else
			low = mid + 1;
	}

	if (L->elem[mid] == x && mid != L->length - 1)
	{
		LElemType_Sq temp = L->elem[mid];
		L->elem[mid] = L->elem[mid + 1];
		L->elem[mid + 1] = temp;
	}

	if (low > high)
	{
		for (int i = L->length - 1; i > high; --i)
			L->elem[i + 1] = L->elem[i];

		L->elem[high + 1] = x;
		L->length++;
	}

}



void Reverse_Sq_3(SqList *L, int left, int right)
{
	LElemType_Sq temp;
	for (int i = 0; i <= (right - left) / 2; i++)
	{
		temp = L->elem[left + i];
		L->elem[left + i] = L->elem[right - i];
		L->elem[right - i] = temp;
	}//for
}

void Exchange2(SqList *L, int m, int n)
{
	Reverse_Sq_3(L, 0, m - 1);
	Reverse_Sq_3(L, m, n - 1);
	Reverse_Sq_3(L, 0, n - 1);
}


void FindMedian(SqList La, SqList Lb, LElemType_Sq *e)
{
	int h1 = 0, t1 = La.length - 1;
	int h2 = 0, t2 = Lb.length - 1;

	int m1, m2;

	while (h1 < t1 && h2 < t2)
	{
		m1 = (h1 + t1) >> 1;
		m2 = (h2 + t2) >> 1;

		if (La.elem[m1] == Lb.elem[m2])
			*e = La.elem[m1];

		if (La.elem[m1] < Lb.elem[m2])
		{
			if ((h1 + t1) % 2 == 0)
			{
				h1 = m1;
				t2 = m2;
			}
			else
			{
				h1 = m1 + 1;
				t2 = m2;
			}
		}
		else
		{
			if ((h2 + t2) % 2 == 0)
			{
				h2 = m2;
				t1 = m1;
			}
			else
			{
				h2 = m2 + 1;
				t1 = m1;
			}
		}
	}//while

	*e = La.elem[h1] < Lb.elem[h2] ? La.elem[h1] : Lb.elem[h2];
}

Status FindMainElem(SqList L, LElemType_Sq *e)
{
	int c, i;
	int count = 0;
	c = L.elem[0];

	for (i = 1; i < L.length; i++)
	{
		if (L.elem[i] == c)
			count++;
		else if (count > 0 && L.elem[i])
			count--;
		else
		{
			count = 1;
			c = L.elem[i];
		}
	}//for

	if (count > 0)
	{
		for (i = count = 0; i < L.length; i++)
			if (L.elem[i] == c)
				count++;
	}

	if (count > L.length / 2)
		*e = c;

	return ERROR;
}



#endif // !LIST_ALGORITHM_H

