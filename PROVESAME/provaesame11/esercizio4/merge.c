#include "minheap.h"
#include <stdlib.h>
#include <string.h>
Heap* MergeHeap(const Heap* h1, const Heap* h2) {
	if (HeapIsEmpty(h1) && HeapIsEmpty(h2)) return HeapCreateEmpty();
	Heap* ris = HeapCreateEmpty();
	if (!HeapIsEmpty(h1) && HeapIsEmpty(h2)) {
		ris->size = h1->size;
		ris->data = malloc(ris->size * sizeof(int));
		memcpy(ris->data, h1->data, h1->size * sizeof(int));
		return ris;
	}
	if (HeapIsEmpty(h1) && !HeapIsEmpty(h2)) {
		ris->size = h2->size;
		ris->data = malloc(ris->size * sizeof(int));
		memcpy(ris->data, h2->data, h2->size * sizeof(int));
		return ris;
	}
	ris->size = h1->size;
	ris->data = malloc(ris->size * sizeof(int));
	memcpy(ris->data, h1->data, h1->size * sizeof(int));
	for (int i = 0; i < (int)h2->size; i++) {
		ris->data = realloc(ris->data, (++ris->size) * sizeof(int));
		ris->data[ris->size - 1] = h2->data[i];
		HeapMinMoveUp(ris, ris->size - 1);
	}
	return ris;
}