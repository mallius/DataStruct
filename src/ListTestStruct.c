#include <stdio.h>
#include "list.h"
#include <string.h>

#define MESSAGE_LEN 1024

/*自定义数据结构 ListElem中的void *data指向该结构体*/
typedef struct Node_
{
	void *nodeData;
	int len;
}Node;

/*自定义析构函数*/
void nodeDataDestroy(void *d)
{
	Node *p = (Node *)d;
	free(p->nodeData);
	return ;
}

int main(void)
{
	int ret = 0;

	/* 插入节点赋值 */
	Node node1;
	node1.nodeData = (char *)malloc(MESSAGE_LEN+1);
	strcpy(node1.nodeData, "ThisIs");
	node1.len = strlen(node1.nodeData); //6

	Node node2;
	node2.nodeData = (char *)malloc(MESSAGE_LEN+1);
	strcpy(node2.nodeData, "This is a message.");
	node2.len = strlen(node2.nodeData); //18

	Node node3;
	node3.nodeData = (char *)malloc(MESSAGE_LEN+1);
	strcpy(node3.nodeData, "This is another message message message message!"); 
	node3.len = strlen(node3.nodeData);


	/* 分配链表头的空间 */
	List *list = (List *)malloc(sizeof(List));
	if(list == NULL) 
	{
		printf("malloc failed.\n");
		return -1;
	}

	/* 初始化链表头 */
	list_init(list, nodeDataDestroy);

	/* 插入第一个节点node1 */
	printf("插入头节点node1\n");
	ret = list_ins_next(list, NULL, &node1);
	if(ret == -1)
	{
		printf("list_ins_next failed.\n");
		return -1;
	}

	/* 插入第二个节点node2 */
	printf("尾部插入第二个节点node2\n");
	ret = list_ins_next(list, list_tail(list), &node2);
	if(ret == -1)
	{
		printf("list_ins_next failed.\n");
		return -1;
	}

	/* 插入第三个节点node3 */
	printf("尾部插入第三个节点node3\n");
	ret = list_ins_next(list, list_tail(list), &node3);
	if(ret == -1)
	{
		printf("list_ins_next failed.\n");
		return -1;
	}



	printf("移除节点\n");
	Node *p;
	ret = list_rem_next(list, NULL, (void **)&p);				//移除头节点
	if(ret == -1)
	{
		printf("list_rem_next failed.\n");
		return -1;
	}
	printf("移除的节点的数据内容:[%s]数据长度[%d]\n", (char *)p->nodeData, p->len);
	free(p->nodeData);

	printf("移除节点\n");
	Node *point;
	ret = list_rem_next(list, list_head(list), (void **)&point);	//移除头节点后的节点
	if(ret == -1)
	{
		printf("list_rem_next failed.\n");
		return -1;
	}
	printf("移除的节点的数据内容:[%s]数据长度[%d]\n", (char *)point->nodeData, point->len);
	free(point->nodeData);


	printf("---移除节点后---\n");
	Node *d = list_data(list_head(list));
	printf("头结点数据长度[%d]\n", d->len);
	printf("头结点数据[%s]\n", (char *)d->nodeData);

	d = list_data(list_tail(list));
	printf("尾节点数据长度[%d]\n", d->len);
	printf("尾节点数据[%s]\n", (char *)d->nodeData);
	printf("节点个数[%d]\n", list_size(list));


	list_destroy(list);
	free(list);
	list = NULL;

	return 0;
}
