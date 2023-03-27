#ifndef RING_H
#define RING_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Ring
{
	size_t size;
	void* zero;//�������
	void* (*sum)(void*, void*);//�����
	void* (*mult)(void*, void*);//������������
	int* (*comp)(void*, void*);//��������� ���������, -1 ������, 1 ������, 0 �����,
	//void* (*mult_sc)(void*, void*);//��������� �� ������
	//void* (*argue)(void*, void*);//����������� ���������
	//void* (*comp)(void*, void*);//����������
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