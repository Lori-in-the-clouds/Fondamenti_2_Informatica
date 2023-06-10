#include "minheap.h"
#include <string.h>
#include <stdlib.h>
Heap* MergeHeap(const Heap* h1, const Heap* h2) {
	Heap* ris = HeapCreateEmpty();
	if (HeapIsEmpty(h1) && HeapIsEmpty(h2)) return ris;
	if (!HeapIsEmpty(h1) && HeapIsEmpty(h2)) {
		ris->size = h1->size;
		ris->data = malloc(ris->size * sizeof(int));
		memcpy(ris->data, h1->data, ris->size * sizeof(int));
		return ris;
	}
	if (HeapIsEmpty(h1) && !HeapIsEmpty(h2)) {
		ris->size = h2->size;
		ris->data = malloc(ris->size * sizeof(int));
		memcpy(ris->data, h2->data, ris->size * sizeof(int));
		return ris;
	}
	ris->size = h1->size;
	ris->data = malloc(ris->size * sizeof(int));
	memcpy(ris->data, h1->data, ris->size * sizeof(int));
	//inseriamo 
	for (int j = 0; j < h2->size; j++) {
		ris->data = realloc(ris->data, (++ris->size) * sizeof(int));
		ris->data[ris->size - 1] = h2->data[j];
		HeapMinMoveUp(ris, ris->size - 1);
	}
	return ris;
}