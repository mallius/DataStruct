/* list.c */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "list.h"

/* list_init */
void list_init(List *list, void (*destroy)(void *data))
{
	list->size = 0;
	list->destroy = destroy;
	list->head = NULL;
	list->tail = NULL;

	return ;
}

/* list_destroy */
void list_destroy(List *list)
{
	void *data;

	/* Remove each element */
	while(list_size(list) > 0)
	{
		if(list_rem_next(list, NULL, (void **)&data) == 0 && list->destroy != NULL)
		{
			/* Call a user-defined function to free dynamically allocated data. */
			list->destroy(data);
		}
	}
	memset(list, 0, sizeof(List));
	return ;
}

/* list_ins_next */
/*
 * 在element之后插入节点
 * 返回值：0，成功；-1，失败
 *
 */
int list_ins_next(List *list, ListElmt *element, const void *data)
{
	ListElmt *new_element;
	if((new_element = (ListElmt *)malloc(sizeof(ListElmt))) == NULL)
	{
		return -1;
	}
	/* Insert the element into the list */
	new_element->data = (void *)data;
	if(element == NULL)
	{
		/* Handle insertion at the head of the list */
		/* 插入头节点 */
		if(list_size(list) == 0)
		{
			list->tail = new_element;
		}

		new_element->next = list->head;
		list->head = new_element;
				
	}
	else
	{
		/* Handle insertion somewhere other than at the head. */
		/* 插入其它节点 */
		if(element->next == NULL)
		{
			list->tail = new_element;
		}
		new_element->next = element->next;
		element->next = new_element;
	}
	list->size++;

	return 0;

}

/* list_rem_next */
/*
 * 删除element节点之后的那个节点
 * 返回值：0，成功；-1，失败
 */
int list_rem_next(List *list, ListElmt *element, void **data)
{
	ListElmt *old_element;

	/* Do not allow removal from an empty list */
	/* 链表为空，无法销毁，则返回失败 */
	if(list_size(list) == 0)
	{
		return -1;
	}

	/* Remove the element from the list */
	/* 删除element之后的节点 */
	if(element == NULL)
	{
		/* Handle removal from the head of the list */
		/* 删除链表头指向的头节点 */
		*data = list->head->data; 		//
		old_element = list->head;
		list->head = list->head->next;

		if(list_size(list) == 1)
		{
			list->tail = NULL;
		}	
	}
	else
	{
		/* Handle removal from somewheree other than the head */
		if(element->next == NULL) 
			return -1;
		
		*data = element->next->data;
		old_element = element->next;
		element->next = element->next->next;

		if(element->next == NULL) {
			list->tail = element;
		}
	}
	/* Free the storage allocated by the abstract datatype */
	free(old_element);

	/* Adjust the size of the list to accout for the removed element */
	list->size--;
	return 0;
}

