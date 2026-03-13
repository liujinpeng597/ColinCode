#include <stdio.h>
/*
3.  题目：两个乒乓球队进行比赛，各出三人。甲队为a,b,c三人，乙队为x,y,z三人。已抽签决定比赛名单。有人向队员打听比赛的名单。a说他不和x比，
   c说他不和x,z比，请编程序找出三队赛手的名单。
   a pk z
   c pk y
   b pk x

*/

int main03 ()
{
	char a;//a 选手 
	char b;//b 选手 
	char c;//c 选手 
	for(a='x';a<='z';a++)
	{
		for(b='x';b<='z';b++)
		{
			for(c='x';c<='z';c++)
			{
				if ( a!=b&&a!=c&&b!=c&&a!='x'&&c!='x'&&c!='z' )
				{
					printf("a pk %c\n",a);
					printf("b pk %c\n",b);
					printf("c pk %c\n",c);
				}
			}
		}
		
	}

	return 0;
}