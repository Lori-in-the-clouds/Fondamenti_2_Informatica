#include "minheap.h"
#include <string.h> 
#include <stdlib.h>
int KthLeast(const int* v, size_t n, int k) {
	Heap* h = HeapCreateEmpty();
	h->size = n;
	h->data = malloc(n * sizeof(int));
	memcpy(h->data, v, n * sizeof(int));
	for (int i = h->size - 1; i >= 0; i--) {
		HeapMinMoveUp(h, i);
	}
	for (int i = 0; i < k - 1; i++) {
		ElemSwap(&h->data[0], &h->data[h->size - 1]);
		h->data = realloc(h->data, (--h->size) * sizeof(int));
		HeapMinMoveDown(h, 0);
	}
	return h->data[0];
}