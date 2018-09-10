

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


	//创建链表
	list = DLinkList_Create();
	if (list == NULL)
	{
		ret = -1;
		printf("func DLinkList_Create() err: (list == NULL) \n");
		return ret;
	}

	//插入  尾插法
	ret = DLinkList_Insert(list, (DLinkListNode*)&v1, DLinkList_Length(list));
	ret = DLinkList_Insert(list, (DLinkListNode*)&v2, DLinkList_Length(list));
	ret = DLinkList_Insert(list, (DLinkListNode*)&v3, DLinkList_Length(list));
	ret = DLinkList_Insert(list, (DLinkListNode*)&v4, DLinkList_Length(list));
	ret = DLinkList_Insert(list, (DLinkListNode*)&v5, DLinkList_Length(list));

	//遍历
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

	//删除首尾 元素
	DLinkList_Delete(list, DLinkList_Length(list) - 1);
	DLinkList_Delete(list, 0);

	//删除之后打印游标指向元素
	for (int i = 0;i < DLinkList_Length(list);i++)
	{
		pV = (Value*)DLinkList_Next(list);
		printf("%d\n", pV->v);
	}
	printf("\n");

	//重置游标
	DLinkList_Reset(list);
	//游标下移
	DLinkList_Next(list);    

	//删除当前游标指向元素
	pV = (Value*)DLinkList_Current(list);
	printf("%d\n", pV->v);
	printf("\n");

	//删除指定结点
	DLinkList_DeleteNode(list, (DLinkListNode*)pV);
	pV = (Value*)DLinkList_Current(list);
	printf("%d\n", pV->v);
	printf("\n");

	//游标前移
	DLinkList_Pre(list);
	pV = (Value*)DLinkList_Current(list);
	printf("%d\n", pV->v);
	printf("\n");

	//获取长度
	printf("length = %d\n", DLinkList_Length(list));

	//销毁
	DLinkList_Destroy(list);
	
	
	printf("Hello world...\n");
	return ret;
}