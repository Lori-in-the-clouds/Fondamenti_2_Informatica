#include "string.h"
#include <stdlib.h>
void isnMinore(int* v, size_t v_size, int lastpos) {
	int i = 0;
	int x = v[lastpos];
	for (i = lastpos - 1; i >= 0 && x < v[i]; i--) {
		v[i + 1] = v[i];
	}
	v[i + 1] = x;
	return;
}
void InsertionSort(int* v, size_t v_size) {
	for (int i = 0; i < v_size; i++) {
		isnMinore(v,v_size, i);
	}
	return;
}



