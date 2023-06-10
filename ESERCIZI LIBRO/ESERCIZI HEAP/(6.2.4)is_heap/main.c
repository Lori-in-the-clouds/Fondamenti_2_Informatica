#include "minheap.h"
#include <stdlib.h>
#include <string.h>
extern bool IsHeap(const Heap* h);
extern bool IsHeapRec2(const Heap* h, int i);
Heap* HeapMinHeapify(const ElemType* v, size_t v_size) {
	if (v_size <= 0) return HeapCreateEmpty();
	Heap* ris = HeapCreateEmpty();
	ris->data = malloc(v_size, sizeof(ElemType));
	ris->size = v_size;
	memcpy(ris->data, v, v_size * sizeof(ElemType));
	for (int i = v_size - 1; i >= 0; i--) {
		HeapMinMoveDown(ris, i);
	}
	return ris;
}
int main(void) {
	ElemType v[] = { 0,12,4,21,2,18,77,8,9};
	size_t size = sizeof(v) / sizeof(ElemType);
	Heap* h = HeapCreateEmpty();
	h->size = size;
	h->data = malloc(size * sizeof(ElemType));
	//memcpy(h->data, v, h->size * sizeof(ElemType));
	h = HeapMinHeapify(v,size);
	h->data[3] = 32;
	IsHeap(h);
	IsHeapRec2(h, 0);
}