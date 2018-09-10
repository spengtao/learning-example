

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "dlink_list.h"
typedef struct _tag_VALUE
{
	DLinkListNode node;
	int v;
}Value;

int main() {
	int ret = 0;

	Value v1, v2, v3, v4, v5;
	Value* pV = NULL;
	DLinkList* list = NULL;

	v1.v = 11;
	v2.v = 12;
	v3.v = 13;
	v4.v = 14;
	v5.v = 15;


	//��������
	list = DLinkList_Create();
	if (list == NULL)
	{
		ret = -1;
		printf("func DLinkList_Create() err: (list == NULL) \n");
		return ret;
	}

	//����  β�巨
	ret = DLinkList_Insert(list, (DLinkListNode*)&v1, DLinkList_Length(list));
	ret = DLinkList_Insert(list, (DLinkListNode*)&v2, DLinkList_Length(list));
	ret = DLinkList_Insert(list, (DLinkListNode*)&v3, DLinkList_Length(list));
	ret = DLinkList_Insert(list, (DLinkListNode*)&v4, DLinkList_Length(list));
	ret = DLinkList_Insert(list, (DLinkListNode*)&v5, DLinkList_Length(list));

	//����
	for (int i = 0;i < DLinkList_Length(list);i++)
	{
		pV = (Value*)DLinkList_GetByPos(list, i);
		if (pV == NULL)
		{
			ret = -2;
			printf("func DLinkList_GetByPos() err: (pV == NULL)\n");
			return ret;
		}

		printf("%d\n", pV->v);
	}
	printf("\n");

	//ɾ����β Ԫ��
	DLinkList_Delete(list, DLinkList_Length(list) - 1);
	DLinkList_Delete(list, 0);

	//ɾ��֮���ӡ�α�ָ��Ԫ��
	for (int i = 0;i < DLinkList_Length(list);i++)
	{
		pV = (Value*)DLinkList_Next(list);
		printf("%d\n", pV->v);
	}
	printf("\n");

	//�����α�
	DLinkList_Reset(list);
	//�α�����
	DLinkList_Next(list);    

	//ɾ����ǰ�α�ָ��Ԫ��
	pV = (Value*)DLinkList_Current(list);
	printf("%d\n", pV->v);
	printf("\n");

	//ɾ��ָ�����
	DLinkList_DeleteNode(list, (DLinkListNode*)pV);
	pV = (Value*)DLinkList_Current(list);
	printf("%d\n", pV->v);
	printf("\n");

	//�α�ǰ��
	DLinkList_Pre(list);
	pV = (Value*)DLinkList_Current(list);
	printf("%d\n", pV->v);
	printf("\n");

	//��ȡ����
	printf("length = %d\n", DLinkList_Length(list));

	//����
	DLinkList_Destroy(list);
	
	
	printf("Hello world...\n");
	return ret;
}