#include <stdio.h>
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdlib.h>
#include "Ring.h"
#include "hashtable.h"
#include "Pair.h"
#include "C:\Users\kiral\Desktop\sem2_lab1\variable_int.h"
#include "C:\Users\kiral\Desktop\sem2_lab1\variable_float.h"

int main()
{
	float* zero = calloc(1, sizeof(float)),*f = calloc(1,sizeof(float));
	ring* ring_info = create_ring(sizeof(float), zero, sum_float, mult_float, NULL);
	map* my_map = make_map(10, ring_info);
	pair* p;
	for (int i = 0; i < my_map->num; i++)
	{
		*f = 0.1*i;
		p = make_pair(i, f, ring_info->size, NULL);
		push(my_map, p);
		if (i==500)
			printf("");
		//free(p);
		
	}
	float k;
	for (int i = 0; i < my_map->num; i++)
	{
		k = *(float*)take_var(i, my_map);
		if ((float)(0.1*i) != k)
		{
			printf("k %f/ i %f\n", k, 0.1*i);
		}
	}
	printf("%f\n", k);

	printf("%f\n", *(float*)take_var(0, my_map));
	*f = 10;
	p = make_pair(0, f, ring_info->size, NULL);
	push(my_map, p);
	printf("%f\n", *(float*)take_var(0, my_map));

	del_map(my_map);

	printf("%f", *(float*)ring_info->zero);
	del_ring(&ring_info);
	free(zero);
	free(f);
	
	_CrtDumpMemoryLeaks();
}