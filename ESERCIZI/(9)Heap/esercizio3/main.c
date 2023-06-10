#include "minheap.h"
#include <stdlib.h>
extern void HeapMinMoveDownRec(Heap* h, int i);
int main(void) {
	Heap* n = HeapCreateEmpty();
	n->size = 6;
	n->data = calloc(n->size, sizeof(ElemType));
	ElemType v[] = { 1,2,4,6,12,23 };
	for (size_t i = 0; i < n->size; i++) {
		n->data[i] = v[i];
	}
	HeapMinMoveDownRec(n, 0);
	return 0;
}