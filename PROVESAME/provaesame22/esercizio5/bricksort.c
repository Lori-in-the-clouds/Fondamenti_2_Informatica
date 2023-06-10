#include <stdlib.h>
void BrickSort(int* v, size_t v_size) {
	if (v == NULL || v_size < 1) return;
	int dim = v_size;
	while (dim > 1) {
		for (int i = 1; i <= v_size - 2; i+=2) {
			if (v[i] > v[i + 1]) {
				//scambiamo
				int tmp = v[i];
				v[i] = v[i + 1];
				v[i + 1] = tmp;
			}
		}
		for (int i = 0; i <= v_size - 2; i+=2) {
			if (v[i] > v[i + 1]) {
				//scambiamo
				int tmp = v[i];
				v[i] = v[i + 1];
				v[i + 1] = tmp;
			}
		}
		dim--;
	}
	return;
}