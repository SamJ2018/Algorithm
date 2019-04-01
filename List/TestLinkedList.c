#include "LinkList_Algorithm.h"

void Vist(LElemType_L);
#define MAX_NUM 20
int len;


const int array[MAX_NUM] = { 2,3,5,8,13,22,7,29,5,35,
							4,3,17,11,26,13,22,3,20,18 };
const int arry2[MAX_NUM] = { 3,5,8,4,22,18,14,27,23,10,
							17,29,18,11,26,13,22,3,20,18 };

Status CreateList_arrary_T(LinkList *L, const int *);
Status CreateList_arrary_H(LinkList *L, const int *);

int main()
{
	LinkList La;
	LinkList Lb;
	//CreateList_NFN(&La);
	//ListTreaverse_L(La, Vist);
	//DeleteXRecursion_L(&La, 3);

	CreateList_arrary_T(&La, array);
	//CreateList_arrary_T(&Lb, arry2);
	//DeleteMin_L(&La);
	//CreateList_arrary_T(&La);

	//DeleteX_L(&La, 4);
	//DeleteX_L2(&La, 3);
	//Reverse_L2(&La);
	//AscendOrder(&La);

	//del_s_t_l(&La, 2, 8);

	//LinkList ret=Search_List_Common(La, Lb);
	//printf("%d", ret->data);
	//ListTreaverse_L(Lb, Vist);

	Disassemble(&La, &Lb);

	//PrintAndDelete(&La, Vist);

	ListTreaverse_L(La, Vist);
	ListTreaverse_L(Lb, Vist);


	system("pause");
}

void Vist(LElemType_L e)
{
	printf("%d ", e);
}


Status CreateList_arrary_H(LinkList *L, const int *arr)
{
	*L = (LinkList)malloc(sizeof(LNode));
	if (!(*L))
		exit(OVERFLOW);

	(*L)->next = NULL;
	LNode *s;

	for (int i = 0; i < MAX_NUM; i++)
	{
		s = (LNode *)malloc(sizeof(LNode));
		s->data = arr[i];
		s->next = (*L)->next;
		(*L)->next = s;
	}
}

Status CreateList_arrary_T(LinkList *L, const int *arr)
{
	(*L) = (LinkList)malloc(sizeof(LNode));
	if (!(*L))
		exit(OVERFLOW);


	LNode *q = *L, *s;

	for (int i = 0; i < MAX_NUM; i++)
	{
		s = (LNode *)malloc(sizeof(LNode));
		s->data = arr[i];
		s->next = NULL;

		q->next = s;
		q = s;
	}
	q->next = NULL;

	return OK;
}


