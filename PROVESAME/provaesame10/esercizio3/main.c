#include "list.h"
extern void InsertionSort(int* v, size_t v_size);
int main(void) {
	int v[] = { 1,3,4,2 };
	InsertionSort(v, sizeof(v) / sizeof(int));
}