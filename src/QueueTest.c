#include <stdio.h>
#include "queue.h"

int main(void)
{
	int ret = 0;

	int num1 = 1;
	int num2 = 2;
	int num3 = 3;
	int *iptr1 = &num1;
	int *iptr2 = &num2;
	int *iptr3 = &num3;

	Queue *queue;

	/* 分配链表头的空间 */
	queue = (Queue *)malloc(sizeof(Queue));
	if(queue == NULL) 
	{
		printf("malloc failed.\n");
		return -1;
	}

	/* 初始化链表头 */
	queue_init(queue, NULL);

	/* 入队列第一个节点 */
	printf("入队列第一个节点\n");
	ret = queue_enqueue(queue, iptr1);
	if(ret == -1)
	{
		printf("queue_enqueue failed.\n");
		return -1;
	}

	int *pData = (int *)queue_peek(queue);
	printf("队列头[%d]\n", *pData);
	printf("队列大小[%d]\n", queue_size(queue));

	/* 入队列第二个节点 */
	printf("入队列第二个节点\n");
	ret = queue_enqueue(queue, iptr2);
	if(ret == -1)
	{
		printf("queue_enqueue failed.\n");
		return -1;
	}
	pData = (int *)queue_peek(queue);
	printf("队列头[%d]\n", *pData);
	printf("队列大小[%d]\n", queue_size(queue));

	/* 入队列第三个节点 */
	printf("入队列第三个节点\n");
	ret = queue_enqueue(queue, iptr3);
	if(ret == -1)
	{
		printf("queue_enqueue failed.\n");
		return -1;
	}
	pData = (int *)queue_peek(queue);
	printf("队列头[%d]\n", *pData);
	printf("队列大小[%d]\n", queue_size(queue));



	/* 出队列 */
	printf("出队列一个节点\n");
	ret = queue_dequeue(queue, (void **)&iptr1);
	if(ret == -1)
	{
		printf("queue_dequeue failed.\n");
		return -1;
	}

	pData = (int *)queue_peek(queue);
	printf("队列头[%d]\n", *pData);
	printf("队列大小[%d]\n", queue_size(queue));
	printf("出列数据[%d]\n", *iptr1);

	printf("出队列一个节点\n");
	ret = queue_dequeue(queue, (void **)&iptr1);
	if(ret == -1)
	{
		printf("queue_dequeue failed.\n");
		return -1;
	}

	pData = (int *)queue_peek(queue);
	printf("队列头[%d]\n", *pData);
	printf("队列大小[%d]\n", queue_size(queue));
	printf("出列数据[%d]\n", *iptr1);


	printf("销毁队列\n");
	queue_destroy(queue);
	free(queue);
	queue = NULL;
	return 0;
}
