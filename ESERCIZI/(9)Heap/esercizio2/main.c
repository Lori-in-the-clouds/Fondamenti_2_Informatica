#include "minheap.h"
#include <stdlib.h>
extern void HeapMinMoveUpRec(Heap* h, int i);
int main(void) {
	Heap* n = HeapCreateEmpty();
	n->size = 7;
	n->data = calloc(n->size, sizeof(ElemType));
	ElemType v[] = { 1,5,4,6,3,23};
	for (size_t i = 0; i < n->size; i++) {
		n->data[i] = v[i];
	}
	HeapMinMoveUpRec(n, 4);
	return 0;
}