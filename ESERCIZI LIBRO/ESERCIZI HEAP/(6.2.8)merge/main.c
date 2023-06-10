#include <stdlib.h>
#include <string.h>
#include "minheap.h"
extern Heap* HeapMerge(const Heap* h1, const Heap* h2);
Heap* HeapMinHeapify(const ElemType* v, size_t v_size) {
	if (v_size <= 0) return HeapCreateEmpty();
	Heap* ris = HeapCreateEmpty();
	ris->data = malloc(v_size * sizeof(ElemType));
	ris->size = v_size;
	memcpy(ris->data, v, v_size * sizeof(ElemType));
	for (int i = (int)v_size - 1; i >= 0; i--) {
		HeapMinMoveDown(ris, i);
	}
	return ris;
}
int main(void) {
	ElemType v[] = { 0,12,4,21 };
	ElemType v2[] = { -1,3,6 };
	size_t size = sizeof(v) / sizeof(ElemType);
	size_t size2 = sizeof(v2) / sizeof(ElemType);
	Heap* h1 = HeapMinHeapify(v, size);
	Heap* h2 = HeapMinHeapify(v2, size2);
	Heap* ris = HeapMerge(h1, h2);
}