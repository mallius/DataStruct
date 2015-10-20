#include <stdio.h>
#include "list.h"

int main(void)
{
	int ret = 0;

	int num1 = 19;
	int num2 = 29;
	int *iptr1 = &num1;
	int *iptr2 = &num2;

	List *list;
	ListElmt *element1; 
	ListElmt *element2; 

	/* 分配链表头的空间 */
	list = (List *)malloc(sizeof(List));
	if(list == NULL) 
	{
		printf("malloc failed.\n");
		return -1;
	}

	/* 初始化链表头 */
	list_init(list, NULL);

	/* 插入第一个节点 */
	ret = list_ins_next(list, NULL, iptr1);
	if(ret == 0)
	{
		printf("list_ins_next ok.\n");
	}
	else if(ret == -1)
	{
		printf("list_ins_next failed.\n");
		return -1;
	}

	int *pData = NULL;
	int *pDataTail = NULL;
	pData = (int *)(list->head->data);
	pDataTail = (int *)(list->tail->data);
	printf("-->*pData[%d]\n", *pData);
	printf("-->*pDataTail[%d]\n", *pDataTail);

	/* 插入第二个节点 */
	ret = list_ins_next(list, list_head(list), iptr2);
	if(ret == 0)
	{
		printf("list_ins_next ok.\n");
	}
	else if(ret == -1)
	{
		printf("list_ins_next failed.\n");
		return -1;
	}
	pData = (int *)(list->head->data);
	pDataTail = (int *)(list->tail->data);
	printf("-->*pData[%d]\n", *pData);
	printf("-->*pDataTail[%d]\n", *pDataTail);

	/* 删除第一个节点之后的节点 */
	ret = list_rem_next(list, list_head(list), (void **)&iptr2);
	if(ret == 0)
	{
		printf("list_rem_next ok.\n");
	}
	else if(ret == -1)
	{
		printf("list_rem_next failed.\n");
		return -1;
	}

	pData = (int *)(list->head->data);
	pDataTail = (int *)(list->tail->data);
	printf("-->*pData[%d]\n", *pData);
	printf("-->*pDataTail[%d]\n", *pDataTail);

	list_destroy(list);
	free(list);
	list = NULL;
	return 0;
}
