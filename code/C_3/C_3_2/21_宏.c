////#include <stdio.h>
//#include"a.h"
//#include"b.h"
//#define SUCCESS 0
//#define MEMORY_OUT -1
///*
//    C 语言启动的经历：
//	1：预处理期： 在这一阶段，源码中的所有预处理语句得到处理例如：#include语句所包含的文件内容替换掉语句本身，所有已定义的宏被展开。
//	2：编译期：编译器对源码进行词法分析、语法分析、优化等操作，最后生成汇编代码。
//	3：汇编期：生成机器语言代码，保存在后缀为.o的目标文件中
//	4：链接期：经过汇编以后的机器代码还不能直接运行。为了使操作系统能够正确加载可执行文件，文件中必须包含固定格式的信息头，还必须与系统提供的启动代码链接起来才能正常运行，这些工作都是由链接器来完成的。
//	5：执行期：执行.EXE文件，得到运行结果
//*/
//int main21()
//{
//	/*宏替换简称宏的格式：
//	#define 宏替换名称  替换内容
//	*/
//	/* 1 替换类型名称 对比typedef的差异*/
//	
//	/*2  替换一个函数或表达式*/
//#define T printf("hello world\n")
//	/*3 嵌套宏替换：不用循环的1000个helloworld*/
//#define A T T T T T T T T T T T
//#define B A A A A A A A A A A A
//	    
//	/*思考总结：宏的意义：增加可读性*/
//	
//	/*用宏和typedef创建一个“布尔型数据”*/
//    #define true 1
//    #define false 0
//	typedef int bool;
//	bool sex = true;
//
//	/*4 定义有参数的宏*/
//    #define ARR_LEN(arr_name) (sizeof(arr_name) / sizeof(arr_name[0]))
//    #define ARR_LEN2(arr_name,arr_type) (sizeof(arr_name) / sizeof(arr_type))
//	int arr[] = { 7,9,8,3,6,9,5,2,8,7 };
//	int len1 = ARR_LEN(arr);
//	int len2 = ARR_LEN2(arr, int);
//
//	double score[] = { 78,68,59.5,100,99.5 };
//	int len3 = ARR_LEN(score);
//	int len4 = ARR_LEN2(arr, double);
//	/*  定义能够计算任意类型数组长度的宏*/
//	 
//	return SUCCESS;
//}