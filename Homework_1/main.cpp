#define  _CRT_SECURE_NO_WARNINGS

/*************************************************
** 功能 : 学生成绩管理系统
** 作者 : QiuXuan0929
** 时间 : 2019.09.16
/**************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "score.h"
#include <iostream>

/*----------------------------------*
		Main Function
*-----------------------------------*/

int main()
{

	printf("******************************\n");
	printf("       学生成绩管理分析系统        \n");
	printf("           QiuXuan           \n");
	printf("******************************\n\n");

	/*-1.变量初始化-*/
	int N = 0;            //学生总数
	SS  *pstu = NULL;    //学生数组-结构体数组指针实现

	//2.读取学生信息
	pstu = readDataFromFile(&N);

	/*-3.计算学生总成绩（总成绩 = 0.2*平时成绩 + 0.2*实验成绩 + 0.6*期末成绩)--*/
	calcuScore(pstu, N);

	/*-4.根据学生成绩排名-*/
	sortScore(pstu, N);

	/*-5.按照排名输出学生信息-*/
	printOut(pstu, N);

	/*-6.输入学号查询学生成绩*/
	Search(pstu, N);

	/*-7.统计全班学生成绩的均值和标准方差，并对成绩分布简要分析*/
	analyze(pstu, N);

	/*-8.释放动态内存空间-*/
	free(pstu);


	system("pause");
	return 0;
}