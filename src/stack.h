/* stack.h */
#ifndef __STACK_H__
#define __STACK_H__

#include <stdlib.h>
#include "list.h"

/* Implement stacks as linked lists. */
/* 结构体定义 */
typedef List Stack;

/* Public Interface */
/* 公共接口 */
#define stack_init list_init

#define stack_destroy list_destroy

int stack_push(Stack *stack, const void *data);
int stack_pop(Stack *stack, void **data);

#define stack_peek(stack) ((stack)->head == NULL ? NULL : (stack)->head->data)
#define stack_size list_size

#endif
