#pragma once
/*************************************************
* Head File   : SCORE.h
* File Usage  : ѧ������ϵͳͷ�ļ�
* Create Time : 2019.09.16
/**************************************************/

#ifndef __SCORE_H__  //���û����
#define __SCORE_H__


#include <stdio.h>
#include <iostream>

/*----------------------------------*
	   ѧ����Ϣ-�ṹ�����
*-----------------------------------*/

typedef struct student
{
	char number[11];  //ѧ��   //����ռ�̫С����С��10�������ѧ��һ��11���ռ䣩
	char name[10];    //����
	float dailyScore;   //ƽʱ�ɼ�
	float experScore;   //ʵ��ɼ�
	float finalScore;   //��ĩ�ɼ�
	float generalScore; //�ܳɼ�
	int rank;          //����

}SS;


/*---------------��������-------------------*/

//1.��ȡѧ����������
void readData(SS stu[], int N);
SS* readDataFromFile(int *N);

//2.����N��ѧ�������ܳɼ�
void calcuScore(SS stu[], int N);


//3.�����ܳɼ�����
void sortScore(SS stu[], int N);


//4.����һ���ĸ�ʽ���N��ѧ����������Ϣ
void printOut(SS stu[], int N);

//5.����ѧ�Ų�ѯ��i��ѧ���ĳɼ�
void Search(SS stu[], int N);

//6.ͳ��ȫ��ѧ���ɼ��ľ�ֵ�ͱ�׼������Գɼ��ֲ���Ҫ����
void analyze(SS stu[], int N);

#endif