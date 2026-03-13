//#include<stdio.h>
//
//int maingb()
//{
//	FILE* pf = fopen("d:\\myfile\\zm.txt", "r + t");
//	if (pf != NULL)
//	{
//		long wz = ftell(pf);
//		printf("%ld\n", wz);
//		fgetc(pf);
//		printf("%ld\n", ftell(pf));
//		char str[10];
//		fscanf(pf, "%4s", str);
//		puts(str);
//		printf("%ld\n", ftell(pf));
//		
//		fclose(pf);
//		printf("%ld\n", ftell(pf));
//		//rewind(pf);
//		//设置指定位置
//		fpos_t xyz = 10;
//		fsetpos(pf, &xyz);
//		char str[10]
//		fscanf(pf, "%4s", str);
//		puts(str);
//	}
//
//}