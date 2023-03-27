#include "hashtable.h"
#define PRIME 3571

map* make_map(
	size_t n,
	ring* ring_info
)
{
	map* result = malloc(sizeof(map));
	result->list_head = calloc(n, sizeof(pair*));
	result->num = n;
	result->ring_info = malloc(sizeof(ring));
	ringcpy(result->ring_info, ring_info);
	return result;
}

void del_map(map* table)
{
	if (table == NULL)return;

	for (int i = 0; i < table->num; i++)
	{
		del_pair((table->list_head + i));
	}
	free(table->list_head);
	del_ring(&(table->ring_info));
	//free(table->ring_info);
	free(table);
	
	table = NULL;
}

size_t hash_func(int key, int table_size)
{
	int result = key * PRIME;
	result %= table_size;
	return (size_t)result;
}

void push(map* table, pair* p)
{
	int key = p->key;
	size_t pos = hash_func(key, table->num);

	if (*(table->list_head + pos) == NULL)
	{
		//*(table->list_head + pos) = make_pair(0, NULL, 1, NULL);
		*(table->list_head + pos) = malloc(sizeof(pair));
		paircpy(*(table->list_head + pos),p);
		del_pair(&p);
	}
	else
	{
		add_pair(*(table->list_head + pos), p, table->ring_info->sum);
	}
}

void* take_var(int key, map* table)
{
	size_t pos = hash_func(key, table->num);
	//void* result = malloc(table->ring_info->size);
	pair* ptr = *(table->list_head + pos);
	do
	{
		if (ptr->key == key)
			return ptr->variable;
		ptr = ptr->next;
	} while (ptr!= NULL);
	return NULL;
}