#include "vettore.h"
#include <stdio.h>
Vector* VectorRead(const char* filename) {
	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return NULL;
	}
	Vector *v = malloc(sizeof(Vector));
	v->capacity = 1;
	v->size = 1;
	v->data = malloc(sizeof(ElemType));
	
	while (1) {
		ElemType n = 0;
		int turn1 = ElemRead(f, &n);
		if (turn1 != 1) {
			break;
		}
		v->data[v->capacity - 1] = n;
		v->capacity++;
		v->size++;
		v->data = realloc(v->data, v->size * sizeof(ElemType));
	}
	v->size--; v->capacity--;
	fclose(f);
	return v;
}

Vector* VectorReadSorted(const char* filename) {
	Vector *v = VectorRead(filename);
	if (v == NULL) {
		return NULL;
	}
	for (size_t i = 0; i < v->size; i++) {
		size_t minpos = i;
		for (size_t j = i + 1; j < v->size; j++) {
			if (ElemCompare(&v->data[j], &v->data[minpos]) < 0) {
				minpos = j;
			}
		}
		if (minpos != i) {
			ElemSwap(&v->data[minpos], &v->data[i]);
		}
	}
	return v;
}