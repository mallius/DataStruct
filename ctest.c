#include <stdio.h>
#include "clist.h"

int main(void)
{
	int ret = 0;

	int num1 = 19;
	int num2 = 29;
	int *iptr1 = &num1;
	int *iptr2 = &num2;

	CList *list;
	CListElmt *element1; 
	CListElmt *element2; 

	/* 分配链表头的空间 */
	list = (CList *)malloc(sizeof(CList));
	if(list == NULL) 
	{
		printf("malloc failed.\n");
		return -1;
	}

	/* 初始化链表头 */
	clist_init(list, NULL);

	/* 插入第一个节点 */
	ret = clist_ins_next(list, NULL, iptr1);
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
	pData = (int *)(list->head->data);
	printf("-->*pData[%d]\n", *pData);

	/* 插入第二个节点 */
	ret = clist_ins_next(list, clist_head(list), iptr2);
	if(ret == 0)
	{
		printf("list_ins_next ok.\n");
	}
	else if(ret == -1)
	{
		printf("list_ins_next failed.\n");
		return -1;
	}
	pData = (int *)(list->head->next->data);
	printf("-->*pData[%d]\n", *pData);

#if 1
	/* 删除第一个节点之后的节点 */
	ret = clist_rem_next(list, clist_head(list), (void **)&iptr2);
	if(ret == 0)
	{
		printf("list_rem_next ok.\n");
	}
	else if(ret == -1)
	{
		printf("list_rem_next failed.\n");
		return -1;
	}

	pData = (int *)(list->head->next->data);
	printf("-->*pData[%d]\n", *pData);
#endif

	clist_destroy(list);
	free(list);
	list = NULL;
	return 0;
}
