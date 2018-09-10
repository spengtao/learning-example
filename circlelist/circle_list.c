
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "circle_list.h"

//ѭ������ ͷ��� ���ݽṹ
typedef struct _tag_CircleList
{
	CircleListNode head;
	CircleListNode *slider;
	int length;
}TCircleList;

//����
CircleList* CircleList_Create()
{
	TCircleList* cList = NULL;
	cList = (TCircleList*)malloc(sizeof(TCircleList));
	if (cList == NULL) 
	{
		printf("func CircleList_Create() malloc err: (TCircleList*)malloc(sizeof(TCircleList))\n");
		return NULL;
	}

	cList->head.next = NULL;
	cList->slider = NULL;
	cList->length = 0;

	return cList;
}

void CircleList_Destroy(CircleList* list)
{
	if (list == NULL)
	{
		printf("func CircleList_Destroy() err: (list == NULL)\n");
		return;
	}

	free(list);

	return ;
}

void CircleList_Clear(CircleList* list)
{
	TCircleList* cList = NULL;
	if (list == NULL)
	{
		printf("func CircleList_Clear() err: (list == NULL)\n");
		return;
	}

	cList = (TCircleList*)list;
	//�ص���ʼ��״̬
	cList->head.next = NULL;
	cList->slider = NULL;
	cList->length = 0;

	return ;
}

int CircleList_Length(CircleList* list)
{
	int ret = 0;
	TCircleList* cList = NULL;
	if (list == NULL)
	{
		ret = -1;
		printf("func CircleList_Length() err:%d (list == NULL)\n",ret);
		return ret;
	}

	cList = (TCircleList*)list;

	return cList->length;
}

int CircleList_Insert(CircleList* list, CircleListNode* node, int pos)
{
	int ret = 0;
	TCircleList* cList = NULL;
	CircleListNode* pCurrent = NULL;
	CircleListNode* pLast = NULL;

	if (list == NULL || node == NULL || pos < 0)
	{
		ret = -1;
		printf("func CircleList_Insert() err:%d (list == NULL || node == NULL || pos < 0)\n", ret);
		return ret;
	}
	//��ʼ������ָ��
	cList = (TCircleList*)list;
	pCurrent = (CircleListNode*)cList;  //ָ��ͷ���
	//���� ����pos
	for (int i = 0;(i < pos) && (pCurrent->next != NULL);i++)
	{
		pCurrent = pCurrent->next;
	}

	node->next = pCurrent->next;
	pCurrent->next = node;
	//��һ�� ����  �����α�
	if (CircleList_Length(list) == 0)
	{
		cList->slider = node;
	}
	cList->length++;

	//�ж��Ƿ�Ϊ ͷ�巨
	if (pCurrent == (CircleListNode*)cList)
	{
		pLast = CircleList_Get(list, CircleList_Length(list) - 1);
		pLast->next = pCurrent->next;
	}

	return ret;
}

CircleListNode* CircleList_Get(CircleList* list, int pos)
{
	TCircleList* cList = NULL;
	CircleListNode* pCurrent = NULL;
	CircleListNode* ret = NULL;

	if (list == NULL || pos < 0)
	{
		printf("func CircleList_Get() err: (list == NULL || node == NULL || pos < 0)\n");
		return ret;
	}
	cList = (TCircleList*)list;
	pCurrent = (CircleListNode*)cList;

	for (int i = 0;(i < pos) && (pCurrent->next != NULL);i++)
	{
		pCurrent = pCurrent->next;
	}

	ret = pCurrent->next;
	return ret;
}

CircleListNode* CircleList_Delete(CircleList* list, int pos)
{
	TCircleList* cList = NULL;
	CircleListNode* pCurrent = NULL;
	CircleListNode* ret = NULL;
	CircleListNode* pLast = NULL;

	if (list == NULL || pos < 0)
	{
		printf("func CircleList_Delete() err: (list == NULL || node == NULL || pos < 0)\n");
		return ret;
	}
	cList = (TCircleList*)list;
	pCurrent = (CircleListNode*)cList;

	if (cList->length > 0) 
	{
		for (int i = 0;(i < pos) && (pCurrent->next != NULL);i++)
		{
			pCurrent = pCurrent->next;
		}
		//ɾ����Ϊ 0�Ž��
		if (pCurrent == (CircleListNode*)cList)
		{
			pLast = CircleList_Get(list, cList->length - 1);
		}
		//����Ҫɾ���Ľ��
		ret = pCurrent->next;
		//ɾ��
		pCurrent->next = ret->next;
		cList->length--;

		//ɾ����Ϊ��
		if (pLast != NULL)
		{
			pLast->next = ret->next;
		}

		//ɾ���α���ָ
		if (ret == cList->slider)
		{
			cList->slider = ret->next;
		}

		//ɾ���󳤶�Ϊ 0
		if (cList->length == 0)
		{
			cList->head.next = NULL;
			cList->slider = NULL;
		}
	}
	
	return ret;
}

//add

CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode* node)
{
	int i = 0;
	TCircleList* cList = NULL;
	CircleListNode* pCurrent = NULL;
	CircleListNode* ret = NULL;

	if (list == NULL || node == NULL)
	{
		printf("func CircleList_DeleteNode() err:(list == NULL || node == NULL)\n");
		return ret;
	}

	cList = (TCircleList*)list;
	pCurrent = (CircleListNode*)cList;

	for (i = 0; i < cList->length; i++)
	{
		if (pCurrent->next == node)
		{
			ret = pCurrent->next;
			break;
		}
		pCurrent = pCurrent->next;
	}

	if (ret != NULL)
	{
		ret = CircleList_Delete(list, i);
	}

	return ret;
}

CircleListNode* CircleList_Reset(CircleList* list)
{
	TCircleList* cList = NULL;
	CircleListNode* ret = NULL;

	if (list == NULL)
	{
		printf("func CircleList_Reset() err:(list == NULL)\n");
		return ret;
	}

	cList = (TCircleList*)list;
	cList->slider = cList->head.next;

	ret = cList->slider;
	
	return ret;
}

CircleListNode* CircleList_Current(CircleList* list)
{
	TCircleList* cList = NULL;
	CircleListNode* ret = NULL;

	if (list == NULL)
	{
		printf("func CircleList_Current() err: (list == NULL)\n");
		return ret;
	}

	cList = (TCircleList*)list;
	ret = cList->slider;
	
	return ret;
}

CircleListNode* CircleList_Next(CircleList* list)
{
	TCircleList* cList = NULL;
	CircleListNode* ret = NULL;

	if (list == NULL)
	{
		printf("func CircleList_Next() err: (list == NULL)\n");
		return ret;
	}
	cList = (TCircleList*)list;

	if (cList->slider != NULL)
	{
		ret = cList->slider;
		cList->slider = ret->next;
	}
	
	return ret;
}