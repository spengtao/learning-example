
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "dlink_list.h"

//链表头结点 内部数据结构
typedef struct _tag_DLinkList
{
	DLinkListNode	head;
	DLinkListNode*	slider;
	int				length;
}TDlinkList;

//创建链表
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

//销毁链表
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

//清空链表
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

//获取链表长度
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


//插入元素 到pos 位置
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

	//缓存pos 结点
	pNext = pCurrent->next;

	node->next = pCurrent->next;
	pCurrent->next = node;

	//首次插入结点 pNext为NULL  特殊处理
	if (pNext != NULL)
	{
		pNext->pre = node;
	}
	node->pre = pCurrent;

	//头插法
	if (pCurrent == (DLinkListNode*)dList)
	{
		node->pre = NULL;
	}
	//处理游标
	if (dList->length == 0)
	{
		dList->slider = node;
	}

	dList->length++;

	return ret;
}


//获取第 pos个位置元素
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


//删除 pos位置元素
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

	//缓存删除的结点
	ret = pCurrent->next;
	pNext = ret->next;

	//删除操作  步骤 1
	pCurrent->next = ret->next;
	//步骤 2
	if (pNext != NULL)            //删除尾部结点 pre 域无须变化
	{
		pNext->pre = pCurrent;   
		//删除 0号位置
		if (pCurrent == (DLinkListNode*)dList)
		{
			pNext->pre = NULL;
		}
	}

	//删除 游标所指
	if (dList->slider == ret)
	{
		dList->slider = ret->next;
	}
	
	dList->length--;

	return ret;
}


//add
//指定删除链表中 某个数据元素
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

//重置游标 位置,返回重置后 所指元素
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

//获取当前 游标指向 数据元素
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

//将游标指向下一个 数据元素
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

//将游标指向上一个 数据元素
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

