#ifndef SEQUENCELIST_H
#define SEQUENCELIST_H

#include <stdio.h>
#include <stdlib.h>
#include "../HeaderFile/Status.h"

/*宏定义*/
#define LIST_INI_SIZE 100      //顺序表存储空间的初始分配量 
#define LIST_INCREASEMENT 30   //顺序表存储空间的分配增量

/*顺序表类型定义*/
#ifndef LELEMTYPE_SQ
#define LELEMTYPE_SQ

typedef int LElemType_Sq;      //顺序表元素类型

#endif // !LELEMTYPE_SQ


typedef struct
{
	LElemType_Sq *elem;    //存储空间基址（指向第一个结点的指针）
	int length;            //当前顺序表长度 
	int listsize;          //当前分配的存储容量 
}SqList;                   //顺序表0号单元正常使用 

/* 顺序表函数列表 */


//(01)算法2.3：初始化空顺序表L
Status InitList_Sq(SqList *L);

//(02)清空顺序表L。
void ClearList_Sq(SqList *L);

//(03)销毁顺序表L。
void DestroyList_Sq(SqList *L);

//(04)判断顺序表L是否为空。
Status ListEmpty_Sq(SqList L);

//(05)返回顺序表L中元素个数。
int ListLength_Sq(SqList L);

//(06)用e接收顺序表L中第i个元素。
Status GetElem_Sq(SqList L, int i, LElemType_Sq *e);

//(07)算法2.6：返回顺序表L中首个与e满足Compare关系的元素位序。
int LocateElem_Sq(SqList L, LElemType_Sq e, Status(Compare)(LElemType_Sq, LElemType_Sq));

//(08)用pre_e接收cur_e的前驱。 
Status PriorElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *pre_e);

//(09)用next_e接收cur_e的后继。 
Status NextElem_Sq(SqList L, LElemType_Sq cur_e, LElemType_Sq *next_e);

//(10)算法2.4：在顺序表L的第i个位置上插入e。
Status ListInsert_Sq(SqList *L, int i, LElemType_Sq e);

//(11)算法2.5：删除顺序表L上第i个位置的元素，并用e返回。
Status ListDelete_Sq(SqList *L, int i, LElemType_Sq *e);

//(12)用visit函数访问顺序表L。
Status ListTraverse_Sq(SqList L, void(Vist)(LElemType_Sq));



#endif // !1
