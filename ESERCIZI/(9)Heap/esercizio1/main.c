#include "minheap.h"
extern Heap* HeapMinHeapify(const ElemType* v, size_t v_size);
int main(void) {
	ElemType v[] = { 7,2,8,4,5,6,1,3 };
	HeapMinHeapify(v, 8);
	return 0;
}