#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string.h>
#include "Ring.h"
#include "Pair.h"
//#define PRIME 3571

typedef struct Map
{
	pair** list_head;
	size_t num;
	ring* ring_info;
} map;

map* make_map(size_t n, ring* ring_info);

void del_map(map* table);

size_t hash_func(int key, int table_size);

void push(map* table, pair* p);

void* take_var(int key, map* table);
#endif