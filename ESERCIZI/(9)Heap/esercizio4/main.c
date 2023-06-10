#include "minheap.h"
#include <stdlib.h>
extern bool HeapMinPop(Heap* h, ElemType* e);
int main(void) {
	Heap* n = HeapCreateEmpty();
	n->size = 6;
	n->data = calloc(n->size, sizeof(ElemType));
	ElemType v[] = { 1,5,4,6,12,23 };
	for (size_t i = 0; i < n->size; i++) {
		n->data[i] = v[i];
	}
	ElemType* e = 0;
	HeapMinPop(n, &e);
	return 0;
}
