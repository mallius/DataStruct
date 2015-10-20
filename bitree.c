/* bitree.c */
/*
 * 提供对二叉树的基本操作，
 * 不包含插入和删除非叶子结点的操作
 */

#include <stdlib.h>
#include <string.h>
#include "bitree.h"

/* 初始化tree指定的二叉树 */
void bitree_init(BiTree *tree, void (*destroy)(void *data))
{
	/* Initialize the binary tree */
	/* 初始化二叉树 */
	tree->size = 0;
	tree->destroy = destroy;
	tree->root = NULL;

	return ;
}

/* bitree_destroy */
/* 销毁tree指定的二叉树 */
void bitree_destroy(BiTree *tree)
{
	/* Remove all the nodes from the tree. */
	/* 删除树上所有结点 */
	bitree_rem_left(tree, NULL);

	/* No operations are allowed now, but clear the structure as a precaution. */
	memset(tree, 0, sizeof(BiTree));
	return;
}

/* 
 * bitree_ins_left
 * 在tree指定的二叉树中插入一个结点，使其成为node的左结点
 * 返回值：0，成功；-1失败；
 */
int bitree_ins_left(BiTree *tree, BiTreeNode *node, const void *data)
{
	BiTreeNode *new_node, **position;

	/* Determine where to insert the node. */
	/* 判断插入结点的地方 */
	if(node == NULL)
	{
		/* Allow insertion at the root only in an empty tree. */
		/* 插入点为root时，树要为空 */
		if(bitree_size(tree)>0)
			return -1;
		position = &tree->root;
	}
	else
	{
		/* Normally allow insertion only at the end of a branch. */
		/* 正常插入时为分支末端 */
		if(bitree_left(node) != NULL)
			return -1;
		position = &node->left;
	}

	/* Allocate storage for the node. */
	/* 分配结点存储空间 */
	if((new_node = (BiTreeNode *)malloc(sizeof(BiTreeNode))) == NULL)
		return -1;
	/* Insert the node into the tree. */
	/* 插入结点到树 */
	new_node->data = (void *)data;
	new_node->left = NULL;
	new_node->right = NULL;
	*position = new_node;

	/* Adjust the size of the tree to account for the inserted node. */
	/* 调整树的大小 */
	tree->size++;

	return 0;
}

/* bitree_ins_right */
/* 返回值：0，成功；-1，失败 */
int bitree_ins_right(BiTree *tree, BiTreeNode *node, const void *data)
{
	BiTreeNode *new_node, **position;

	/* Determine where to insert the node. */
	/* 判断插入结点的地方 */
	if(node == NULL)
	{
		/* Allow insertion at the root only in an empty tree. */
		/* 插入点为root时，树要为空 */
		if(bitree_size(tree)>0)
			return -1;
		position = &tree->root;
	}
	else
	{
		/* Normally allow insertion only at the end of a branch. */
		/* 正常插入时为分支末端 */
		if(bitree_right(node) != NULL)
			return -1;
		position = &node->right;
	}

	/* Allocate storage for the node. */
	/* 分配结点存储空间 */
	if((new_node = (BiTreeNode *)malloc(sizeof(BiTreeNode))) == NULL)
		return -1;
	/* Insert the node into the tree. */
	/* 插入结点到树 */
	new_node->data = (void *)data;
	new_node->left = NULL;
	new_node->right = NULL;
	*position = new_node;

	/* Adjust the size of the tree to account for the inserted node. */
	/* 调整树的大小 */
	tree->size++;

	return 0;
}

/* bitree_rem_left
 * 移除tree指定的二叉树中node的左子结点为根的子树
 * 返回值：无
 */
void bitree_rem_left(BiTree *tree, BiTreeNode *node)
{
	BiTreeNode **position;

	/* Do not allow removal from an empty tree. */
	/* 树为空，无法删除，直接返回 */
	if(bitree_size(tree) == 0)
		return;
	/* Determine where to remove nodes. */
	/* 判断删除结点的位置 */
	if(node == NULL)
		position = &tree->root;
	else
		position = &node->left;

	/* Remove the nodes. */
	/* 删除结点 */
	if(*position != NULL)
	{
		bitree_rem_left(tree, *position);
		bitree_rem_right(tree, *position);
		
		if(tree->destroy != NULL)
		{
			/* Call a user-defined function to free dynamically allocated data. */
			tree->destroy((*position)->data);
		}	
		free(*position);
		*position = NULL;

		/* Adjust the size of the tree to account for the removed node. */
		tree->size--;
	}
	return ;
}

/* bitree_rem_right */
void bitree_rem_right(BiTree *tree, BiTreeNode *node)
{
	BiTreeNode **position;

	/* Do not allow removal from an empty tree. */
	/* 树为空，无法删除，直接返回 */
	if(bitree_size(tree) == 0)
		return;
	/* Determine where to remove nodes. */
	/* 判断删除结点的位置 */
	if(node == NULL)
		position = &tree->root;
	else
		position = &node->right;

	/* Remove the nodes. */
	/* 删除结点 */
	if(*position != NULL)
	{
		bitree_rem_left(tree, *position);
		bitree_rem_right(tree, *position);
		
		if(tree->destroy != NULL)
		{
			/* Call a user-defined function to free dynamically allocated data. */
			tree->destroy((*position)->data);
		}	
		free(*position);
		*position = NULL;

		/* Adjust the size of the tree to account for the removed node. */
		/* 调整树的大小值 */
		tree->size--;
	}
	return ;
}

/* bitree_merge */
int bitree_merge(BiTree *merge, BiTree *left,
		BiTree *right, const void *data)
{
	/* Initialize the merged tree. */
	bitree_init(merge, left->destroy);
	
	/* Insert the data for the root node of the merged tree. */
	if(bitree_ins_left(merge, NULL, data) != 0)
	{
		bitree_destroy(merge);
		return -1;
	}

	/* Merge the two binary trees into a single binary tree. */
	bitree_root(merge)->left = bitree_root(left);
	bitree_root(merge)->right = bitree_root(right);

	/* Adjust the size of the new binary tree. */
	merge->size = merge->size + bitree_size(left) + bitree_size(right);

	/* Do not let the original trees access the merged node. */
	left->root = NULL;
	left->size = 0;
	right->root = NULL;
	right->size = 0;

	return 0;
}
