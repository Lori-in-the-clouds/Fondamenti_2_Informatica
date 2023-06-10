#include "elemtype.h"
#include "minheap.h"
#include <stdlib.h>
#include <string.h>
Heap* MergeHeap(const Heap* h1, const Heap* h2) {
	if (HeapIsEmpty(h1) && HeapIsEmpty(h2)) return HeapCreateEmpty();
	Heap* ris = HeapCreateEmpty();
	if (HeapIsEmpty(h1)) {
		ris->size = h2->size;
		ris->data = malloc(ris->size *sizeof(ElemType));
		memcpy(ris->data, h2->data, ris->size * sizeof(ElemType));
		return ris;
	}
	if (HeapIsEmpty(h2)) {
		ris->size = h1->size;
		ris->data = malloc(ris->size *sizeof(ElemType));
		memcpy(ris->data, h1->data, ris->size * sizeof(ElemType));
		return ris;
	}
	
	ris->size = h1->size;
	ris->data = malloc(h1->size *sizeof(ElemType));
	memcpy(ris->data, h1->data, h1->size * sizeof(ElemType));
	size_t h_size = h1->size;
	for (int j = 0; j < h2->size; j++) {
		h_size++;
		ris->data = realloc(ris->data, h_size * sizeof(ElemType));
		ris->size = h_size;
		ris->data[h_size - 1] = h2->data[j];
		HeapMinMoveUp(ris, h_size - 1);
	}
	return ris;
}
//int main(void) {
//	Heap* h1 = HeapCreateEmpty();
//	Heap* h2 = HeapCreateEmpty();
//	h1->data = calloc(4, sizeof(ElemType));
//	h1->size = 4;
//	h1->data[0] = 0;
//	h1->data[1] = 12;
//	h1->data[2] = 4;
//	h1->data[3] = 21;
//
//
//	h2->data = calloc(4, sizeof(ElemType));
//	h2->size = 4;
//	h2->data[0] = -1;
//	h2->data[1] = 3;
//	h2->data[2] = 6;
//	h2->data[3] = 4;
//
//	Heap *ris = MergeHeap(h1, h2);
//
//}
