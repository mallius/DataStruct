/* stack.c */
#include <stdlib.h>

#include "list.h"
#include "stack.h"

/* stack_push */
/* 返回值：0，成功；-1，失败 */
int stack_push(Stack *stack, const void *data)
{
	/* Push the data onto the stack */
	/* 数据入栈 */
	return list_ins_next(stack, NULL, data);
}

/* stack_pop */
/* 返回值：0，成功；-1，失败 */
int stack_pop(Stack *stack, void **data)
{
	/* Pop the data off the stack. */
	/* 数据出栈 */
	return list_rem_next(stack, NULL, data);
}
