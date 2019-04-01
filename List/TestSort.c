#include <stdio.h>
typedef int ElemType;
int patition2(int low, int high, ElemType *L)
{
	ElemType pivot = L[low];

	while (low < high)
	{
		while (low < high && pivot <= L[high]) --high;
		L[low] = L[high];
		while (low < high && pivot >= L[low])++low;
		L[high] = L[low];
	}
	L[low] = pivot;
	return low;
}

void QuickSort2(int begin, int end, ElemType *L)
{
	ElemType pivot;
	if (begin < end)
	{
		pivot = patition2(begin, end, L);
		QuickSort2(begin, pivot - 1, L);
		QuickSort2(pivot + 1, end, L);
	}
}


int main02()
{
	int ch[] = { 2,6,3,23,7,4,9,3 };

	QuickSort2(0, 7, ch);

	for (int i = 0; i < 8; i++)
	{
		printf("%d ", ch[i]);
	}

	system("pause");
}