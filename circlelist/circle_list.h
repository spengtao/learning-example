
#ifndef _CIRCLELIST_H_
#define _CIRCLELIST_H_

typedef void CircleList;
/*
typedef struct _tag_CircleListNode CircleListNode;
struct _tag_CircleListNode
{
	CircleListNode* next;
};
*/
typedef struct _tag_CircleListNode
{
	struct _tag_CircleListNode * next;
}CircleListNode;

//创建
CircleList* CircleList_Create();
//销毁
void CircleList_Destroy(CircleList* list);
//清空  回到初始化状态
void CircleList_Clear(CircleList* list);
//获取长度
int CircleList_Length(CircleList* list);
//插入结点   在 pos位置 前插入
int CircleList_Insert(CircleList* list, CircleListNode* node, int pos);
//获取pos 位置结点
CircleListNode* CircleList_Get(CircleList* list, int pos);
//删除结点
CircleListNode* CircleList_Delete(CircleList* list, int pos);

//add
//指定删除链表中的 某个数据元素
CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode* node);
//重置游标  指向第一个数据元素
CircleListNode* CircleList_Reset(CircleList* list);
//获取当前 游标指向的元素
CircleListNode* CircleList_Current(CircleList* list);
//将游标当前 指向的元素返回， 并将游标 下移一位
CircleListNode* CircleList_Next(CircleList* list);

#endif