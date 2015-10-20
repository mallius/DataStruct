/* dlist.c */
#include <stdlib.h>
#include <string.h>

#include "dlist.h"

/* dlist_init */
void dlist_init(DList *list, void (*destroy)(void *data))
{
	/* Initialize the list. */
	/* 初始化链表 */

	list->size = 0;
	list->destroy = destroy;
	list->head = NULL;
	list->tail = NULL;

	return ;
}

/* dlist_destroy */
void dlist_destroy(DList *list)
{
	void *data;

	/* Remove each element. */
	/* 删除每个节点 */
	
	while(dlist_size(list) > 0)
	{
		if(dlist_remove(list, dlist_tail(list), (void **)&data) == 0 	/* 二级指针 */
				&& list->destroy != NULL)
		{
			/* Call a user-defined function to free dynamically allocated data */
			/* 调用定义的函数释放数据 */
			list->destroy(data);
		}
	}

	/* No operation are allowed now, but clear the struct as precaution. */
	/* 清除链表本身 */
	memset(list, 0, sizeof(DList));
	return ;
}

/* 
 * dlist_ins_next
 * 在指定元素的后面插入新节点 
 * 返回值：0,成功；-1,失败
 *
 */
int dlist_ins_next(DList *list, DListElmt *element, const void *data)
{
	DListElmt 	*new_element;

	/* Do not allow a NULL element unless the list is empty. */
	/* 链表为空,且大小不为0,则返回错误 */
	if(element == NULL && dlist_size(list) != 0)
	{
		return -1;
	}
	
	/* Allocate storage for the element. */
	/* 为新节点分配空间 */
	if((new_element = (DListElmt *)malloc(sizeof(DListElmt))) == NULL)
	{
		return -1;
	}	

	/* Insert the new element into the list. */
	/* 插入新元素到链表 */
	new_element->data = (void *)data; 		//?如何把data打印出来

	if(dlist_size(list) == 0)
	{
		/* Handle insertion when the list is empty. */
		/* 链表为空的情况 */
		list->head = new_element;
		list->head->prev = NULL;
		list->head->next = NULL;
		list->tail = new_element;
	}
	else
	{
		/* Handle insertion when the list is not empty. */
		/* 链表不为空 */	
		new_element->next = element->next;  //(1)
		new_element->prev = element; 	    //(2)

		/* 在最后一个节点后插入 */          //(3)
		if(element->next == NULL)
		{
			list->tail = new_element;
		}
		else
		{
			element->next->prev = new_element;	
		}
		element->next = new_element;       //(4)
	}

	/* Adjust the size of the list to account for the inserted element. */
	/* 链表大小加1 */
	list->size++;
	return 0;
}


/*
 * dlist_ins_prev
 * 在指定元素之前插入新节点 
 * 返回值：0，成功；-1：失败
 */
int dlist_ins_prev(DList *list, DListElmt *element, const void *data)
{
	DListElmt *new_element;
	
	/* Do not allow a NULL element unless the list is empty. */
	/* 链表为空，且大小不为0，则返回错误 */
	if(element == NULL && dlist_size(list) != 0)
	{
		return -1;
	}

	/* Allocate storage to be managed by the abstract datatype. */
	/* 为新节点分配空间 */
	if((new_element = (DListElmt *)malloc(sizeof(DListElmt))) == NULL)
	{
		return -1;
	}

	/* Insert the new element into the list. */
	/* 新节点插入链表 */
	new_element->data = (void *)data;

	if(dlist_size(list) == 0)
	{
		/* Handle insertion when the list is empty. */
		/* 链表为空的情况 */
		list->head = new_element;
		list->head->prev = NULL;
		list->head->next = NULL;
		list->tail = new_element;
	}
	else
	{
		/* Handle insertion when the list is not empty. */
		/* 链表不为空的情况 */
		new_element->next = element;
		new_element->prev = element->prev;

		/* 在最后一个节点前插入 */
		if(element->prev == NULL)
		{
			list->head = new_element;	
		}
		else
		{
			element->prev->next = new_element;
		}
		element->prev = new_element;
	}
	/* Adjust the size of the list to account for the new element. */
	/* 链表大小加1 */
	list->size++;
	return 0;
}

/*
 * dlist_remove
 * 删除指定的节点 
 * 返回值：0，成功；-1，失败
 *
 */
int dlist_remove(DList *list, DListElmt *element, void **data)
{
	/* Do not allow a NULL element or removal from an empty list. */
	/* 链表为空，则无法删除 */
	if(element == NULL || dlist_size(list) == 0)
	{
		return -1;
	}	

	/* Remove the element from the list */
	*data = element->data;

	if(element == list->head)
	{
		/* Handle removal from the head of the list. */
		/* 删除链表头 */
		list->head = element->next;

		if(list->head == NULL)
		{
			list->tail = NULL;
		}
		else
		{
			element->next->prev = NULL;
		}
	       	
	}
	else
	{
		/* Handle removal from other than the head of the list. */
		element->prev->next = element->next;
		if(element->next == NULL)
		{
			list->tail = element->prev;
		}
		else
		{
			element->next->prev = element->prev;
		}
	}

	/* Free the storage allocated by the abstract datatype. */
	free(element);

	/* Adjust the size of the list to account for the removed element. */
	list->size--;
	return 0;
}
