

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "linklist.h"

typedef struct Teacher
{
	LinkListNode node;
	int age;
	char name[64];
}Teacher;


int main(){

	int ret = 0;

	Teacher t1, t2, t3, t4, t5;

	t1.age = 18;
	strcpy(t1.name, "aaa");
	t2.age = 19;
	strcpy(t2.name, "www");
	t3.age = 20;
	strcpy(t3.name, "ggg");
	t4.age = 21;
	strcpy(t4.name, "hhh");
	t5.age = 22;
	strcpy(t5.name, "kkk");

	LinkList* list = NULL;

	//创建
	list = LinkList_Create();
	if (list == NULL) {
		ret = -1;
		printf("func LinkList_Create() err: (list == NULL)\n");
		return ret;
	}

	//插入
	ret = LinkList_Insert(list, (LinkListNode*) &t1, 0);
	if (ret != 0) {
		printf("func LinkList_Insert() err:%d\n", ret);
		return ret;
	}
	ret = LinkList_Insert(list, (LinkListNode*) &t2, 0);
	ret = LinkList_Insert(list, (LinkListNode*) &t3, 0);
	ret = LinkList_Insert(list, (LinkListNode*) &t4, 0);
	ret = LinkList_Insert(list, (LinkListNode*) &t5, 0);

	//遍历
	for (int i = 0;i < LinkList_Length(list);i++) {
		Teacher* tmp = (Teacher *)LinkList_Get(list, i);
		if (tmp == NULL) {
			ret = -1;
			printf("func LinkList_Get() err: (tmp == NULL)");
			return ret;
		}

		printf("name:%s  tmp[%d].age:%d\n", tmp->name, i, tmp->age);
	}

	//删除
	while (LinkList_Length(list) >0)
	{
		LinkList_Delete(list, 0);
	}

	//销毁
	LinkList_Destroy(list);

	/*
	LinkList* LinkList_Create();

	void LinkList_Destroy(LinkList *list);

	void LinkList_Clear(LinkList *list);

	int LinkList_Length(LinkList *list);

	int LinkList_Insert(LinkList *list, LinkListNode *node, int pos);

	LinkListNode* LinkList_Get(LinkList *list, int pos);

	LinkListNode* LinkList_Delete(LinkList *list, int pos);
	*/
	
	
	printf("Hello world...\n");
	return ret;
}