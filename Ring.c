#include "Ring.h"

ring* create_ring(
	size_t size,
	void* zero,
	void* (*sum)(void*, void*),
	void* (*mult)(void*, void*),
	int* (*comp)(void*, void*)
)
{
	ring* ring_info = malloc(sizeof(ring));
	ring_info->zero = malloc(sizeof(size));
	memcpy(ring_info->zero, zero, size);
	ring_info->size = size;
	ring_info->sum = sum;
	ring_info->mult = mult;
	ring_info->comp = comp;
	return ring_info;
}

void del_ring(ring** r)
{
	free((*r)->zero);
	free(( *r));
	//*r = NULL;
}

ring* ringcpy(ring* r, ring* p)
{
	memcpy(r, p, sizeof(ring));
	r->zero = malloc(p->size);
	memcpy(r->zero, p->zero, p->size);
}