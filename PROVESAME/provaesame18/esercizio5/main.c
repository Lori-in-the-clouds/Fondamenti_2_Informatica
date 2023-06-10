#include <stdlib.h>
extern void CocktailSort(int* v, size_t v_size);
int main(void) {
	int* v = malloc(4 * sizeof(int));
	v[0] = 4;
	v[1] = 1;
	v[2] = 3;
	v[3] = 2;
	CocktailSort(v, 4);
}