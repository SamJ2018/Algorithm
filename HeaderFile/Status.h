#ifndef  STATUS_H
#define  STATUS_H

/*״̬��*/
#define TRUE		 1     //��
#define FALSE		 0     //��
#define YES			 1     //��
#define NO			 0     //��
#define OK			 1     //ͨ��
#define ERROR		 -1     //ʧ��
#define UNSUCCESS	 0	   //ʧ��
#define INFEASIBLE   -1    //������

#ifndef _MATH_H      //ϵͳ�Ѿ��д�״̬�룬�����ͻ

#define OVERFLOW -2  //��ջ����
#define UNDERFLOW -3 //��ջ����

#endif // !_MATH_H   

#ifndef NULL
#define NULL ((void *)0)
#endif // !NULL

/*״̬ʶ����*/
typedef int Status;

/*�꺯��*/
//������ͣһ��ʱ��
#define Wait(x)\
{\
	double _Loop_Num_; \
	for(_Loop_Num=0.01; _Loop_Num<=100000.0*x; _Loop_Num += 0.01)\
	;\
}//һ����ѭ��

//��Enter����
#define PressEnter\
 {\
	fflush(stdin);\
	printf("Press Enter...");\
	getchar();\
	fflush(stdin);\
 }\

#endif

