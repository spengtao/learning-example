

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "seqlist.h"

typedef struct Teacher
{
	int age;
	char name[64];
}Teacher;

int main(){
	int ret = 0;
	int capacity = 20;
	int len = 0;

	Teacher t1, t2, t3, t4, t5;

	t1.age = 25;
	strcpy(t1.name, "aaa");
	t2.age = 26;
	strcpy(t2.name, "bbb");
	t3.age = 27;
	strcpy(t3.name, "ccc");
	t4.age = 28;
	strcpy(t4.name, "ddd");
	t5.age = 29;
	strcpy(t5.name, "eee");

	
	//创建线性表
	SeqList* list = NULL;
	list = SeqList_Create(capacity);
	if (list == NULL) {
		printf("func SeqList_Create() err: (list == NULL)\n");
		return ;
	}

	//获取长度
	len = SeqList_Length(list);

	//插入元素
	ret = SeqList_Insert(list, (SeqListNode*) &t1, 0);
	if (ret != 0)
	{
		ret = -1;
		printf("func SeqList_Insert() err:%d\n", ret);
		return ret;
	}
	ret = SeqList_Insert(list, (SeqListNode*) &t2, 0);
	ret = SeqList_Insert(list, (SeqListNode*) &t3, 0);
	ret = SeqList_Insert(list, (SeqListNode*) &t4, 0);
	ret = SeqList_Insert(list, (SeqListNode*) &t5, 0);

	//遍历
	for (int i = 0;i < SeqList_Length(list);i++) 
	{
		Teacher *tmp = (Teacher *)SeqList_Get(list, i);
		if (tmp == NULL) 
		{
			ret = -1;
			printf("func SeqList_Get() err:%d\n",ret);
			return ret;
		}

		printf("tmp[%d].age:%d  ", i, tmp->age);
	}

	//删除
	printf("\n===============================================\n");
	while (SeqList_Length(list)>0)
	{
		Teacher *tmp = (Teacher *)SeqList_Delete(list, 0);
		if (tmp == NULL)
		{
			ret = -1;
			printf("func SeqList_Get() err:%d\n", ret);
			return ret;
		}

		printf("tmp.age:%d  ", tmp->age);
	}

	//销毁
	SeqList_Destroy(list);

	/*
	SeqList* SeqList_Create(int capacity);

	void SeqList_Destroy(SeqList* list);

	void SeqList_Clear(SeqList* list);

	int SeqList_Length(SeqList* list);

	int SeqList_Capacity(SeqList* list);

	int SeqList_Insert(SeqList* list, SeqListNode* node, int pos);

	SeqListNode* SeqList_Get(SeqList* list, int pos);

	SeqListNode* SeqList_Delete(SeqList* list, int pos);
	*/


	printf("\nHello world...\n");
	return ret;
}