
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "dlink_list.h"

//����ͷ��� �ڲ����ݽṹ
typedef struct _tag_DLinkList
{
	DLinkListNode	head;
	DLinkListNode*	slider;
	int				length;
}TDlinkList;

//��������
DLinkList* DLinkList_Create()
{
	TDlinkList* dList = NULL;
	dList = (TDlinkList*)malloc(sizeof(TDlinkList));
	if (dList == NULL)
	{
		printf("func DLinkList_Create() malloc err: (TDlinkList*)malloc(sizeof(TDlinkList))\n");
		return NULL;
	}

	memset(dList, 0, sizeof(TDlinkList));

	/*dList->head.next = NULL;
	dList->head.pre = NULL;
	dList->slider = NULL;
	dList->length = 0;*/

	return dList;
}

//��������
void DLinkList_Destroy(DLinkList *list)
{
	if (list == NULL)
	{
		printf("func DLinkList_Destroy() err:(list == NULL)\n");
		return;
	}

	free(list);
	return ;
}

//�������
void DLinkList_Clear(DLinkList *list)
{
	TDlinkList* dList = NULL;

	if (list == NULL)
	{
		printf("func DLinkList_Clear() err:(list == NULL)\n");
		return;
	}

	dList = (TDlinkList*)list;

	dList->head.next = NULL;
	dList->head.pre = NULL;
	dList->slider = NULL;
	dList->length = 0;

	return ;
}

//��ȡ������
int DLinkList_Length(DLinkList *list)
{
	int ret = 0;
	TDlinkList* dList = NULL;

	if (list == NULL)
	{
		ret = -1;
		printf("func DLinkList_Length() err:%d (list == NULL)\n",ret);
		return ret;
	}

	dList = (TDlinkList*)list;
	ret = dList->length;

	return ret;
}


//����Ԫ�� ��pos λ��
int DLinkList_Insert(DLinkList *list, DLinkListNode *node, int pos)
{
	int ret = 0;
	TDlinkList* dList = NULL;
	DLinkListNode* pCurrent = NULL;
	DLinkListNode* pNext = NULL;

	if (list == NULL || node == NULL || pos < 0) {
		ret = -1;
		printf("func DLinkList_Insert() err:%d (list == NULL || node == NULL || pos < 0)\n",ret);
		return ret;
	}

	//
	dList = (TDlinkList*)list;
	pCurrent = (DLinkListNode*)dList;

	for (int i = 0; (i < pos) && (pCurrent->next != NULL);i++)
	{
		pCurrent = pCurrent->next;
	}

	//����pos ���
	pNext = pCurrent->next;

	node->next = pCurrent->next;
	pCurrent->next = node;

	//�״β����� pNextΪNULL  ���⴦��
	if (pNext != NULL)
	{
		pNext->pre = node;
	}
	node->pre = pCurrent;

	//ͷ�巨
	if (pCurrent == (DLinkListNode*)dList)
	{
		node->pre = NULL;
	}
	//�����α�
	if (dList->length == 0)
	{
		dList->slider = node;
	}

	dList->length++;

	return ret;
}


//��ȡ�� pos��λ��Ԫ��
DLinkListNode* DLinkList_GetByPos(DLinkList *list, int pos)
{
	TDlinkList* dList = NULL;
	DLinkListNode* pCurrent = NULL;
	DLinkListNode* ret = NULL;

	if (list == NULL || pos < 0) {
		printf("func DLinkList_GetByPos() err: (list == NULL || pos < 0)\n");
		return ret;
	}

	dList = (TDlinkList*)list;
	pCurrent = (DLinkListNode*)dList;

	for (int i = 0; (i < pos) && (pCurrent->next != NULL);i++)
	{
		pCurrent = pCurrent->next;
	}

	ret = pCurrent->next;

	return ret;
}


//ɾ�� posλ��Ԫ��
DLinkListNode* DLinkList_Delete(DLinkList *list, int pos)
{
	TDlinkList* dList = NULL;
	DLinkListNode* pCurrent = NULL;
	DLinkListNode* pNext = NULL;
	DLinkListNode* ret = NULL;

	if (list == NULL || pos < 0) {
		printf("func DLinkList_Delete() err: (list == NULL || pos < 0)\n");
		return ret;
	}

	dList = (TDlinkList*)list;
	pCurrent = (DLinkListNode*)dList;

	if (pos > dList->length)
	{
		printf("func DLinkList_Delete() err: the pos is bigger than length !\n");
		return ret;
	}

	for (int i = 0; (i < pos) && (pCurrent->next != NULL);i++)
	{
		pCurrent = pCurrent->next;
	}

	//����ɾ���Ľ��
	ret = pCurrent->next;
	pNext = ret->next;

	//ɾ������  ���� 1
	pCurrent->next = ret->next;
	//���� 2
	if (pNext != NULL)            //ɾ��β����� pre ������仯
	{
		pNext->pre = pCurrent;   
		//ɾ�� 0��λ��
		if (pCurrent == (DLinkListNode*)dList)
		{
			pNext->pre = NULL;
		}
	}

	//ɾ�� �α���ָ
	if (dList->slider == ret)
	{
		dList->slider = ret->next;
	}
	
	dList->length--;

	return ret;
}


//add
//ָ��ɾ�������� ĳ������Ԫ��
DLinkListNode* DLinkList_DeleteNode(DLinkList *list, DLinkListNode *node)
{
	int i = 0;
	TDlinkList* dList = NULL;
	DLinkListNode* pCurrent = NULL;
	DLinkListNode* ret = NULL;

	if (list == NULL || node == NULL) {
		printf("func DLinkList_DeleteNode() err: (list == NULL || node == NULL)\n");
		return ret;
	}

	dList = (TDlinkList*)list;
	pCurrent = (DLinkListNode*)dList;

	for (i = 0;i < dList->length;i++)
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
		ret = DLinkList_Delete(list, i);
	}

	return ret;
}

//�����α� λ��,�������ú� ��ָԪ��
DLinkListNode* DLinkList_Reset(DLinkList *list)
{
	TDlinkList* dList = NULL;
	DLinkListNode* ret = NULL;

	if (list == NULL)
	{
		printf("func DLinkList_Reset() err: (list == NULL)\n");
		return ret;
	}

	dList = (TDlinkList*)list;

	dList->slider = dList->head.next;

	ret = dList->slider;
	return ret;
}

//��ȡ��ǰ �α�ָ�� ����Ԫ��
DLinkListNode* DLinkList_Current(DLinkList *list)
{
	TDlinkList* dList = NULL;
	DLinkListNode* ret = NULL;

	if (list == NULL)
	{
		printf("func DLinkList_Current() err: (list == NULL)\n");
		return ret;
	}

	dList = (TDlinkList*)list;

	ret = dList->slider;

	return ret;
}

//���α�ָ����һ�� ����Ԫ��
DLinkListNode* DLinkList_Next(DLinkList *list)
{
	TDlinkList* dList = NULL;
	DLinkListNode* ret = NULL;

	if (list == NULL)
	{
		printf("func DLinkList_Next() err: (list == NULL)\n");
		return ret;
	}

	dList = (TDlinkList*)list;

	if (dList->slider != NULL)
	{
		ret = dList->slider;
		dList->slider = ret->next;
	}

	return ret;
}

//���α�ָ����һ�� ����Ԫ��
DLinkListNode* DLinkList_Pre(DLinkList *list)
{
	TDlinkList* dList = NULL;
	DLinkListNode* ret = NULL;

	if (list == NULL)
	{
		printf("func DLinkList_Pre() err: (list == NULL)\n");
		return ret;
	}

	dList = (TDlinkList*)list;

	if (dList->slider != NULL)
	{
		ret = dList->slider;
		dList->slider = ret->pre;
	}

	return ret;
}

