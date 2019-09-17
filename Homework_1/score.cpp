/*************************************************
** Դ�ļ�   : score.c
** ����˵�� : Function Definitions
** ʱ�� : 2019.09.16
/**************************************************/

/*----------------ͷ�ļ�--------------*/
#define  _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "SCORE.h"
#include <algorithm> //�����㷨��ͷ�ļ�
#include <iostream>

/*----------------��������-------------*/

////1.1�ֶ�����ѧ����������
//void readData(SS stu[], int N)
//{
//
//	printf("�밴�����¸�ʽ����ѧ����Ϣ��ѧ��,����,ƽʱ�ɼ�,��ĩ�ɼ�\n");
//
//	for (int i = 0; i < N; i++)
//	{
//		printf("��%d��ѧ��:", i + 1);
//		scanf("%s %s %f %f", &stu[i].number, &stu[i].name, &stu[i].dailyScore, &stu[i].finalScore);
//		printf("\n");
//	}
//
//	printf("------�ɼ�¼�����!--------\n");
//
//}

//1.2���ļ����ȡѧ����������
SS* readDataFromFile(int *N)
{

	printf("\n\n------��һ��: ���ļ���ȡѧ���ĳɼ���Ϣ--------\n\n");

	SS *stu;// �����¿ռ�,��ȡ�ļ��е�ÿ��ѧ����Ϣ

	FILE *fp = NULL;
	int count = 0;
	int index = 0;

	fp = fopen("data.txt", "r");

	//1.��ȡѧ����Ŀ
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

	printf("ѧ����ĿΪ:%d\n", count);


	//2.������ѧ������洢�ռ�
	stu = (SS*)malloc(count * sizeof(SS));


	//3.��ȡÿ��ѧ������Ϣ
	while ((!feof(fp)))
	{

		//�����ļ����ݵ��ڴ�	
		fscanf(fp, "%s%s%f%f%f\n", (stu[index].number), (stu[index].name), &stu[index].dailyScore, &stu[index].experScore, &stu[index].finalScore);

		//���ѧ����Ϣ
		printf("* ѧ�ţ�%s	����:%s	\tƽʱ�ɼ���%4.2f��\tʵ��ɼ���%4.2f��\t��ĩ�ɼ�:%4.2f��\n", (stu[index].number), (stu[index].name), stu[index].dailyScore, stu[index].experScore, stu[index].finalScore);

		index++;
	}

	getchar();

	fclose(fp);

	return stu;
}

//2.����N��ѧ�����Ե������ɼ�
void calcuScore(SS stu[], int N)
{


	printf("\n\n------�ڶ���: ����ÿ��ѧ���������ɼ�--------\n\n");

	for (int i = 0; i < N; i++)
	{

		stu[i].generalScore = 0.2*stu[i].dailyScore + 0.2*stu[i].experScore + 0.6*stu[i].finalScore;
		printf("* ѧ�ţ�%s	����:%s		�ܳɼ�:%4.2f��\n", (stu[i].number), (stu[i].name), stu[i].generalScore);

	}

	getchar();
}


////3.���������ɼ�����
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
//}   //ע�͵Ŀ�ݷ�ʽ����Ctrl+K����Ctrl+C��ȡ��ע�ͣ� ��CTRL+K��Ȼ��CTRL+U�������ʽ�� ��ctrl + k, Ȼ��ctrl + f

bool cmp(SS a, SS b)  //bool�ͣ�ֻ��0 1
{
	return a.generalScore > b.generalScore;
} //���򣬵�a���ܳɼ�����b���ܳɼ�ʱ������1�����򷵻�0

void sortScore(SS stu[], int N)
{

//	qsort(&(stu[0]), N, sizeof(stu[0]), cmpBigtoSmall);
	std::sort(stu, stu + N, cmp);  //std::�����ռ䣬����Ϊ�׵�ַ��ĩ��ַ���׵�ַ+���ȣ������õĺ���
}

//4.����һ���ĸ�ʽ���N��ѧ������Ϣ
void printOut(SS stu[], int N)
{

	printf("\n------������: �����ܳɼ����ѧ��������Ϣ!------\n\n");

	for (int i = 0; i < N; i++)
	{

		printf("��%d����Ϣ ѧ�ţ�%s	����:%s		�ܳɼ�:%4.2f��\n", i + 1, stu[i].number, stu[i].name, stu[i].generalScore);
	}

	getchar();

}

//5.����ѧ�Ų�ѯ��i��ѧ���ĳɼ�
void Search(SS stu[], int N)
{
	printf("\n------���Ĳ�: ����ѧ�Ų�ѯѧ���ĳɼ�!------\n\n");

	char a[11];//����ռ�̫С����С��10�������ѧ��һ��11���ռ䣩
	while (1)
	{
		printf("\n------������ѧ�Ų�ѯѧ���ĳɼ�!���˳�������exit��------\n\n");
		scanf("%s", a);
		if (!strcmp(a, "exit")) {
			break;
		}
		for (int i = 0; i < N; i++)
		{
			if (!strcmp(a, stu[i].number))
			{
				printf("ѧ�ţ�%s	����:%s		�ܳɼ�:%4.2f��\n", stu[i].number, stu[i].name, stu[i].generalScore);
				break;
			}
			else if (i==N-1)
			{
				printf("����ѧ���д�����������");
				break;
			}   //Ҳ��������flag
		}
	}

	getchar();
}

//6.ͳ��ȫ��ѧ���ɼ��ľ�ֵ�ͱ�׼������Գɼ��ֲ���Ҫ����
void analyze(SS stu[], int N)
{
	printf("\n------���岽: ͳ��ȫ��ѧ���ɼ��ľ�ֵ�ͱ�׼������Գɼ��ֲ���Ҫ����!------\n\n");

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
	printf("ȫ��ѧ���ɼ��ľ�ֵΪ%f����׼����Ϊ%f\n", mean, variance);

	if (mean >= 85)
		printf("ȫ��ͬѧ�ľ�ֵΪ��%f�����ڵ���85�֣�����ˮƽ����\n", mean);
	else if (mean >= 70)
		printf("ȫ��ͬѧ�ľ�ֵΪ��%f����70�ֵ�85��֮�䣬����ˮƽ���ã����������ռ�\n", mean);
	else if (mean >= 60)
		printf("ȫ��ͬѧ�ľ�ֵΪ��%f����60�ֵ�70��֮�䣬����ˮƽ�д�����\n", mean);
	else
		printf("ȫ��ͬѧ�ľ�ֵΪ��%f��С��60�֣�����ˮƽƫ�ͬѧ����Ҫ����Ŭ����\n", mean);

	if (variance <= 10)
		printf("ȫ��ͬѧ�ı�׼����Ϊ��%f��ͬѧ�ǳɼ��ֲ�����\n", variance);
	else if (variance <= 20)
		printf("ȫ��ͬѧ�ı�׼����Ϊ��%f��ͬѧ�ǳɼ��ֲ��β�룬�����ͬѧ�Ƚϼ���\n", variance);
	else
		printf("ȫ��ͬѧ�ı�׼����Ϊ��%f��ͬѧ�ǳɼ��ֲ������ֻ��ϴ�\n", variance);

	getchar();
}