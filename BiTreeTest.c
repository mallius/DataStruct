#include "bitree.h"
#include <stdio.h>
int main(void)
{
	int ret;
	BiTree *tree; 

	tree = (BiTree *)malloc(sizeof(BiTree));
	if(tree == NULL)
	{
		printf("malloc error.\n");
		return -1;
	}

	bitree_init(tree, NULL);

	int data1=1;
	int data2=2;
	int *pdata1 = &data1;
	int *pdata2 = &data2;

	ret = bitree_ins_left(tree, tree->root , pdata1);
	if(ret == -1)
	{
		printf("bitree_ins_left 1st error.\n");
		return -1;
	}
	printf("bitree_ins_left 1st ok.\n");

	int *p1 = tree->root->data;
	printf("1st[%d]\n", (*p1));

#if 0
	ret = bitree_ins_left(tree, tree->root->left, pdata2);
	if(ret == -1)
	{
		printf("bitree_ins_left 2nd error.\n");
		return -1;
	}
#endif
	
	return 0;
}
