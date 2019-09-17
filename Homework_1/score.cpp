/*************************************************
** 源文件   : score.c
** 功能说明 : Function Definitions
** 时间 : 2019.09.16
/**************************************************/

/*----------------头文件--------------*/
#define  _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "SCORE.h"
#include <algorithm> //包含算法的头文件
#include <iostream>

/*----------------函数定义-------------*/

////1.1手动输入学生基本数据
//void readData(SS stu[], int N)
//{
//
//	printf("请按照如下格式输入学生信息：学号,姓名,平时成绩,期末成绩\n");
//
//	for (int i = 0; i < N; i++)
//	{
//		printf("第%d个学生:", i + 1);
//		scanf("%s %s %f %f", &stu[i].number, &stu[i].name, &stu[i].dailyScore, &stu[i].finalScore);
//		printf("\n");
//	}
//
//	printf("------成绩录入完毕!--------\n");
//
//}

//1.2从文件里读取学生基本数据
SS* readDataFromFile(int *N)
{

	printf("\n\n------第一步: 从文件读取学生的成绩信息--------\n\n");

	SS *stu;// 开辟新空间,存取文件中的每个学生信息

	FILE *fp = NULL;
	int count = 0;
	int index = 0;

	fp = fopen("data.txt", "r");

	//1.获取学生数目
	if (fp != NULL)
	{
		fscanf(fp, "%d", &count);
		*N = count;
	}
	else
	{
		printf("failed to open the info file\n");
		getchar();
	}

	printf("学生数目为:%d\n", count);


	//2.给所有学生分配存储空间
	stu = (SS*)malloc(count * sizeof(SS));


	//3.读取每条学生的信息
	while ((!feof(fp)))
	{

		//读入文件数据到内存	
		fscanf(fp, "%s%s%f%f%f\n", (stu[index].number), (stu[index].name), &stu[index].dailyScore, &stu[index].experScore, &stu[index].finalScore);

		//输出学生信息
		printf("* 学号：%s	姓名:%s	\t平时成绩：%4.2f分\t实验成绩：%4.2f分\t期末成绩:%4.2f分\n", (stu[index].number), (stu[index].name), stu[index].dailyScore, stu[index].experScore, stu[index].finalScore);

		index++;
	}

	getchar();

	fclose(fp);

	return stu;
}

//2.计算N个学生各自的总评成绩
void calcuScore(SS stu[], int N)
{


	printf("\n\n------第二步: 计算每个学生的总评成绩--------\n\n");

	for (int i = 0; i < N; i++)
	{

		stu[i].generalScore = 0.2*stu[i].dailyScore + 0.2*stu[i].experScore + 0.6*stu[i].finalScore;
		printf("* 学号：%s	姓名:%s		总成绩:%4.2f分\n", (stu[i].number), (stu[i].name), stu[i].generalScore);

	}

	getchar();
}


////3.根据总评成绩排名
//int cmpBigtoSmall(const void *a, const void *b)
//{
//
//	SS *aa = (SS *)(a);
//	SS *bb = (SS *)(b);
//
//
//
//	if ((*aa).generalScore < (*bb).generalScore)  return 1;
//
//	else if ((*aa).generalScore > (*bb).generalScore)  return -1;
//
//	else
//		return 0;
//
//}   //注释的快捷方式：先Ctrl+K，再Ctrl+C；取消注释： 先CTRL+K，然后CTRL+U；代码格式化 先ctrl + k, 然后ctrl + f

bool cmp(SS a, SS b)  //bool型，只有0 1
{
	return a.generalScore > b.generalScore;
} //排序，当a的总成绩大于b的总成绩时，返回1，否则返回0

void sortScore(SS stu[], int N)
{

//	qsort(&(stu[0]), N, sizeof(stu[0]), cmpBigtoSmall);
	std::sort(stu, stu + N, cmp);  //std::命名空间，参数为首地址，末地址（首地址+长度），调用的函数
}

//4.按照一定的格式输出N个学生的信息
void printOut(SS stu[], int N)
{

	printf("\n------第三步: 根据总成绩输出学生排名信息!------\n\n");

	for (int i = 0; i < N; i++)
	{

		printf("第%d名信息 学号：%s	姓名:%s		总成绩:%4.2f分\n", i + 1, stu[i].number, stu[i].name, stu[i].generalScore);
	}

	getchar();

}

//5.输入学号查询第i个学生的成绩
void Search(SS stu[], int N)
{
	printf("\n------第四步: 输入学号查询学生的成绩!------\n\n");

	char a[11];//数组空间太小，若小于10，会出错（学号一共11个空间）
	while (1)
	{
		printf("\n------请输入学号查询学生的成绩!（退出请输入exit）------\n\n");
		scanf("%s", a);
		if (!strcmp(a, "exit")) {
			break;
		}
		for (int i = 0; i < N; i++)
		{
			if (!strcmp(a, stu[i].number))
			{
				printf("学号：%s	姓名:%s		总成绩:%4.2f分\n", stu[i].number, stu[i].name, stu[i].generalScore);
				break;
			}
			else if (i==N-1)
			{
				printf("输入学号有错，请重新输入");
				break;
			}   //也可以设置flag
		}
	}

	getchar();
}

//6.统计全班学生成绩的均值和标准方差，并对成绩分布简要分析
void analyze(SS stu[], int N)
{
	printf("\n------第五步: 统计全班学生成绩的均值和标准方差，并对成绩分布简要分析!------\n\n");

	float mean = 0;
	for (int i = 0; i < N; i++)
	{
		mean += stu[i].generalScore;
	}
	mean = mean / N;

	float variance = 0;
	for (int i=0; i < N; i++)
	{
		variance += (stu[i].generalScore - mean)*(stu[i].generalScore - mean);
	}
	variance = variance / N;
	printf("全班学生成绩的均值为%f，标准方差为%f\n", mean, variance);

	if (mean >= 85)
		printf("全班同学的均值为：%f，大于等于85分，整体水平优秀\n", mean);
	else if (mean >= 70)
		printf("全班同学的均值为：%f，在70分到85分之间，整体水平良好，还有提升空间\n", mean);
	else if (mean >= 60)
		printf("全班同学的均值为：%f，在60分到70分之间，整体水平有待提升\n", mean);
	else
		printf("全班同学的均值为：%f，小于60分，整体水平偏差，同学们需要继续努力！\n", mean);

	if (variance <= 10)
		printf("全班同学的标准方差为：%f，同学们成绩分布集中\n", variance);
	else if (variance <= 20)
		printf("全班同学的标准方差为：%f，同学们成绩分布参差不齐，大多数同学比较集中\n", variance);
	else
		printf("全班同学的标准方差为：%f，同学们成绩分布两极分化较大\n", variance);

	getchar();
}