#pragma once
/*排序规则函数*/
/*学号比较规则*/
int ruleStuNumOrder(void* s1, void* s2);
/*按学号的升序排序*/
void stuNumOrder();

/*数学比较规则*/
int ruleMathOrder(void* s1, void* s2);
/*按数学的 成绩 降序排序*/
void mathOrder();

/*英语比较规则*/
int ruleEnglishOrder(void* s1, void* s2);
/*按英语的 成绩 降序排序*/
void englishOrder();

/*语文比较规则*/
int ruleChineseOrder(void* s1, void* s2);
/*按语文的 成绩 降序排序*/
void chineseOrder();

/*总成绩比较规则*/
int ruleAllScoreOrder(void* s1, void* s2);
/*按总成绩的降序排序*/
void allScoreOrder();
