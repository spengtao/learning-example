
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "seq_stack.h"
#include "seq_list.h"

SeqStack* SeqStack_Create(int capacity) 
{
	return SeqList_Create(capacity);
}

void SeqStack_Destroy(SeqStack* stack)
{
	SeqList_Destroy(stack);
}

void SeqStack_Clear(SeqStack* stack)
{
	SeqList_Clear(stack);
}

//压栈 相当于 从线性表 尾部插入元素
int SeqStack_Push(SeqStack* stack, void* item)
{
	return SeqList_Insert(stack, item, SeqList_Length(stack));
}

//出栈 相当于 从线性表 尾部拿出元素
void* SeqStack_Pop(SeqStack* stack)
{
	return SeqList_Delete(stack, SeqList_Length(stack)-1);
}

//获取栈顶元素 相当于 获取线性表 尾部元素
void* SeqStack_Top(SeqStack* stack)
{
	return SeqList_Get(stack, SeqList_Length(stack) - 1);
}

int SeqStack_Size(SeqStack* stack)
{
	return SeqList_Length(stack);
}

int SeqStack_Capacity(SeqStack* stack)
{
	return SeqList_Capacity(stack);
}