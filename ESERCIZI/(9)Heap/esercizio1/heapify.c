#include "minheap.h"
#include <stdlib.h>
int compare(const void* a, const void* b) {
ElemType arg1 = *(const ElemType* )a;
ElemType arg2 = *(const ElemType* )b;
if (ElemCompare(&arg1, &arg2) < 0) return -1;
if (ElemCompare(&arg1, &arg2) > 0) return 1;
return 0;
}

Heap* HeapMinHeapify(const ElemType* v, size_t v_size) {
	Heap* ris = HeapCreateEmpty();
	if (v_size == 0 || v == NULL) {
		return ris;
	}
	ris->size = v_size;
	ris->data = calloc(v_size, sizeof(ElemType));
	qsort((void*)v, v_size, sizeof(ElemType), compare);
	for (size_t i = 0; i < v_size; i++) {
		ris->data[i] = v[i];
	}
	return ris;
	
}