

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "circle_list.h"

/*
Լɪ�����⣺
n ����Χ��һȦ�����ȴӵ�һ���˿�ʼ˳ʱ�뱨���������� m ���ˣ� ������У�Ȼ��ӳ��е���һ���˿�ʼ˳ʱ�뱨����
������ m ���ˣ���������У� ����ѭ���������˳��

�ƶ��� m-1 �� �α�
*/

typedef struct _tag_People
{
	CircleListNode node;
	int id;
}People;

void main3333(){

	int ret = 0;
	CircleList* list = NULL;
	
	People p1, p2, p3, p4, p5, p6, p7, p8;
	p1.id = 1;  p2.id = 2;  p3.id = 3;  p4.id = 4;
	p5.id = 5;  p6.id = 6;  p7.id = 7;  p8.id = 8;

	//����ѭ������
	list = CircleList_Create();

	//����
	ret = CircleList_Insert(list, (CircleListNode*)&p1, CircleList_Length(list));
	ret = CircleList_Insert(list, (CircleListNode*)&p2, CircleList_Length(list));
	ret = CircleList_Insert(list, (CircleListNode*)&p3, CircleList_Length(list));
	ret = CircleList_Insert(list, (CircleListNode*)&p4, CircleList_Length(list));
	ret = CircleList_Insert(list, (CircleListNode*)&p5, CircleList_Length(list));
	ret = CircleList_Insert(list, (CircleListNode*)&p6, CircleList_Length(list));
	ret = CircleList_Insert(list, (CircleListNode*)&p7, CircleList_Length(list));
	ret = CircleList_Insert(list, (CircleListNode*)&p8, CircleList_Length(list));

	//����
	for (int i = 0;i < CircleList_Length(list);i++)
	{
		People* tmp = (People*)CircleList_Get(list, i);
		printf("%d ", tmp->id);
	}
	printf("\n");

	//���Լɪ��   �˴� m ��СΪ 3
	CircleList_Reset(list);
	while (CircleList_Length(list)>0)
	{
		for (int i = 1;i < 3;i++)
		{
			CircleList_Next(list);
		}

		People* tmp = (People*)CircleList_Next(list);
		printf("%d ", tmp->id);
		//ɾ�� tmp
		CircleList_DeleteNode(list, (CircleListNode*)tmp);
	}

	//��������
	CircleList_Destroy(list);
	
	printf("\nHello world...\n");
	return;
}