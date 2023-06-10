#include "minheap.h"
#include <stdlib.h>
#include <string.h>
Heap* HeapCopy(const Heap* h) {
	if (HeapIsEmpty(h)) return HeapCreateEmpty();
	Heap* ris = HeapCreateEmpty();
	ris->size = h->size;
	ris->data = malloc(ris->size * sizeof(Heap));
	for (int i = 0; i < h->size; i++) {
		ris->data[i] = ElemCopy(&h->data[i]);
	}
	return ris;
}