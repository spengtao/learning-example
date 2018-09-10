


#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "circle_list.h"

typedef struct _tag_TestValue
{
	CircleListNode node;
	int v;
}Value;

int main02() {
	int ret = 0;
	Value* tmp = NULL;

	Value v1, v2, v3, v4, v5;
	v1.v = 11;
	v2.v = 12;
	v3.v = 13;
	v4.v = 14;
	v5.v = 15;

	//创建
	CircleList* list = NULL;
	list = CircleList_Create();
	if (list == NULL)
	{
		ret = -1;
		printf("func CircleList_Create() err\n");
		return ret;
	}

	//插入链表
	ret = CircleList_Insert(list, (CircleListNode*)&v1, CircleList_Length(list));
	ret = CircleList_Insert(list, (CircleListNode*)&v2, CircleList_Length(list));
	ret = CircleList_Insert(list, (CircleListNode*)&v3, CircleList_Length(list));
	ret = CircleList_Insert(list, (CircleListNode*)&v4, CircleList_Length(list));
	ret = CircleList_Insert(list, (CircleListNode*)&v5, CircleList_Length(list));

	//长度
	printf("length:%d\n", CircleList_Length(list));

	//遍历
	for (int i = 0;i < CircleList_Length(list);i++)
	{
		tmp = (Value*)CircleList_Get(list, i);
		if (tmp == NULL)
		{
			ret = -2;
			return ret;
		}
		printf("tmp.v:%d  ", tmp->v);
	}
	printf("\n");

	//删除指定节点
	tmp = (Value*)CircleList_DeleteNode(list, (CircleListNode*)&v2);
	printf("删除的为：%d\n", tmp->v);

	//获取当前游标所指   
	tmp = (Value*)CircleList_Current(list);
	printf("当前所指为：%d\n", tmp->v);
	//下移
	CircleList_Next(list);
	tmp = (Value*)CircleList_Current(list);
	printf("下移之后：%d\n", tmp->v);
	//重置游标
	tmp = (Value*)CircleList_Reset(list);
	printf("重置游标之后：%d\n", tmp->v);

	//删除结点
	while (CircleList_Length(list) > 0)
	{
		tmp = (Value*)CircleList_Delete(list, 0);
		printf("tmp.v:%d ", tmp->v);
	}

	//销毁
	CircleList_Destroy(list);


	printf("\nHello world...\n");
	return ret;
}