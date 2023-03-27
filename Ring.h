#ifndef RING_H
#define RING_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Ring
{
	size_t size;
	void* zero;//нулевой
	void* (*sum)(void*, void*);//сумма
	void* (*mult)(void*, void*);//перемножение
	int* (*comp)(void*, void*);//сравнение элементов, -1 меньше, 1 больше, 0 равно,
	//void* (*mult_sc)(void*, void*);//умножение на скал€р
	//void* (*argue)(void*, void*);//подстановка аргумента
	//void* (*comp)(void*, void*);//композици€
} ring;

ring* create_ring(
	size_t size,
	void* zero,
	void* (*sum)(void*, void*),
	void* (*mult)(void*, void*),
	int* (*comp)(void*, void*)
);

void del_ring(ring** r);

ring* ringcpy(ring* r, ring* p);
#endif // !RING_H