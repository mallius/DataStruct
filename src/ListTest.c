#include <stdio.h>
#include "list.h"

int main(void)
{
	int ret = 0;

	int num1 = 1;
	int num2 = 2;
	int num3 = 3;
	int *iptr1 = &num1;
	int *iptr2 = &num2;
	int *iptr3 = &num3;

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

	/* 插入第一个节点1 */
	printf("插入节点\n");
	ret = list_ins_next(list, NULL, iptr1);
	if(ret == -1)
	{
		printf("list_ins_next failed.\n");
		return -1;
	}

	int *pData = NULL;
	int *pDataTail = NULL;
	pData = (int *)(list->head->data);
	pDataTail = (int *)(list->tail->data);
	printf("Head[%d]\n", *pData);
	printf("Tail[%d]\n", *pDataTail);

	/* 插入第二个节点2 */
	ret = list_ins_next(list, list_tail(list), iptr2);
	if(ret == -1)
	{
		printf("list_ins_next failed.\n");
		return -1;
	}
	pData = (int *)(list->head->data);
	pDataTail = (int *)(list->tail->data);
	printf("Head[%d]\n", *pData);
	printf("Tail[%d]\n", *pDataTail);


	/* 插入第三个节点3 */
	ret = list_ins_next(list, list_tail(list), iptr3);
	if(ret == -1)
	{
		printf("list_ins_next failed.\n");
		return -1;
	}
	pData = (int *)(list->head->data);
	pDataTail = (int *)(list->tail->data);
	printf("Head[%d]\n", *pData);
	printf("Tail[%d]\n", *pDataTail);

	/* 删除第一个节点之后的节点 */
	/* 删除头节点 */
	printf("删除节点\n");
	ret = list_rem_next(list, NULL, (void **)&iptr2);
	if(ret == -1)
	{
		printf("list_rem_next failed.\n");
		return -1;
	}

	pData = (int *)(list->head->data);
	pDataTail = (int *)(list->tail->data);
	printf("Head[%d]\n", *pData);
	printf("Tail[%d]\n", *pDataTail);

	/* 删除头节点 */
	ret = list_rem_next(list, NULL, (void **)&iptr2);
	if(ret == -1)
	{
		printf("list_rem_next failed.\n");
		return -1;
	}

	pData = (int *)(list->head->data);
	pDataTail = (int *)(list->tail->data);
	printf("Head[%d]\n", *pData);
	printf("Tail[%d]\n", *pDataTail);

	int *p = list_data(list_head(list));
	printf("头结点数据:[%d]\n", *p);

	p = list_data(list_tail(list));
	printf("尾节点数据:[%d]\n", *p);

	list_destroy(list);
	free(list);
	list = NULL;
	return 0;
}
