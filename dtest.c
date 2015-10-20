#include <stdio.h>
#include "dlist.h"

int main(void)
{
	int ret = 0;
	int iSizeNum = 0;
	int num1 = 19;
	int num2 = 29;
	int *iptr1 = &num1;
	int *iptr2 = &num2;

	DList *list = NULL;
	list = (DList *)malloc(sizeof(DList));
	if(NULL == list)
	{
		printf("malloc error!\n");
		return -1;
	}
	
	dlist_init(list, (void *)dlist_destroy);

	/* 第一次插入数据，在链表头上插入数据 */
	ret = dlist_ins_next(list, NULL, iptr1);
	if(ret == -1)
	{
		printf("dlist_ins_next failed.\n");
	}
	else if(ret == 0)
	{
		printf("dlist_ins_next ok.\n");
	}
	
	iSizeNum = dlist_size(list);
	printf("iSizeNum[%d]\n", iSizeNum);


	DListElmt *new_element = NULL;
	int *pData;
	
	printf("list->head[%p]\n", list->head);
	printf("list->tail[%p]\n", list->tail);
	printf("list->head->data[%p]\n", list->head->data);
	pData = (int *)(list->head->data);
	printf("pData[%p]\n", pData);
	printf("pData[%d]\n", *pData);

	/* 第二次插入数据，在第一个元素之后插入 */
	ret = dlist_ins_next(list, dlist_head(list), iptr2);
	if(ret == -1)
	{
		printf("dlist_ins_next failed.\n");
	}
	else if(ret == 0)
	{
		printf("dlist_ins_next ok.\n");
	}

	iSizeNum = dlist_size(list);
	printf("iSizeNum[%d]\n", iSizeNum);

	printf("list->head[%p]\n", list->head);
	printf("list->tail[%p]\n", list->tail);
	printf("list->tail->data[%p]\n", list->head->data);
	pData = (int *)(list->tail->data);
	printf("pData[%p]\n", pData);
	printf("pData[%d]\n", *pData);	



	dlist_destroy(list);	

	free(list);
	//list = NULL;

	return 0;
}
