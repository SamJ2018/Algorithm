#ifndef MYSORT_H
#define MYSORT_H
#include "SqListImplement.h"
#define StackSize 100

int partition_random(SqList *L, int low, int high);
//栈
typedef struct
{
	LElemType_Sq *data;
	int top;
}Stack;

void InitStack(Stack *s)
{
	(*s).data = (LElemType_Sq *)malloc(StackSize * sizeof(LElemType_Sq));
	if (!(*s).data)
		return;

	(*s).top = -1;
}

void Stack_pop(Stack *st, LElemType_Sq *e)
{
	if (st->top != -1)
	{
		*e = st->data[st->top--];
	}
}

void Stack_push(Stack *st, LElemType_Sq e)
{
	st->data[++st->top] = e;
}

int stack_empty(Stack st)
{
	if (st.top == -1)
		return 1;
	else
		return 0;
}

typedef int ElemType;
//快速排序
int partition(int low, int high, SqList *L)
{
	ElemType pivot = L->elem[low];

	while (low < high)
	{
		while (low <= high && pivot <= L->elem[high]) --high;
		L->elem[low] = L->elem[high];

		while (low < high && pivot >= L->elem[low]) ++low;
		L->elem[high] = L->elem[low];
	}

	L->elem[low] = pivot;
	return low;
}

void QuickSort_Recur(int begin, int end, SqList *L)
{
	ElemType pivot;
	if (begin < end)
	{
		pivot = partition(begin, end, L);
		QuickSort_Recur(begin, pivot - 1, L);
		QuickSort_Recur(pivot + 1, end, L);
	}
}


//非递归快排
void QuickSort(int begin, int end, SqList *L)
{
	Stack s;
	InitStack(&s);
	Stack_push(&s, begin);
	Stack_push(&s, end);

	while (!stack_empty(s))
	{
		Stack_pop(&s, &end);
		Stack_pop(&s, &begin);

		int pivot = partition(begin, end, L);

		if (pivot - 1 > begin)
		{
			Stack_push(&s, begin);
			Stack_push(&s, pivot - 1);
		}

		if (pivot + 1 < end)
		{
			Stack_push(&s, pivot + 1);
			Stack_push(&s, end);
		}
	}
}


void Swap_Sq(LElemType_Sq *La, LElemType_Sq *Lb)
{
	LElemType_Sq temp = *La;
	*La = *Lb;
	*Lb = temp;
}



//快速排序的划分算法，每次选取的枢轴值都是随机地从当前子表中选择的。
//思想：先随机求出枢轴的下标，然后将枢轴值与A[low]交换。
//测试不成功！
int partition_random(SqList *L, int low, int high)
{
	int rand_index = low + rand() % (high - low + 1);
	Swap_Sq(&L->elem[rand_index], &L->elem[low]);

	LElemType_Sq pivot = L->elem[low];
	//使得表A[low...i]中的所有元素小于pivot，初始为空表
	int i = low;

	//从第二个元素开始寻找小于基准的元素
	for (int j = low + 1; j <= high; j++)
		if (L->elem[j] < pivot)
			Swap_Sq(&L->elem[++i], &L->elem[j]);

	return i;
}


//普通冒泡排序
void BubbleSort_Sq(SqList *L)
{
	int La_len = ListLength_Sq(*L), i, j, flag;

	for (flag = 1, i = 0; flag&&i < La_len; i++)
	{
		flag = 0;
		for (j = 0; j < La_len - i - 1; j++)
		{
			if (L->elem[j] > L->elem[j + 1])
			{
				Swap_Sq(&L->elem[j + 1], &L->elem[j]);
				flag = 1;
			}
		}
	}
}

//双向冒泡
void BubbleSortBothWay(SqList *L)
{
	int len = ListLength_Sq(*L), low = 0, high = len - 1;
	int i, flag = 1;

	while (low < high && flag)
	{
		flag = 0;
		for (i = 0; i < high; i++)
			if (L->elem[i] > L->elem[i + 1])
			{
				flag = 1;
				Swap_Sq(&L->elem[i], &L->elem[i + 1]);
			}
		--high;

		for (i = high; i > low; --i)
		{
			if (L->elem[i] > L->elem[i + 1])
			{
				flag = 1;
				Swap_Sq(&L->elem[i], &L->elem[i + 1]);
			}
		}
		++low;
	}
}


#endif // !1
