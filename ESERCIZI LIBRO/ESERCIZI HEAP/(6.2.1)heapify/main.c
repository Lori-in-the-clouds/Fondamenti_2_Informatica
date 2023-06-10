#include "minheap.h"
extern Heap* HeapMinHeapify(const ElemType* v, size_t v_size);
int main(void) {
	ElemType v[] = { 0,12,4,21,2,18,77,8,9 };
	size_t v_size = sizeof(v) / sizeof(ElemType); //RICORDA
	Heap* ris = HeapMinHeapify(v, v_size);
	HeapWriteStdout(ris);
}