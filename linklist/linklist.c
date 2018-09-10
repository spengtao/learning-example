
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "linklist.h"

typedef struct _tag_LinkList
{
	LinkListNode head;
	int length;
}TLinkList;

//创建线性 链式表
LinkList* LinkList_Create()
{
	TLinkList *tList = NULL;
	//分配内存
	tList = (TLinkList *)malloc(sizeof(TLinkList));
	if (tList == NULL) 
	{
		printf("func LinkList_Create() err: (TLinkList *)malloc(sizeof(TLinkList)) \n");
		return NULL;
	}
	memset(tList, 0, sizeof(TLinkList));


	return tList;
}

//销毁
void LinkList_Destroy(LinkList *list)
{
	if (list != NULL) {
		free(list);
		list = NULL;
	}

	return;
}

//清空 回到初始化状态
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

//获取长度
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

//插入结点
int LinkList_Insert(LinkList *list, LinkListNode *node, int pos)
{
	int ret = 0;

	TLinkList*		tList = NULL;
	LinkListNode*	pCurrent = NULL;

	//传入参数判断
	if (list == NULL || node == NULL || pos < 0) {
		ret = -1;
		printf("func LinkList_Insert() err:%d (list == NULL || node == NULL || pos < 0)\n", ret);
		return ret;
	}

	tList = (TLinkList*)list;
	pCurrent = &(tList->head);  //辅助指针变量  指向链表的 头结点
	//遍历 
	for (int i = 0;i < pos && pCurrent->next != NULL;i++) {
		pCurrent = pCurrent->next;
	}

	//执行插入操作
	node->next = pCurrent->next;
	pCurrent->next = node;

	tList->length++;

	return ret;
}

//获取结点信息
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

	//遍历  移动 pos个次数， pos结点地址 存放在前一个结点的 next域中
	for (int i = 0;i < pos && ret->next != NULL;i++) {
		ret = ret->next;
	}

	return ret->next;
}

//删除结点
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

	//遍历 
	for (int i = 0;i < pos && pCurrent->next != NULL;i++)
	{
		pCurrent = pCurrent->next;
	}

	//缓存要删除的结点 地址
	ret = pCurrent->next;

	//执行删除  连线
	pCurrent->next = ret->next;

	tList->length--;

	return ret;
}