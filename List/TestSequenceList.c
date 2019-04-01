#include "SqListImplement.h"
#include "List_Algorithm.h"
#include <time.h>
#include "MySort.h"

/* 测试调用的函数原型 */
Status CmpGreater(LElemType_Sq e, LElemType_Sq data);
//data>e, 返回TRUE，否则返回FALSE

void PrintElem(LElemType_Sq e);
//测试函数，打印整型

const int NUM = 20;
int main01(int argc, char ** argv)
{
	//LElemType_Sq e;


	/*产生随机数*/
	//srand((unsigned int)time(NULL));
	/*
	printf("▼1\n▲函数 InitList_Sq 测试...\n");   //1.函数InitList_Sq测试
	{
		printf("初始化顺序表 L ...\n");
		InitList_Sq(&L);
		printf("\n");
	}
	PressEnter;

	printf("▼4\n▲函数 ListEmpty_Sq 测试...\n"); //4.函数ListEmpty_Sq测试
	{
		ListEmpty_Sq(L) ? printf("L 为空！！\n") : printf("L 不空！！ \n");
		printf("\n");
	}
	PressEnter;


	printf("▼10\n▲函数 ListInsert_Sq 测试...\n");//10.函数ListInsert_Sq测试
	{
		for (i = 1; i <= 6; i++)
		{
			printf("作为示范，在L第 %d 个位置插入 \"%d\"...\n", i, 2 * i);
			ListInsert_Sq(&L, i, 2 * i);
		}
		printf("\n");
	}
	PressEnter;

	printf("▼12\n▲函数 ListTraverse_Sq 测试...\n");  //12.函数ListTraverse_Sq测试
	{
		printf(" L 中的元素为:L = ");
		ListTraverse_Sq(L, PrintElem);
	}
	PressEnter;
	*/
#if 0
	SqList La, Lb;
	LElemType_Sq a[5] = { 7,2,3,1,2 };
	LElemType_Sq b[7] = { 8,2,3,1,4,5,11 };

	int i;
	InitList_Sq(&La);
	for (i = 1; i <= 5; i++)
	{
		ListInsert_Sq(&La, i, a[i - 1]);
	}
	printf("La=");
	ListTraverse_Sq(La, PrintElem);

	InitList_Sq(&Lb);


	for (i = 1; i <= 7; i++)
	{
		ListInsert_Sq(&Lb, i, b[i - 1]);
	}
	printf("\nLb=");
	ListTraverse_Sq(Lb, PrintElem);


	Union(&La, Lb);
	printf("\nLa U Lb= ");
	ListTraverse_Sq(La, PrintElem);


	int i;

	InitList_Sq(&La);
	for (i = 1; i <= 5; i++)
		ListInsert_Sq(&La, i, a[i - 1]);

	InitList_Sq(&Lb);
	for (i = 1; i <= 7; i++)
		ListInsert_Sq(&Lb, i, b[i - 1]);

	printf("La=");
	ListTraverse_Sq(La, PrintElem);
	printf("\n");
	printf("Lb=");
	ListTraverse_Sq(Lb, PrintElem);
	printf("\n");

	printf("La=LaULb=");
	Union(&La, Lb);
	ListTraverse_Sq(La, PrintElem);
	printf("\n\n");

	PressEnter;
#endif

	SqList La;
	//Lb, Lc;
	LElemType_Sq a[10] = { 5,12,5,2,5,5,5,8,5,13 };
	LElemType_Sq b[10] = { 8,2,3,1,7,5,11,23,17,9 };

	int i;
	LElemType_Sq e;
	InitList_Sq(&La);
	for (i = 1; i <= 10; i++)
		ListInsert_Sq(&La, i, a[i - 1]);

	ListTraverse_Sq(La, PrintElem);

	//1、QuickSort(0, 4, &La);
	//2、BubbleSort_Sq(&La);
	//3、BubbleSortBothWay(&La);
	//4、del_Min_Sq(&La, &e);
	//5、Reverse_Sq(&La);
	//6、del_x_Sq_1(&La, 3);
	//7、del_x_Sq_2(&La, 2);
	//8、del_x_Sq_3(&La, 2);

	//9、QuickSort_Recur(0, 12, &La);
	// del_s_t(&La, 2, 3);


	//10、del_s_t_2(&La, 3, 5);

	//11、QuickSort_Recur(0, 12, &La);
	//del_same_sq(&La);


	//QuickSort_Recur(0, 13, &La);
	//ListTraverse_Sq(La, PrintElem);
	//printf("\n");
	//Find_X_Sq(&La, 6);


	//Exchange2(&La, 6, 14);


	//Exchange(&La, 7, 7);





	/*InitList_Sq(&Lb);
	for (i = 1; i <= 7; i++)
		ListInsert_Sq(&Lb, i, b[i - 1]);*/

		//MergeSeList_1(La, Lb, &Lc);
		//ListTraverse_Sq(Lc, PrintElem);

	system("pause");

	return 0;
}

Status CmpGreater(LElemType_Sq e, LElemType_Sq data)
{
	return data > e ? TRUE : FALSE;
}

void PrintElem(LElemType_Sq e)
{
	printf("%d ", e);
}