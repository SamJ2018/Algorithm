#ifndef LINKLISTALGORITHM_H
#define LINKLISTALGORITHM_H

#include "LinkedListImplement.h"

/*
(01)算法2.12：C=A+B，且保持元素相对位置不变。  
Lc利用La的头结点，Lb中结点均插入新链表Lc中
*/
void MergeList(LinkList La, LinkList *Lb, LinkList *Lc)
{
	LinkList pa, pb, pc;

	pa = La->next;
	pb = (*Lb)->next;
	pc = *Lc = La;            //用La的头结点作为Lc的头结点     

	while (pa && pb)
	{
		if (pa->data <= pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}

	pc->next = pa ? pa : pb;   //插入剩余段 

	free(*Lb);                 //释放Lb的头结点
	*Lb = NULL;
}

void MergeList2(LinkList La, LinkList *Lb, LinkList *Lc)
{
	LinkList pa, pb, pc;

	pa = La->next;
	pb = (*Lb)->next;
	pc = *Lc = La;

	while (pa && pb)
	{
		if (pa->data <= pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
	}

}

/*递归算法，删除不带头结点的单链表L中所有值为x的结点。*/
void DeleteXRecursion_L(LinkList *L, LElemType_L x)
{
	//递归实现在单链表L中删除值为x的结点
	if ((*L) == NULL)
		return;

	LNode *p;

	if ((*L)->data == x)
	{
		p = (*L);
		(*L) = (*L)->next;
		free(p);
		DeleteXRecursion_L(L, x);
	}
	else
		DeleteXRecursion_L(&(*L)->next, x);
}


/*1、在带头结点的单链表L中，删除所有值为x的结点，并释放其空间，假设值为x的结点不唯一，试编写算法以实现上述操作。*/
void DeleteX_L(LinkList *L, LElemType_L x)
{
	LNode *pre, *p;

	if (*L)
	{
		pre = *L;
		while ((p = pre->next))
		{
			if (p->data == x)
			{
				pre->next = p->next;
				free(p);
			}
			else
				pre = pre->next;
		}
	}
}
/*2、使用尾插法*/
void DeleteX_L2(LinkList *L, LElemType_L x)
{
	//带头结点
	LNode *p = (*L)->next,
		*r = *L, *q; //r为工作指针

	while (p != NULL)
	{
		if (p->data != x)
		{
			r->next = p;
			r = p;
			p = p->next;   //继续扫描
		}
		else
		{
			//*p结点值为x时将其释放掉
			q = p;
			p = p->next;  //继续扫描链表
			free(q);      //释放空间
		}
	}//while
	r->next = NULL; //插入结束后置尾结点指针为NULL
}

/*设L为带头结点的单链表，编写算法实现从尾到头反向输出每个结点的值。有问题，多打印一个*/
void print_reverse_L(LinkList L)
{
	if (L->next != NULL)
		print_reverse_L(L->next);

	printf("%d", L->data);
}

/*试编写在带头结点的单链表L中删除一个最小值结点的高效算法（假设最小值结点是唯一的）。*/
void DeleteMin_L(LinkList *L)
{
	LNode *pre, *p;
	LNode *minpre, *minp;

	if (!(*L))
		return;

	minpre = pre = *L,
		minp = p = pre->next;

	while (p)
	{
		if (p->data < minp->data)
		{
			minp = p;
			minpre = pre;
		}
		pre = p;
		p = p->next;
	}

	if (minp)
	{
		minpre->next = minp->next;
		free(minp);
		minp = NULL;
	}
	/*
		 //L是带头结点的单链表，本算法删除其最小值结点
 
    LNode *pre = L, *p = L->next;    //p为工作指针，pre指向其前驱
    LNode *minpre = pre, *minp = p;  //保存最小值结点及其前驱
 
    while (p != NULL)
    {
        if (p->data < minp->data)
        {
            minp = p;             //找到比之前找到的最小值结点更小的结点
            minpre = pre;
        }
        pre = p;                  //继续扫描下一个结点
        p = p->next;
    }//while
    minpre->next = minp->next;      //删除最小值结点
    free(minp);
    return L;
	*/
}

/*试编写算法将带头结点的单链表就地逆置，所谓"就地”是指辅助空间复杂度为0(1)。*/
void Reverse_L(LinkList *L)
{
	if (!(*L))
		return;

	LNode *p = (*L)->next, *q;

	(*L)->next = NULL;

	while (p)
	{
		q = p->next;
		p->next = (*L)->next;

		(*L)->next = p;

		p = q;
	}
}
void Reverse_L2(LinkList *L)
{
	LNode *p = (*L)->next, *q = p->next, *delem;
	p->next = NULL;

	while (q)   //q为空时，p为最后一个元素
	{
		delem = p;   //要反转的元素
		p = q;
		q = q->next;
		p->next = delem;
	}
	(*L)->next = p;
}

/*  ***有一个带头结点的单链表L,设计一个算法使其元素递增有序。*/
void AscendOrder(LinkList *L)
{
	LNode *p = (*L)->next, *r = p->next, *pre;
	p->next = NULL;
	p = r;

	while (p)
	{
		r = p->next;
		pre = *L;

		while (pre->next != NULL && pre->next->data < p->data)
			pre = pre->next;

		p->next = pre->next;
		pre->next = p;
		p = r;
	}
}


/*
设在一个带表头结点的单链表中所有元素结点的数据值无序，
试编写一个函数，删除表中所有介于给定的两个值（作为函数参数给出）之间的元素（若存在）。
*/
void del_s_t_l(LinkList *L, LElemType_L s, LElemType_L t)
{
	if (!(*L))
		return;
	LNode *pre = *L, *p = pre->next;
	LNode *r;
	while (p)
	{
		if (p->data > s && p->data < t)
		{
			r = p;
			p = p->next;
			pre->next = p;
			free(r);
		}
		else {
			pre = p;
			p = p->next;
		}
	}
}


/*
给定两个单链表，编写算法找出两个链表的公共结点。
两个链表成Y形状，一旦有一个结点相同，则后面的都相同。
*/
LinkList Search_List_Common(LinkList La, LinkList Lb)
{
	LNode *shortlist, *longlist;
	int len_a = ListLength_L(La), len_b = ListLength_L(Lb);
	int dist;

	if (len_a > len_b)
	{
		longlist = La->next;
		shortlist = Lb->next;
		dist = len_a - len_b;
	}
	else
	{
		longlist = Lb->next;
		shortlist = La->next;
		dist = len_b - len_a;
	}

	while (dist--)
	{
		longlist = longlist->next;
	}

	while (longlist != NULL)
	{
		if (longlist->data == shortlist->data)
			return longlist;
		else
		{
			longlist = longlist->next;
			shortlist = shortlist->next;
		}
	}//while


	return NULL;
}

/*给定一个带表头结点的单链表，设head为头指针，结点的结构为（data, next), data为 整型元素，next为指针，
试写出算法：按递增次序输出单链表中各结点的数据元素，并释放结点所占的存储空间（要求：不允许使用数组作为辅助空间）。*/
void PrintAndDelete(LinkList *L, void(Print)(LElemType_L))
{
	LNode *p, *minpre, *minp;

	while ((*L)->next)
	{
		minpre = *L;
		p = (*L)->next;

		while (p->next)
		{
			if (p->next->data < minpre->next->data)
				minpre = p;
			p = p->next;
		}//while

		if (minpre->next)
			Print(minpre->next->data);

		minp = minpre->next;
		minpre->next = minp->next;
		free(minp);
	}//while

	free(*L);
}

/*
将一个带头结点的单链表A分解为两个带头结点的单链表A和B，
使得A表中含有原表中序号为奇数的元素，而B表中含有原表中序号为偶数的元素，且保持其相对顺序不变。
*/
void Disassemble(LinkList *La, LinkList *Lb)
{
	*Lb = (LinkList)malloc(sizeof(LNode));
	if (!(*Lb))
		return;

	LNode *pa = *La, *pb = *Lb;
	LNode *p = (*La)->next;   //工作指针，遍历整个链表

	int count = 1;

	while (p)
	{
		if (count % 2 == 0)
		{
			pb->next = p;
			pb = p;
		}
		else
		{
			pa->next = p;
			pa = p;
		}
		p = p->next;
		count++;
	}
	pa->next = NULL;
	pb->next = NULL;
}

/*
设C={a1，b1, a2，b2，…，an, bn}为线性表，
采用带头结点的hc单链表存放，设计一个就地算法，将其拆分为两个线性表，使得A={al，a2,…，an}, B={bn,…，b2, b1}
*/


/*
在一个递增有序的线性表中，有数值相同的元素存在。若存储方式为单链表，设计算法去掉数值相同的元素，使表中不再有重复的元素。
例如（7，10，10, 21，30, 42, 42, 42, 51，70)将变作（7，10，21，30, 42，51，70)。
*/



/*
假设有两个按元素值递增次序排列的线性表，均以单链表形式存储。
请编写算法将这两个单链表归并为一个接元素值递减次序排列的单链表，并要求利用原来两个单链表的结点存放归并后的单链表。
*/


/*
设A和B是两个单链表（带头结点），其中元素递增有序。
设计一个算法从A和B中公共元素产生单链表C,要求不破坏A、B的结点。
*/


/*
已知两个链表A和B分别表示两个集合，其元素递增排列，编制函数，求A与B的交集，井存放于A链表中。
*/


/*
两个整数序列A=al, a2, a3，…，am和B=b1, b2, b3,…，bn已经存入两个单链表 中，
设计一个算法，判断序列B是否是序列A的连续子序列。
*/


/*
设计一个算法用于判断带头结点的循环双链表是否对称。
*/


/*
有两个循环单链表，链表头指针分别为h1和h2,编写一个函数将链表h2链接到链表h1之后，要求链接后的链表仍保持循环链表形式。
*/

/*
设有一个带头结点的循环单链表，其结点值均为正整数。
设计一个算法，反复找出单链表中结点值最小的结点并输出，然后将该结点从中删除，直到单链表空为止，再删除表头结点。
*/


/*
设头指针为L的带有表头结点的非循环双向链表，其每个结点中除有pred (前驱指针）、 data (数据）和next (后继指针）域外，还有一个访问频度域freq。
在链表被启用前，其值均初 始化为零，每当在链表中进行一次Locate(L, x)运算时，令元素值为x的结点中freq域的值增1， 并使此链表中结点保持按访问频度非增（递减）的顺序排列，同时最近访问的结点排在频度相同 的结点的前面，以便使频繁访问的结点总是靠近表头。
试编写符合上述要求的Locate(L, x)运算 的算法，该运算为函数过程，返回找到结点的地址，类型为指针型。
*/

/*
已知一个带有表头结点的单链表，结点结构为
data	      link
假设该链表只给出了头指针list。在不改变链表的前提下.
请设计一个尽可能高效的算法， 查找链表中倒数第k个位置上的结点（k为正整数)。若查找成功，算法输出该结点的data域的值，并返回1;否则，只返回0。要求：

*/


/*
假定采用带头结点的单链表保存单词，当两个单词有相同的后缀时，则可共享相同的后缀存储空间，
例如，“loading”和“being”的存储映像如下图所示.
设strl和str2分别指向两个单词所在单链表的头结点，链表结点结构为| data | next |,
请设计一个时间上尽可能高效的算法，找出由strl和str2所指向两个链表共同后缀的起始位置（如图中 字符i所在结点的位置p).要求：
*/


/*
用单链表保存m个整数，结点的结构为：[data][link],且|data| < n (n为正整数）。现要求设 计一个时间复杂度尽可能高效的算法，对于链表中data的绝对值相等的结点，仅保留第一次出现 的结点而删除其余绝对值相等的结点。
例如，若给定的单链表head如下：
*/

#endif // !LINKLISTALGORITHM_H
