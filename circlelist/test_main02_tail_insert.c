


#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "circle_list.h"

typedef struct _tag_TestValue
{
	CircleListNode node;
	int v;
}Value;

int main02() {
	int ret = 0;
	Value* tmp = NULL;

	Value v1, v2, v3, v4, v5;
	v1.v = 11;
	v2.v = 12;
	v3.v = 13;
	v4.v = 14;
	v5.v = 15;

	//����
	CircleList* list = NULL;
	list = CircleList_Create();
	if (list == NULL)
	{
		ret = -1;
		printf("func CircleList_Create() err\n");
		return ret;
	}

	//��������
	ret = CircleList_Insert(list, (CircleListNode*)&v1, CircleList_Length(list));
	ret = CircleList_Insert(list, (CircleListNode*)&v2, CircleList_Length(list));
	ret = CircleList_Insert(list, (CircleListNode*)&v3, CircleList_Length(list));
	ret = CircleList_Insert(list, (CircleListNode*)&v4, CircleList_Length(list));
	ret = CircleList_Insert(list, (CircleListNode*)&v5, CircleList_Length(list));

	//����
	printf("length:%d\n", CircleList_Length(list));

	//����
	for (int i = 0;i < CircleList_Length(list);i++)
	{
		tmp = (Value*)CircleList_Get(list, i);
		if (tmp == NULL)
		{
			ret = -2;
			return ret;
		}
		printf("tmp.v:%d  ", tmp->v);
	}
	printf("\n");

	//ɾ��ָ���ڵ�
	tmp = (Value*)CircleList_DeleteNode(list, (CircleListNode*)&v2);
	printf("ɾ����Ϊ��%d\n", tmp->v);

	//��ȡ��ǰ�α���ָ   
	tmp = (Value*)CircleList_Current(list);
	printf("��ǰ��ָΪ��%d\n", tmp->v);
	//����
	CircleList_Next(list);
	tmp = (Value*)CircleList_Current(list);
	printf("����֮��%d\n", tmp->v);
	//�����α�
	tmp = (Value*)CircleList_Reset(list);
	printf("�����α�֮��%d\n", tmp->v);

	//ɾ�����
	while (CircleList_Length(list) > 0)
	{
		tmp = (Value*)CircleList_Delete(list, 0);
		printf("tmp.v:%d ", tmp->v);
	}

	//����
	CircleList_Destroy(list);


	printf("\nHello world...\n");
	return ret;
}