#include <stdlib.h>
#include <string.h>
#include "minheap.h"
Heap* HeapCopy(const Heap* h) {
	Heap* ris = HeapCreateEmpty();
	ris->size = h->size;
	ris->data = malloc(ris->size * sizeof(Heap));
	for (int i = 0; i < h->size; i++) {
		ris->data[i] = ElemCopy(&h->data[i]);
	}
	return ris;
}
Heap* HeapMerge(const Heap* h1, const Heap* h2) {
	if (HeapIsEmpty(h1) && HeapIsEmpty(h2)) return HeapCreateEmpty();
	if (HeapIsEmpty(h1) && !HeapIsEmpty(h2)) return HeapCopy(h2);
	if (!HeapIsEmpty(h1) && HeapIsEmpty(h2)) return HeapCopy(h1);
	Heap* ris = HeapCreateEmpty();
	ris->size = h1->size + h2->size;
	ris->data = malloc(ris->size * sizeof(ElemType));
	//copiamo il primo
	for (int i = 0; i < h1->size; i++) ris->data[i] = ElemCopy(&h1->data[i]);
	for (int i = h1->size; i < ris->size; i++) {
		 ris->data[i] = ElemCopy(&h2->data[i - h1->size]);
		 HeapMinMoveUp(ris, i);
	}
	return ris;
}