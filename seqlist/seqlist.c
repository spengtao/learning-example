
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "seqlist.h"

typedef struct _tag_SeqList
{
	int length;
	int capacity;
	unsigned int **node;
}TSeqList;

//创建
SeqList* SeqList_Create(int capacity) 
{
	
	TSeqList* tList = NULL;
	//分配内存
	tList = (TSeqList*)malloc(sizeof(TSeqList));
	if (tList == NULL) {
		printf("func SeqList_Create() err: (TSeqList*)malloc(sizeof(TSeqList)) \n");
		return NULL;
	}
	memset(tList, 0, sizeof(tList));

	//根据 capacity 分配内存
	tList->node = (unsigned int **)malloc(sizeof(unsigned int *) * capacity);
	if (tList->node == NULL) {
		printf("func SeqList_Create() err: (unsigned int **)malloc(sizeof(unsigned int *) * capacity) \n");
		return NULL;
	}
	
	tList->capacity = capacity;
	tList->length = 0;

	return tList;
}

//销毁
void SeqList_Destroy(SeqList* list)
{
	TSeqList *tList = NULL;
	if (list == NULL) 
	{
		printf("func SeqList_Destroy() err\n");
		return;
	}

	tList = (TSeqList *)list;

	if (tList->node != NULL) {
		free(tList->node);
		tList->node = NULL;
	}

	free(tList);
	return ;
}

//清空  回到初始化状态
void SeqList_Clear(SeqList* list)
{
	TSeqList *tList = NULL;
	if (list == NULL)
	{
		printf("func SeqList_Clear() err\n");
		return;
	}

	tList = (TSeqList *)list;
	tList->length = 0;

	return ;
}

//获取长度
int SeqList_Length(SeqList* list)
{
	int ret = 0;
	TSeqList *tList = NULL;
	if (list == NULL) {
		ret = -1;
		printf("func SeqList_Length() err:%d  (list == NULL) \n", ret);
		return ret;
	}

	tList = (TSeqList *)list;

	return tList->length;
}

//获取容量
int SeqList_Capacity(SeqList* list)
{
	int ret = 0;
	TSeqList *tList = NULL;

	if (list == NULL) {
		ret = -1;
		printf("func SeqList_Capacity() err:%d  (list == NULL) \n", ret);
		return ret;
	}

	tList = (TSeqList *)list;

	return tList->capacity;
}

//插入
int SeqList_Insert(SeqList* list, SeqListNode* node, int pos)
{
	int ret = 0, i = 0;
	TSeqList* tList = NULL;

	if (list == NULL || node == NULL || pos < 0) {
		ret = -1;
		printf("func SeqList_Insert() err:%d (list == NULL || node == NULL || pos < 0)\n", ret);
		return ret;
	}

	tList = (TSeqList*)list;

	//判断容量 是否已满
	if (tList->length >= tList->capacity) {
		ret = -2;
		printf("func SeqList_Insert() err:%d (SeqList_Length(list) >= SeqList_Capacity(list))", ret);
		return ret;
	}

	//容错修正   
	if (pos >= tList->length) {
		pos = tList->length;
	}

	//后移
	for (i = SeqList_Length(list);i > pos;i--) {
		tList->node[i] = tList->node[i - 1];
	}

	//pos 位置 插入
	tList->node[pos] = node;
	//长度加 1
	tList->length++;

	return ret;
}

//获取指定位置数据
SeqListNode* SeqList_Get(SeqList* list, int pos)
{
	TSeqList*	tList = NULL;
	SeqListNode* ret = NULL;
	if (list == NULL || pos < 0) {
		printf("func SeqList_Get() err: (list == NULL || pos < 0)\n");
		return ret;
	}

	tList = (TSeqList*)list;

	ret = (SeqListNode *)tList->node[pos];

	return ret;
}

//删除指定位置数据
SeqListNode* SeqList_Delete(SeqList* list, int pos)
{
	TSeqList*	tList = NULL;
	SeqListNode* ret = NULL;
	if (list == NULL || pos < 0) {
		printf("func SeqList_Get() err: (list == NULL || pos < 0)\n");
		return ret;
	}

	tList = (TSeqList*)list;

	//缓存指定位置数据
	ret = (SeqListNode*)tList->node[pos];

	//遍历 前移
	for (int i = pos + 1;i < tList->length;i++) {
		tList->node[i-1] = tList->node[i];
	}

	//长度 减1
	tList->length--;

	return ret;
}