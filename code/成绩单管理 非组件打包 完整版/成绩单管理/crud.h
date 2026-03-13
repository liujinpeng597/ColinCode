#pragma once
#include "loadcom.h"
/*成绩管理子程序*/
/*成绩的数据模型*/
typedef struct score
{
	char name[28];//姓名
	char stuNum[20];//学号
	int math;
	int english;
	int chinese;
	int del;//逻辑删除标记 0 不删除 1 删除
} SCORE, * P_Score;
/*成绩单 列表*/
extern PLinkedList listScore;
/*初始化数据*/
void initData();
/*查询所有的成绩 ，按学号排序*/
void showAllScore();

/*输入成绩*/
P_Score inputNewScore();

/*在堆区申请空间 存储成绩*/
P_Score createScore(const char* name, const char* stuNum,
	int math, int english, int chinese);

/*追加到文件 ： ab方式 */
void appendToFile(P_Score ps);
/*增加新成绩*/
void addNewScore();
/*更新一条*/
void updateScore();
/*删除成绩*/
void deleteScore();
/*
查询一条
index:形参返回 符号的下标号
返回： 复合学号的 成绩
*/
P_Score queryOneScore(int* const index);
/*更新数据到文件*/
void updateToFile(P_Score p, int index);
