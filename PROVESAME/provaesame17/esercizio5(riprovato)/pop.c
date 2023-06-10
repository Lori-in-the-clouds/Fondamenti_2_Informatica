#include "elemtype.h"
#include "minheap.h"
#include <stdlib.h>
bool Pop(Heap* h, ElemType* e) {
	if (HeapIsEmpty(h)) return false;
	*e = *HeapGetNodeValue(h, 0);
	ElemSwap(&h->data[0], &h->data[h->size - 1]);
	h->size--;
	h->data = realloc(h->data, h->size * sizeof(ElemType));
	HeapMinMoveDown(h, 0);
	return true;
}


//int main(void) {
//	Heap* h = HeapCreateEmpty();
//	h->size = 5;
//	h->data = malloc(5 * sizeof(ElemType));
//	h->data[0] = 1;
//	h->data[1] = 3;
//	h->data[2] = 4;
//	h->data[3] = 6;
//	h->data[4] = 4;
//
//	ElemType e = 0;
//
//	Pop(h, &e);
//}



