#include <stdio.h>
#include <string.h>
#include "queue.h"

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

	Queue *queue;

	/* 分配链表头的空间 */
	queue = (Queue *)malloc(sizeof(Queue));
	if(queue == NULL) 
	{
		printf("malloc failed.\n");
		return -1;
	}

	/* 初始化链表头 */
	queue_init(queue, nodeDataDestroy);

	/* 入队列第一个节点 */
	printf("入队列第一个节点node1\n");
	ret = queue_enqueue(queue, &node1);
	if(ret == -1)
	{
		printf("queue_enqueue failed.\n");
		return -1;
	}

	Node *p = (Node *)queue_peek(queue);
	printf("队列头数据[%s]\n", p->nodeData);
	printf("队列大小[%d]\n", queue_size(queue));

	/* 入队列第二个节点 */
	printf("入队列第二个节点node2\n");
	ret = queue_enqueue(queue, &node2);
	if(ret == -1)
	{
		printf("queue_enqueue failed.\n");
		return -1;
	}

	p = (Node *)queue_peek(queue);
	printf("队列头数据[%s]\n", p->nodeData);
	printf("队列大小[%d]\n", queue_size(queue));

	/* 入队列第三个节点 */
	printf("入队列第三个节点node3\n");
	ret = queue_enqueue(queue, &node3);
	if(ret == -1)
	{
		printf("queue_enqueue failed.\n");
		return -1;
	}
	p = (Node *)queue_peek(queue);
	printf("队列头数据[%s]\n", p->nodeData);
	printf("队列大小[%d]\n", queue_size(queue));



	/* 出队列 */
	printf("出队列一个节点node1\n");
	Node *temp;
	ret = queue_dequeue(queue, (void **)&temp);
	if(ret == -1)
	{
		printf("queue_dequeue failed.\n");
		return -1;
	}

	Node *head;
	head = (Node *)queue_peek(queue);
	printf("队列头数据[%s]\n", head->nodeData);
	printf("队列大小[%d]\n", queue_size(queue));
	printf("出列数据[%s]\n", temp->nodeData);
	/* 销毁移除数据 */
	free(temp->nodeData);

	printf("出队列一个节点node2\n");
	ret = queue_dequeue(queue, (void **)&temp);
	if(ret == -1)
	{
		printf("queue_dequeue failed.\n");
		return -1;
	}

	head = (Node *)queue_peek(queue);
	printf("队列头数据[%s]\n", head->nodeData);
	printf("队列大小[%d]\n", queue_size(queue));
	printf("出列数据[%s]\n", temp->nodeData);

	/* 销毁移除数据 */
	free(temp->nodeData);

	printf("销毁队列\n");
	queue_destroy(queue);
	free(queue);
	queue = NULL;
	return 0;
}
