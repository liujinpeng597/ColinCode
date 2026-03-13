#pragma once
#define IMPORT_SUCCESS 1
#define IMPORT_ERR 0
#define EXPORT_SUCCESS 1
#define EXPORT_ERR 0

/*显示导入的用户界面*/
void showImportUI();

/*导入数据
参数：数据的存储来源
返回：是否成功 0 失败,1成功
*/
int importData(const char* dataPath);

/*导出界面*/
void showExportUI();
/*导出数据
参数：数据的存放位置
返回：是否成功 0 失败,1成功
*/
int exportData(const char* dataPath);
