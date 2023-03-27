#ifndef PAIR_H
#define PAIR_H
#include "Ring.h"

typedef struct Pair
{
	int key;
	size_t var_size;
	void* variable;
	struct Pair* next;
} pair;

pair* make_pair(int key, void* var, size_t var_size, pair* next);

pair* paircpy(pair* result, pair* p);

void* pair_var(pair* p);

int pair_key(pair* p);

void del_pair(pair* p);

void add_pair(pair* list_head, pair* p, void* (*sum)(void*,void*));
#endif