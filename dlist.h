/* dlist.h */
#ifndef DLIST_H
#define DLIST_H

#include <stdlib.h>

/* Define a structure for doubly-linked list elements. */
/* 双向链表元素 */
typedef struct _DListElmt
{
	void *data;
	struct _DListElmt *prev;
	struct _DListElmt *next;
}DListElmt;

/* Define a struct for double-linked lists */
/* 双向链表 */
typedef struct _DList
{
	int size;
	int (*match)(const void *key1, const void *key2);  //未实现
	void (*destroy)(void *data);
	DListElmt *head;
	DListElmt *tail;
}DList;

/* Public Interface */
/* 公共接口 */
void dlist_init(DList *list, void (*destroy)(void *data));
void dlist_destroy(DList *list);
int dlist_ins_next(DList *list, DListElmt *element, const void *data);
int dlist_ins_prev(DList *list, DListElmt *element, const void *data);
int dlist_remove(DList *list, DListElmt *element, void **data);

#define dlist_size(list) ((list)->size)
#define dlist_head(list) ((list)->head)
#define dlist_tail(list) ((list)->tail)
#define dlist_is_head(element) ((element)->prev == NULL ? 1:0)
#define dlist_is_tail(element) ((element)->next == NULL ? 1:0)
#define dlist_data(element) ((element)->data)
#define dlist_next(element) ((element)->next)
#define dlist_prev(element) ((element)->prev)

#endif
