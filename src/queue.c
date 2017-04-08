/* queue.c */
#include <stdlib.h>

#include "queue.h"

/* queue_enqueue */
/* 返回值：0，成功；-1，失败 */
int queue_enqueue(Queue* queue, const void *data)
{
	/* Enqueue the data */
	/* 入队 */
	return list_ins_next(queue, list_tail(queue), data);
}

/* queue_dequeue */
/* 返回值：0，成功；-1，失败 */
int queue_dequeue(Queue* queue, void **data)
{
	/* Dequeue the data */
	/* 出队 */
	return list_rem_next(queue, NULL, data);
}
