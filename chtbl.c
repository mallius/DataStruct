/* chtbl.c */
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "chtbl.h"

/* chtbl_init */
/* 返回值：0，成功；-1，失败 */
int chtbl_init(CHTbl *htbl, int buckets, int (*h)(const void *key), 
		int (*match)(const void *key1, const void *key2), void (*destroy)(void *data))
{
	int i;
	
	/* Allocate space for the hash table. */
	/* 分配哈希表空间 */
	if((htbl->table = (List *)malloc(buckets * sizeof(List))) == NULL)
		return -1;

	/* Initialize the buckets. */
	/* 初始化桶数 */
	htbl->buckets = buckets;
	for(i = 0; i<htbl->buckets; i++)
	{
		list_init(&htbl->table[i], destroy);
	}

	/* Encapsulate the functions. */
	htbl->h = h;
	htbl->match = match;
	htbl->destroy = destroy;

	/* Initialize the number of elements in the table. */
	htbl->size = 0;

	return 0;
}

/* chtbl_destroy */
void chtbl_destroy(CHTbl *htbl)
{
	int i;

	/* Destroy each bucket. */
	/* 销毁每个链表 */
	for(i = 0; i < htbl->buckets; i++)
	{
		list_destroy(&htbl->table[i]);
	}
	
	/* Free the storage allocated for the hash table. */
	/* 释放哈希表分配的空间 */
	free(htbl->table);

	/* No operations are allowd now, but clear the structe as a precaution. */
	memset(htbl, 0, sizeof(CHTbl));

	return ;
}

/* chtbl_insert */
/* 返回值：0，成功；-1，失败；1，数据已存在 */
int chtbl_insert(CHTbl *htbl, const void *data)
{
	void *temp;
	int bucket, retval;

	/* Do nothing if the data is already in the table. */
	/* 数据已在表中 */
	temp = (void *)data;
	if(chtbl_lookup(htbl, &temp) == 0)
	{
		return 1;
	}

	/* Hash the key */
	/* 产生哈希值 */
	bucket = htbl->h(data) % htbl->buckets;

	/* Insert the data into the bucket. */
	/* 插入对应的桶中 */
	if((retval = list_ins_next(&htbl->table[bucket], NULL, data)) == 0)
		htbl->size++;

	return retval;
}

/* chtbl_remove */
int chtbl_remove(CHTbl *htbl,  void **data)
{
	ListElmt *element, *prev;
	int bucket;

	/* Hash the key */
	bucket = htbl->h(*data) % htbl->buckets;



}

/* chtbl_lookup */
int chtbl_lookup(const CHTbl *htbl, void **data)
{
	
}
