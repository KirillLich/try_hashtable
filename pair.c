#include "Pair.h"

pair* make_pair(int key, void* var, size_t var_size, pair* next)
{
	pair* result = malloc(sizeof(pair));
	result->key = key;
	result->variable = malloc(var_size);
	memcpy(result->variable, var, var_size);
	result->var_size = var_size;
	if (next != NULL)
	{
		result->next = malloc(sizeof(pair));
		paircpy(result->next, next);
	}
	else result->next = NULL;
	return result;
}

pair* paircpy(pair* result, pair* p)
{
	if (p == NULL)
	{
		free(result);
		result = NULL;
		return NULL;
	}
	result->key = p->key;
	result->variable = malloc(p->var_size);
	memcpy(result->variable, p->variable, p->var_size);
	result->var_size = p->var_size;
	if (p->next == NULL) result->next = NULL;
	else paircpy(result->next, p->next);
	return result;
}

void* pair_var(pair* p)
{
	return p->variable;
}

int pair_key(pair* p)
{
	return p->key;
}

void del_pair(pair** p)
{
	if ((*p) == NULL)return;
	if (( * p)->next != NULL)
		del_pair(&((*p)->next));
	free((*p)->variable);
	free((*p));
	(*p) = NULL;
}

void add_pair(pair* list_head, pair* p, void* (*sum)(void*, void*))
{
	pair* ptr = list_head;
	do
	{
		if (p->key == ptr->key)
		{
			void* res = sum(p->variable, ptr->variable);
			free(ptr->variable);
			ptr->variable = res;
			del_pair(&p);
			return;
		}
		if(ptr->next!=NULL)ptr = ptr->next;
	} while (ptr->next != NULL);
	ptr->next = malloc(sizeof(pair));
	paircpy(ptr->next, p);
	del_pair(&p);
}