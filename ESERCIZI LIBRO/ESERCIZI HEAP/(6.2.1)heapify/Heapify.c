#include "minheap.h"
#include <stdlib.h>
#include <string.h>
Heap* HeapMinHeapify(const ElemType* v, size_t v_size) {
	if (v_size <= 0) return HeapCreateEmpty();
	Heap* ris = HeapCreateEmpty();
	ris->data = malloc(v_size, sizeof(ElemType));
	ris->size = v_size;
	memcpy(ris->data, v, v_size * sizeof(ElemType));
	for (int i = v_size-1; i >= 0; i--) {
		HeapMinMoveDown(ris,i);
	}
	return ris;
}