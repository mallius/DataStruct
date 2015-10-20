/* clist.h */
#ifndef CLIST_H
#define CLIST_H

#include <stdlib.h>

/* Define a structure for circular list element. */
/* 循环链表元素 */
typedef struct _CListElmt
{
	void *data;
	struct _CListElmt *next;
} CListElmt;

/* Define a structure for circular list */
/* 循环链表 */
typedef struct _CList
{
	int size;
	int (*match)(const void *key1, const void *key2);
	void (*destroy)(void *data);
	CListElmt *head;
}CList;

/* Public Interface */
/* 公函 */
void clist_init(CList *list, void (*destroy)(void *data));
void clist_destroy(CList *list);
int clist_ins_next(CList *list, CListElmt *element, const void *data);
int clist_rem_next(CList *list, CListElmt *element, void **data);

#define clist_size(list) ((list)->size)
#define clist_head(list) ((list)->head)
#define clist_data(element) ((element)->data)
#define clist_next(element) ((element)->next)

#endif
