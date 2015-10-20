#include <stdio.h>
#include "queue.h"

int main(void)
{
	int ret = 0;

	int num1 = 190;
	int num2 = 29;
	int *iptr1 = &num1;
	int *iptr2 = &num2;

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

	/* 插入第一个节点 */
	ret = queue_enqueue(queue, iptr1);
	if(ret == 0)
	{
		printf("queue_enqueue ok.\n");
	}
	else if(ret == -1)
	{
		printf("queue_enqueue failed.\n");
		return -1;
	}

	int *pData = NULL;
	int *pDataTail = NULL;
	pData = (int *)queue_peek(queue);
	printf("-->*pData[%d]\n", *pData);

	/* 插入第二个节点 */
	ret = queue_enqueue(queue, iptr2);
	if(ret == 0)
	{
		printf("queue_enqueue ok.\n");
	}
	else if(ret == -1)
	{
		printf("queue_enqueue failed.\n");
		return -1;
	}
	pData = (int *)queue_peek(queue);
	printf("-->*pData[%d]\n", *pData);
	int size = queue_size(queue);
	printf("-->size[%d]\n", size);

	/* 删除第一个节点之后的节点 */
	ret = queue_dequeue(queue, (void **)&iptr2);
	if(ret == 0)
	{
		printf("queue_dequeue ok.\n");
	}
	else if(ret == -1)
	{
		printf("queue_dequeue failed.\n");
		return -1;
	}

	pData = (int *)queue_peek(queue);
	printf("-->*pData[%d]\n", *pData);
	size = queue_size(queue);
	printf("-->size[%d]\n", size);

	queue_destroy(queue);
	free(queue);
	queue = NULL;
	return 0;
}
