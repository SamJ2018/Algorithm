#ifndef  STATUS_H
#define  STATUS_H

/*状态码*/
#define TRUE		 1     //真
#define FALSE		 0     //假
#define YES			 1     //是
#define NO			 0     //否
#define OK			 1     //通过
#define ERROR		 -1     //失败
#define UNSUCCESS	 0	   //失败
#define INFEASIBLE   -1    //不可行

#ifndef _MATH_H      //系统已经有此状态码，避免冲突

#define OVERFLOW -2  //堆栈上溢
#define UNDERFLOW -3 //堆栈下溢

#endif // !_MATH_H   

#ifndef NULL
#define NULL ((void *)0)
#endif // !NULL

/*状态识别码*/
typedef int Status;

/*宏函数*/
//函数暂停一段时间
#define Wait(x)\
{\
	double _Loop_Num_; \
	for(_Loop_Num=0.01; _Loop_Num<=100000.0*x; _Loop_Num += 0.01)\
	;\
}//一个空循环

//摁Enter继续
#define PressEnter\
 {\
	fflush(stdin);\
	printf("Press Enter...");\
	getchar();\
	fflush(stdin);\
 }\

#endif

