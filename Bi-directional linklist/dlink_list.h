
#ifndef _DLINK_LIST_H_
#define _DLINK_LIST_H_

typedef void DLinkList;

//双向链表  小结点
typedef struct _tag_DLinkListNode
{
	struct _tag_DLinkListNode *next;
	struct _tag_DLinkListNode *pre;
}DLinkListNode;

//创建链表
DLinkList* DLinkList_Create();

//销毁链表
void DLinkList_Destroy(DLinkList *list);

//清空链表
void DLinkList_Clear(DLinkList *list);

//获取链表长度
int DLinkList_Length(DLinkList *list);


//插入元素 到pos 位置
int DLinkList_Insert(DLinkList *list, DLinkListNode *node, int pos);


//获取第 pos个位置元素
DLinkListNode* DLinkList_GetByPos(DLinkList *list, int pos);


//删除 pos位置元素
DLinkListNode* DLinkList_Delete(DLinkList *list, int pos);


//add

//指定删除链表中 某个数据元素
DLinkListNode* DLinkList_DeleteNode(DLinkList *list, DLinkListNode *node);

//重置游标 位置,返回重置后 所指元素
DLinkListNode* DLinkList_Reset(DLinkList *list);

//获取当前 游标指向 数据元素
DLinkListNode* DLinkList_Current(DLinkList *list);

//将游标指向下一个 数据元素
DLinkListNode* DLinkList_Next(DLinkList *list);

//将游标指向上一个 数据元素
DLinkListNode* DLinkList_Pre(DLinkList *list);

#endif