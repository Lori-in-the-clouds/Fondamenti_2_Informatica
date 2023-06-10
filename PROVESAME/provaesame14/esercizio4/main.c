#include "minheap.h"
#include <stdlib.h>
extern void HeapDeleteNode(Heap* h, int k);
int main(void) {
	Heap* n = HeapCreateEmpty();
	n->size = 5;
	n->data = malloc(5 * sizeof(ElemType));
	int v[] = {0,2,4,8,12,18,77,21,9};
	for (int j = 0; j < n->size; j++) {
		n->data[j] = v[j];
	}
	HeapDeleteNode(n, 1);
	return 0;
}