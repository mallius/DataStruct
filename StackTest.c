#include <stdio.h>
#include "stack.h"

int main(void)
{
	int ret = 0;

	int num1 = 19;
	int num2 = 29;
	int *iptr1 = &num1;
	int *iptr2 = &num2;

	Stack *stack;

	/* 分配链表头的空间 */
	stack = (Stack *)malloc(sizeof(Stack));
	if(stack == NULL) 
	{
		printf("malloc failed.\n");
		return -1;
	}

	/* 初始化链表头 */
	stack_init(stack, NULL);

	/* 插入第一个节点 */
	ret = stack_push(stack, iptr1);
	if(ret == 0)
	{
		printf("stack_push ok.\n");
	}
	else if(ret == -1)
	{
		printf("stack_push failed.\n");
		return -1;
	}

	int *pData = NULL;
	int *pDataTail = NULL;
	pData = (int *)stack_peek(stack);
	printf("-->*pData[%d]\n", *pData);

	/* 插入第二个节点 */
	ret = stack_push(stack, iptr2);
	if(ret == 0)
	{
		printf("stack_push ok.\n");
	}
	else if(ret == -1)
	{
		printf("stack_push failed.\n");
		return -1;
	}
	pData = (int *)stack_peek(stack);
	printf("-->*pData[%d]\n", *pData);
	int size = stack_size(stack);
	printf("-->size[%d]\n", size);

	/* 删除第一个节点之后的节点 */
	ret = stack_pop(stack, (void **)&iptr2);
	if(ret == 0)
	{
		printf("stack_pop ok.\n");
	}
	else if(ret == -1)
	{
		printf("stack_pop failed.\n");
		return -1;
	}

	pData = (int *)stack_peek(stack);
	printf("-->*pData[%d]\n", *pData);
	size = stack_size(stack);
	printf("-->size[%d]\n", size);

	stack_destroy(stack);
	free(stack);
	stack = NULL;
	return 0;
}
