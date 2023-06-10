#include "minheap.h"
#include <string.h>
#include <stdlib.h>
extern Heap* MergeHeap(const Heap* h1, const Heap* h2);
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
	ElemType v[] = { 0,12,4,21,2,18,77,8,9 };
	size_t size = sizeof(v) / sizeof(ElemType);
	/*ElemType e[] = { 5,99,88 };*/
	Heap* h = HeapMinHeapify(v, size);
	 //size = sizeof(e) / sizeof(ElemType);

	//Heap* h2 = HeapMinHeapify(e, size);
	Heap* h2 = HeapCreateEmpty();
	MergeHeap(h, h2);
}