#include <stdlib.h>
#include "minheap.h"
extern bool IsHeap(const Heap* h);
int main(void) {
	Heap* p = HeapCreateEmpty();
	p->data = malloc(5 * sizeof(int));
	p->data[0] = 1;
	p->data[1] = 3;
	p->data[2] = 4;
	p->data[3] = 6;
	p->data[4] = 4;
	p->size = 5;
	IsHeap(p);
}
