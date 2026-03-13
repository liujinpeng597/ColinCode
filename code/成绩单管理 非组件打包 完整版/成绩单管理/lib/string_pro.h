#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
/*
功能：判断一个字符串中是否包含另一个字符串
参数：str：目标字符长串
	 substr：被查找的短字符串
返回：0 不包含 1包含
简例：int a = contains("Hello ,how are you","are");
返回 1；
*/ 
int contains(const char* str,const char *substr) ;
 
/*
功能：判断一个字符串的开头是否与另一个字符串相同
参数：str 目标字符串 substr被比较字符串
返回：0 否 1 是
简例：int a =startsWith("Hello ,how are you","Hello");
返回值：1
*/
int startsWith(const char* str,const char *substr);
 
/*
功能：判断一个字符串的结尾是否与另一个字符串相同
参数：str 目标字符串 substr被比较字符串
返回：0 否 1 是
简例：int a =endsWith("Hello ,how are you","are");
返回值：1
*/
int endsWith(const char* str,const char *substr);
 
/*
功能：从一个字符串前面寻找另一个字符串首次出现的下标
参数：str目标字符串，substr寻找字符串
返回：下标位置
简例：int a= strIndexOf("how are you","are");
返回值：4
*/
int strIndexOf(const char* str,const char* substr) ;
 
/*
功能：在一个字符串str前面开始寻找字符c首次出现的下标
参数：str目标字符串，c 被寻找的字符
返回：下标位置
简例：int a= charIndexOf("how are you",'w');
返回值：2
*/
int charIndexOf(const char* str,char c) ;
 
/*
功能：从一个字符串尾部开始寻找另一个字符串首次出现的下标
参数：str目标字符串，substr寻找字符串
返回：下标位置
简例：int a= strLastIndexOf("how do you do","do");
返回值：11
*/
int strLastIndexOf(const char* str,const char* substr) ;
 
/*
功能：在一个字符串str尾部开始寻找字符c首次出现的下标
参数：str目标字符串，c 被寻找的字符
返回：下标位置
简例：int a= charLastIndexOf("how are you",'o');
返回值：9
*/
int charLastIndexOf(const char* str,char c) ;
 
/*
功能：判断一个字符串是否空串
参数：str被检测的字符串
返回：0 不是 1 是
简例：int a = isEmpty("");
返回值 1 
*/
int isEmpty(const char* str) ;
 
/*
功能：去掉字符串中的所有空格
参数：str 需要去掉空格的字符串
返回：处理后的str
简例：
char s[] = "  how are you  ";
trimAll(s)
返回值：howareyou
*/
char* trimAll(char* str) ;
 
/*
功能：只去掉字符串左侧的所有空格
参数：str: 需要去掉左侧空格的字符串
返回：处理后的str
简例：
char s[] = "  how are you  ";
leftTrim(s)
返回值：how are you  |
*/
char* leftTrim(char* str) ;
 
/*
功能：只去掉字符串右侧的所有空格
参数：str: 需要去掉右侧空格的字符串
返回：处理后的str
简例：
char s[] = "  how are you  ";
rightTrim(s)
返回值：  how are you|
*/
char* rightTrim(char* str) ;
 
/*
功能：把字符串的字母全部转换成大写 
参数：str被变大写的字符串
返回：处理后的str
简例：
char s[] = "how are you";
toUpperCase(s);
返回值： HOW ARE YOU
*/
char* toUpperCase(char* str ) ;
 
/*
功能：把字符串的字母全部转换成小写 
参数：str被变小写的字符串
返回：处理后的str
简例：
char s[] = "IEEE1394";
toUpperCase(s);
返回值： ieee1394
*/
char* toLowerCase(char* str ) ;
 
/*
功能：忽略大小写字母，比较两个字符串的大小
参数：str1 str2 两个比较的字符串
返回：1 大于关系 0 等于关系 -1小于关系
简例：int a=strcmpIgnorecase("Are","are");
返回值：0
*/
int strcmpIgnorecase(const char* str1,const char *str2) ;
 
/*
功能：对一个字符串进行翻转
参数：str被翻转的字符串
返回：翻转处理后的str
简例：char s[] ="12345";
返回值：54321
*/
char* reserveStr(char *str);
 
/*
功能：把一个s字符串重复连接n次后存放到d字符串
参数：d最终结果字符串，s被重复的字符串 n 重复的次数
返回：d最终结果字符串
简例：char a[50];
repeat(a,"sorry!",3);
返回值：sorry!sorry!sorry!
*/
char* repeat(char* d,const char *s ,int n) ;
 
/*
功能：把一个长串中的一段字符串复制到另一个字符串。
参数：s 长串 from从 to到(但不包括) d存放位置
返回：d字符串的结果
简例：char d[20];
substr("hello world",2,5,d);
返回值：llo
*/
char* substr(const char* s,int from ,int to,char * d) ;
 
/*
功能：把sub字符串插入到str的指定下标位置
参数：str目标字符串 sub被插入的子串 index 插入点下标。
返回：处理后的str
简例：
char s[50]="how you";
insert(s,"are ",3);
返回值：how are you
*/
char* insert(char* str,const char *sub,int index) ;
 
/*
功能：把字符串中指定下标的字符删除掉
参数：str目标字符串，index 被删除下标
返回：处理后的str
简例：char s[]="how you";
	deleteCharAt(s,1);
返回值：hw you	
*/
char* deleteCharAt(char* str,int index) ;
 
/*
功能：把str字符串中的一段字符删除掉
参数：str被删除的字符串 from删除开始点 to 结束点（但不包括）
返回：处理后的str
简例：
char s[]="how you";
deleteSubstr(s,0,4);
返回值：you
*/
char* deleteSubstr(char* str,int from ,int to) ;
 
/*
功能：把字符串str的一小段字符替换成另一个字符串sub
参数：str目标字符串 from起始点，to结束点（但不包括） sub替换的内容
返回：处理后的str
简例：
char s[50]="how is you";
replace(s,4,6,"are");
返回值：how are you
*/
char* replace(char* str,int from ,int to,const char * sub); 
 
/*
功能：把字符串str中的某些部分替换成另外的字符串
参数：str目标字符串 oldsub原来的内容 newsub 新的内容
返回：处理后的str
简例：
char s[50]="how did you did";
replaceAll(s,"did","do");
返回值：how do you do
*/
char* replaceAll(char* str,const char *oldsub,const char* newsub) ;
 
