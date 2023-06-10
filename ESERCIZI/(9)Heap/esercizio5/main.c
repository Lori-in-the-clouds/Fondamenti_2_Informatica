#include "minheap.h"
#include <stdlib.h>
extern void HeapMinHeapsort(Heap* h);
int main(void) {
	Heap* h = HeapCreateEmpty();
	ElemType v[] = { 1,5,4,6,12,23 };
	h->size = 6;
	h->data = malloc(h->size, sizeof(ElemType));
	for (size_t j = 0; j < h->size; j++) {
		h->data[j] = v[j];
	}
	HeapMinHeapsort(h);
	return 0;
}