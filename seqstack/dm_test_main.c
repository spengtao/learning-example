

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "seq_stack.h"

void main(){
	
	int cap = 10;
	int i = 0;
	int a[5];

	SeqStack *stk = SeqStack_Create(cap);
	if (stk == NULL)
	{
		printf("func SeqStack_Create() err\n");
		return;
	}

	for (i = 0;i < 5;i++)
	{
		a[i] = i + 1;
		SeqStack_Push(stk, &a[i]);
	}

	printf("capacity:%d\n", SeqStack_Capacity(stk));

	printf("size:%d\n", SeqStack_Size(stk));

	printf("top:%d\n", *((int*)SeqStack_Top(stk)));

	while (SeqStack_Size(stk)>0)
	{
		int tmp = *((int *)SeqStack_Pop(stk));
		printf("%d ", tmp);
	}


	SeqStack_Destroy(stk);

	
	printf("\nHello world...\n");
	return;
}