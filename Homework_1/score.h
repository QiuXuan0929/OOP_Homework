#pragma once
/*************************************************
* Head File   : SCORE.h
* File Usage  : 学生管理系统头文件
* Create Time : 2019.09.16
/**************************************************/

#ifndef __SCORE_H__  //如果没定义
#define __SCORE_H__


#include <stdio.h>
#include <iostream>

/*----------------------------------*
	   学生信息-结构体设计
*-----------------------------------*/

typedef struct student
{
	char number[11];  //学号   //数组空间太小，若小于10，会出错（学号一共11个空间）
	char name[10];    //姓名
	float dailyScore;   //平时成绩
	float experScore;   //实验成绩
	float finalScore;   //期末成绩
	float generalScore; //总成绩
	int rank;          //排名

}SS;


/*---------------函数声明-------------------*/

//1.读取学生基本数据
void readData(SS stu[], int N);
SS* readDataFromFile(int *N);

//2.计算N个学生各自总成绩
void calcuScore(SS stu[], int N);


//3.根据总成绩排名
void sortScore(SS stu[], int N);


//4.按照一定的格式输出N个学生的完整信息
void printOut(SS stu[], int N);

//5.输入学号查询第i个学生的成绩
void Search(SS stu[], int N);

//6.统计全班学生成绩的均值和标准方差，并对成绩分布简要分析
void analyze(SS stu[], int N);

#endif