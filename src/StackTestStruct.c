#include <stdio.h>
#include "stack.h"
#include <string.h>

#define MESSAGE_LEN 1024

/*自定义数据结构 ListElem中的void *data指向该结构体*/
typedef struct Node_
{
	void *nodeData;
	int len;
}Node;

/*自定义析构函数*/
void nodeDataDestroy(void *d)
{
	//free(d->nodeData);
	Node *p = (Node *)d;
	free(p->nodeData);
	return ;
}

int main(void)
{
	int ret = 0;

	/* 插入节点赋值 */
	Node node1;
	node1.nodeData = (char *)malloc(MESSAGE_LEN+1);
	if(NULL==node1.nodeData)
	{
		printf("malloc failed.\n");
		return -1;
	}
	memset(node1.nodeData, 0, MESSAGE_LEN+1);
	strcpy(node1.nodeData, "ThisIs1");
	node1.len = strlen(node1.nodeData); //6

	Node node2;
	node2.nodeData = (char *)malloc(MESSAGE_LEN+1);
	if(NULL==node2.nodeData)
	{
		printf("malloc failed.\n");
		return -1;
	}
	memset(node2.nodeData, 0, MESSAGE_LEN+1);
	strcpy(node2.nodeData, "This is a message2");
	node2.len = strlen(node2.nodeData); //18

	Node node3;
	node3.nodeData = (char *)malloc(MESSAGE_LEN+1);
	if(NULL==node3.nodeData)
	{
		printf("malloc failed.\n");
		return -1;
	}
	memset(node3.nodeData, 0, MESSAGE_LEN+1);
	strcpy(node3.nodeData, "This is Another Message message message message 3!");
	node3.len = strlen(node3.nodeData);

	/* 分配链表头的空间 */
	Stack *stack = (Stack *)malloc(sizeof(Stack));
	if(stack == NULL) 
	{
		printf("malloc failed.\n");
		return -1;
	}

	/* 初始化链表头 */
	stack_init(stack, nodeDataDestroy);

	/* 入栈第一个节点node1 */
	printf("压栈第一个节点\n");
	ret = stack_push(stack, &node1);
	if(ret == -1)
	{
		printf("stack_push failed.\n");
		return -1;
	}

	Node *p;
	p = (Node *)stack_peek(stack);
	printf("栈顶数据[%s]数据长度[%d]\n", p->nodeData, p->len);
	printf("栈大小[%d]\n", stack_size(stack));

	/* 入栈第二个节点node2 */
	printf("压栈第二个节点\n");
	ret = stack_push(stack, &node2);
	if(ret == -1)
	{
		printf("stack_push failed.\n");
		return -1;
	}
	p = (Node *)stack_peek(stack);
	printf("栈顶数据[%s]数据长度[%d]\n", p->nodeData, p->len);
	printf("栈大小[%d]\n", stack_size(stack));

	/* 入栈第三个节点node3 */
	printf("压栈第三个节点\n");
	ret = stack_push(stack, &node3);
	if(ret == -1)
	{
		printf("stack_push failed.\n");
		return -1;
	}
	p = (Node *)stack_peek(stack);
	printf("栈顶数据[%s]数据长度[%d]\n", p->nodeData, p->len);
	printf("栈大小[%d]\n", stack_size(stack));


	/* 出栈第一个节点之后的节点 */
	printf("出栈\n");
	Node *point;
	ret = stack_pop(stack, (void **)&point);
	if(ret == -1)
	{
		printf("stack_pop failed.\n");
		return -1;
	}

	Node *top = (Node *)stack_peek(stack);
	printf("栈顶数据[%s]数据长度[%d]\n", top->nodeData, top->len);
	printf("出栈数据[%s]数据长度[%d]\n", point->nodeData, point->len);
	printf("栈大小[%d]\n", stack_size(stack));

	/* 释放出栈数据 */
	free(point->nodeData);

	printf("销毁栈\n");
	stack_destroy(stack);
	free(stack);
	stack = NULL;

	return 0;
}
