#include <stdio.h>
#include "stack.h"

int main(void)
{
	int ret = 0;

	int num1 = 1;
	int num2 = 2;
	int num3 = 3;
	int *iptr1 = &num1;
	int *iptr2 = &num2;
	int *iptr3 = &num3;

	/* 分配链表头的空间 */
	Stack *stack = (Stack *)malloc(sizeof(Stack));
	if(stack == NULL) 
	{
		printf("malloc failed.\n");
		return -1;
	}

	/* 初始化链表头 */
	stack_init(stack, NULL);

	/* 入栈第一个节点 */
	printf("压栈第一个节点\n");
	ret = stack_push(stack, iptr1);
	if(ret == -1)
	{
		printf("stack_push failed.\n");
		return -1;
	}

	int *pData = NULL;
	pData = (int *)stack_peek(stack);
	printf("栈顶[%d]\n", *pData);
	printf("栈大小[%d]\n", stack_size(stack));

	/* 入栈第二个节点 */
	printf("压栈第二个节点\n");
	ret = stack_push(stack, iptr2);
	if(ret == -1)
	{
		printf("stack_push failed.\n");
		return -1;
	}
	pData = (int *)stack_peek(stack);
	printf("栈顶[%d]\n", *pData);
	printf("栈大小[%d]\n", stack_size(stack));

	/* 入栈第三个节点 */
	printf("压栈第三个节点\n");
	ret = stack_push(stack, iptr3);
	if(ret == -1)
	{
		printf("stack_push failed.\n");
		return -1;
	}
	pData = (int *)stack_peek(stack);
	printf("栈顶[%d]\n", *pData);
	printf("栈大小[%d]\n", stack_size(stack));



	/* 出栈第一个节点之后的节点 */
	printf("出栈\n");
	ret = stack_pop(stack, (void **)&iptr2);
	if(ret == -1)
	{
		printf("stack_pop failed.\n");
		return -1;
	}

	pData = (int *)stack_peek(stack);
	printf("栈顶[%d]\n", *pData);
	printf("出栈元素[%d]\n", *iptr2);
	printf("栈大小[%d]\n", stack_size(stack));

	printf("销毁栈\n");
	stack_destroy(stack);
	free(stack);
	stack = NULL;
	return 0;
}
