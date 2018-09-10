
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "linklist.h"

typedef struct _tag_LinkList
{
	LinkListNode head;
	int length;
}TLinkList;

//�������� ��ʽ��
LinkList* LinkList_Create()
{
	TLinkList *tList = NULL;
	//�����ڴ�
	tList = (TLinkList *)malloc(sizeof(TLinkList));
	if (tList == NULL) 
	{
		printf("func LinkList_Create() err: (TLinkList *)malloc(sizeof(TLinkList)) \n");
		return NULL;
	}
	memset(tList, 0, sizeof(TLinkList));


	return tList;
}

//����
void LinkList_Destroy(LinkList *list)
{
	if (list != NULL) {
		free(list);
		list = NULL;
	}

	return;
}

//��� �ص���ʼ��״̬
void LinkList_Clear(LinkList *list)
{
	TLinkList *tList = NULL;

	if (list == NULL) {
		printf("func LinkList_Clear() err: (list == NULL)\n");
		return;
	}

	tList = (TLinkList *)list;

	tList->length = 0;
	tList->head.next = NULL;

	return ;
}

//��ȡ����
int LinkList_Length(LinkList *list)
{
	int ret = 0;
	TLinkList *tList = NULL;

	if (list == NULL) {
		ret = -1;
		printf("func LinkList_Length() err:%d (list == NULL)\n",ret);
		return ret;
	}

	tList = (TLinkList *)list;

	return tList->length;
}

//������
int LinkList_Insert(LinkList *list, LinkListNode *node, int pos)
{
	int ret = 0;

	TLinkList*		tList = NULL;
	LinkListNode*	pCurrent = NULL;

	//��������ж�
	if (list == NULL || node == NULL || pos < 0) {
		ret = -1;
		printf("func LinkList_Insert() err:%d (list == NULL || node == NULL || pos < 0)\n", ret);
		return ret;
	}

	tList = (TLinkList*)list;
	pCurrent = &(tList->head);  //����ָ�����  ָ������� ͷ���
	//���� 
	for (int i = 0;i < pos && pCurrent->next != NULL;i++) {
		pCurrent = pCurrent->next;
	}

	//ִ�в������
	node->next = pCurrent->next;
	pCurrent->next = node;

	tList->length++;

	return ret;
}

//��ȡ�����Ϣ
LinkListNode* LinkList_Get(LinkList *list, int pos)
{
	LinkListNode*	ret = NULL;
	TLinkList*		tList = NULL;

	if (list == NULL || pos < 0) 
	{
		printf("func LinkList_Insert() err: (list == NULL || pos < 0)\n");
		return ret;
	}

	tList = (TLinkList*)list;
	ret = &(tList->head);

	//����  �ƶ� pos�������� pos����ַ �����ǰһ������ next����
	for (int i = 0;i < pos && ret->next != NULL;i++) {
		ret = ret->next;
	}

	return ret->next;
}

//ɾ�����
LinkListNode* LinkList_Delete(LinkList *list, int pos)
{
	LinkListNode*	ret = NULL;
	LinkListNode*	pCurrent = NULL;
	TLinkList*		tList = NULL;



	if (list == NULL || pos < 0)
	{
		printf("func LinkList_Insert() err: (list == NULL || pos < 0)\n");
		return ret;
	}

	tList = (TLinkList*)list;
	pCurrent = &(tList->head);

	//���� 
	for (int i = 0;i < pos && pCurrent->next != NULL;i++)
	{
		pCurrent = pCurrent->next;
	}

	//����Ҫɾ���Ľ�� ��ַ
	ret = pCurrent->next;

	//ִ��ɾ��  ����
	pCurrent->next = ret->next;

	tList->length--;

	return ret;
}