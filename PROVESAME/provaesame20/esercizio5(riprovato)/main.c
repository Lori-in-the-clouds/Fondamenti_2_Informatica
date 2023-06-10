#include <stdlib.h>
extern void CountingSort(int* v, size_t v_size);
int main(void) {
	int* v = malloc(3 * sizeof(int));
	v[0] = -2;
	v[1] = 3;
	v[2] = 1;
	CountingSort(v, 3);
}