////#pragma once
//
//#ifndef __def_h__
//#define __def_h__
//
//
////主要：替换，预处理阶段
//#define A 10
//
////替换多行的代码。 \作用：链接当前行和下一行，一般最后一行不加
//// \后面不能有任何的字符（空格，tab，注释等等）
//
//#define B \
//for (int i = 0;i < A;++i){\
//	cout << i << " ";\
//}\
//cout << endl;
//
////宏参数：也是一个替换的作用，没有类型
//#define C(N) \
//for (int i = 0;i < A;++i){\
//	cout << i << " ";\
//}\
//cout << endl;
//
//
////两个数乘法的功能 优点：参数有类型比较安全，自动计算求解，
//				 //缺点：效率没有宏高。
//int mul(int a, int b);
//
////用宏可以替代功能简单的函数，宏替换执行效率高。
////宏参数：不会做表达式的计算和求解，只是单纯的替换。
//#define MUL(A,B) ((A)*(B))
//
//#define mul(AA,BB) ((AA)*(BB))
//
//
//
//#endif
//
//#define D 1
//
////# 将宏参数变为字符串，加了双引号 “3”
//#define E(EE) #EE
//
////#@ 变为字符，加了单引号 ‘4’
//#define F(FF) #@FF
//
////## 用来连接
//#define G(GG) int a##GG=12345;