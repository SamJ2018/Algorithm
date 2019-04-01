﻿/*
	静态链表相关数据结构
*/

#ifndef STATICLINKEDLIST_H
#define STATICLINKEDLIST_H

#include <stdlib.h>  //提供malloc、realloc、free、exit原型
#include "../HeaderFile/Status.h"

#define MAXSIZE 1000  //静态链表的最大长度

typedef int SLinkList;  //静态链表类型
typedef int LElemType_S;

typedef struct
{
	LElemType_S data;
	int cur;	//cur是游标，做指针用，区别于数组下标 
}Component[MAXSIZE];

/* 全局变量 */
Component SPACE;    //静态链表空间 

/*  静态链表函数列表 */
//(01)算法2.14：将一维数组SPACE中各分量链成一个大的备用空间。
void InitSpace_SL();

//(02)算法2.15：为插入数据申请空间。
int Malloc_SL();

//(03)算法2.16：将下标为k的空闲结点回收。 
void Free_SL(int k);

//(04)初始化静态链表，建立头结点。
int InitList_SL(SLinkList *H);

//(05)置空。
Status ClearList_SL(SLinkList H);

//(06)销毁。
void DestroyList_SL(SLinkList *H);

//(07)判空。
Status ListEmpty_SL(SLinkList H);

//(08)求长。
int ListLength_SL(SLinkList H);

//(09)取值。
Status GetElem_SL(SLinkList H, int i, LElemType_S *e);

//(10)算法2.13：返回元素e的位序。
int LocateElem_SL(SLinkList H, LElemType_S e);

//(11)前驱。
Status PriorElem_SL(SLinkList H, LElemType_S cur_e, LElemType_S *pre_e);

//(12)后继。
Status NextElem_SL(SLinkList H, LElemType_S cur_e, LElemType_S *next_e);

//(13)插入。
Status ListInsert_SL(SLinkList H, int i, LElemType_S e);

//(14)删除。
Status ListDelete_SL(SLinkList H, int i, LElemType_S *e);

//(15)访问。
Status ListTraverse_SL(SLinkList H, void(Visit)(LElemType_S));
#endif // !STATICLINKEDLIST_H
