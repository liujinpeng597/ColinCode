#define _CRT_SECURE_NO_WARNINGS
#include "data_manage.h"
#include<stdio.h>
#include"crud.h"
void showImportUI()
{
	printf("请输入导入数据的来源：");
	char path[50];
	scanf_s("%s", path, 50);
	if (importData(path) == IMPORT_SUCCESS)
	{
		printf("\n数据导入成功\n");
	}
	else
	{
		printf("\n数据导入失败\n");
	}
}

int importData(const char* dataPath)
{
	FILE* pImportData = fopen(dataPath, "rt");
	if (pImportData == NULL) {
		return IMPORT_ERR;
	}
	FILE* pData = fopen(".\\data.db", "ab");
	if (pData != NULL)
	{
		SCORE temp;
		while (fscanf_s(pImportData, "%s%s%d%d%d"
			, temp.name, 28
			, temp.stuNum, 20
			, &temp.math
			, &temp.english
			, &temp.chinese) >= 5)
		{
			temp.del = 0;
			//存入文件
			fwrite(&temp, sizeof(SCORE), 1, pData);
			//放入链表
			P_Score ps = (P_Score)malloc(sizeof(SCORE));
			memcpy(ps, &temp, sizeof(SCORE));
			add(listScore, ps);
		}
		fclose(pData);
	}
	fclose(pImportData);
	return IMPORT_SUCCESS;
}

void showExportUI()
{
	printf("导出的位置：");
	char path[50];
	scanf_s("%s", path, 50);
	if (exportData(path) == EXPORT_SUCCESS)
	{
		printf("\n数据导出成功\n");
	}
	else
	{
		printf("\n数据导出失败\n");
	}
}

int exportData(const char* dataPath)
{
	FILE* pExport = fopen(dataPath, "wt");
	if (pExport != NULL)
	{
		fprintf(pExport, "\n%-8s%-10s%6s%6s%6s\n", "姓名", "学号", "数学", "英语", "语文");
		//把链表的数据 向文件输出
		iterator(listScore);
		while (hasNext(listScore))
		{
			P_Score p = (P_Score)next(listScore);
			if (p->del == 0)
			{
				fprintf(pExport, "%-8s%-10s%6d%6d%6d\n", p->name, p->stuNum,
					p->math, p->english, p->chinese);
			}
		}

		fclose(pExport);
		return EXPORT_SUCCESS;
	}
	return EXPORT_ERR;
}
