#ifndef ALGORITHMPROTOTYPE_H
#define ALGORITHMPROTOTYPE_H

#include "SqListImplement.h"


//求两个线性表并集 (01)算法2.1：A=A∪B。
void Union(SqList *La, SqList Lb);


//(02)判断两元素是否相等。
Status equal(LElemType_Sq e1, LElemType_Sq e2);


/*顺序表的归并算法
  将两个有序顺序表合并成一个新的有序顺序表，并由函数返回结果顺序表。
*/
void MergeSeList_1(SqList La, SqList Lb, SqList *Lc);


/*
从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删元素的值。注意：只删除第一个最小的值
空出的位置由最后一个元素填补，若顺序表为空则显示出错信息并退出运行
*/
Status del_Min_Sq(SqList *L, LElemType_Sq *e);


//将顺序表的所有元素逆置，算法的空间复杂度为O(1)。
void Reverse_Sq(SqList *L);


//长度为n的顺序表L，删除线性表中所有值为x的数据元素。时间复杂度为0(n)、空间复杂度为0(1)
void del_x_Sq_1(SqList *L, LElemType_Sq x);

void del_x_Sq_2(SqList *L, LElemType_Sq x);

void del_x_Sq_3(SqList *L, LElemType_Sq x);


//从有序顺序表中删除其值在给定值s与t之间（要求s<t)的所有元素，
//如果s或t不合理 或者顺序表为空则显示出错信息并退出运行。(注意：是有序表)
Status del_s_t(SqList *L, LElemType_Sq s, LElemType_Sq t);


//从顺序表中删除其值在给定值s与t之间（包含s和t, 要求s < t)的所有元素，
//如果s或t不合理或者顺序表为空则显示出错信息并退出运行。
Status del_s_t_2(SqList *L, LElemType_Sq s, LElemType_Sq t);


//**从有序顺序表中删除所有其值重复的元素，使表中所有元素的值均不同。
Status del_same_sq(SqList *L);


/*
已知在一维数组A[m+n]中依次存放着两个线性表(a_1, a_2, a_3, ⋯ a_m )和(b_1, b_2, b_3,⋯ b_n )。
试编写一个函数，将数组中两个顺序表的位置互换，即将(b_1, b_2, b_3, ⋯ b_n  )放在(a_1, a_2, a_3, ⋯ a_m)的前面。
*/
Status Reverse_Sq_2(SqList *L, int left, int right);
void Exchange(SqList *L, int m, int n);

//线性表(a_1,a_2,a_3,a_n⋯)中元素递增有序且按顺序存储于计算机内。要求设计一算法完成用最少时间在表中查找数值为X的元素，
//若找到将其与后继元素位置相交换，若找不到将其插入表中并使表中元素仍递增有序。
void Find_X_Sq(SqList *L, LElemType_Sq x);



/*
将n (n>1)个整数存放到一维数组R中。将R中保存的序列循环左移p (0<p<n)个位置，
即将R中的数据由（X0, X1，… ，Xn-1 ) 变换为(Xp, Xp+1，…，Xn-1, X0, X1, …, Xp-1)。
*/
void Reverse_Sq_3(SqList *L, int left, int right);
void Exchange2(SqList *L, int m, int n);


/*
一个长度为L (L>1)的升序序列S,处在第「L/2 个位置的数称为S的中位数。例如，
若序列Sl= ( 11，13，15，17, 19),则S1的中位数是15,两个序列的中位数是含它们所有元素的升序序列的中位数。
例如，若S2= (2, 4, 6，8, 20),则S1和S2的中位数是11。
现在有两个等长升序序列A和B,试设计一个在时间和空间两方面都尽可能高效的算法，找出两个序列A和B的中位数。
*/
void FindMedian(SqList La, SqList Lb, LElemType_Sq *e);



/*
已知一个整数序列 A= (a_0,a_1,⋯,a_(n−1) ),其中 0≤a_i<n  (0≤ⅈ<n)。
若存在 a_(p_1 )=a_(p_2 )=…=a_Pm=x 且m>n∕〖 2 〗 (0≤Pk<n,1≤k≤m),则称x为A的主元素。
例如 A= ( 0, 5, 5, 3, 5, 7, 5, 5)，则 5为主元素；又如A= (0, 5, 5, 3， 5, 1, 5，7 )，则A中没有主元素。
假设A中的n个元素保存在一个一维数组中，请设计一个尽可能高效的算法，找出A的主元素.若存在主元素，则输出该元素；否则输出-1。
*/
Status FindMainElem(SqList L, LElemType_Sq *e);




#endif // !ALGORITHMPROTOTYPE_H
