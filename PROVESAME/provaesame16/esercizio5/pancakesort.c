#include <stdlib.h>
void flip(int* v, int i) {
	int* tmp = calloc(i + 1, sizeof(int));
	int k = 0;
	for (int j = i; j >=0; j--) {
		tmp[k] = v[j];
		k++;
	}
	for (int j = 0; j < i + 1; j++) {
		v[j] = tmp[j];
	}
	free(tmp);
	return;
}
void PancakeSort(int* v, size_t v_size) {
	int curr_size = (int)v_size;
	while (curr_size > 1) {
		int indice_max = 0;
		int max = v[0];
		for (int i = 0; i < curr_size; i++) {
			if (v[i] > max) {
				indice_max = i;
				max = v[i];
			}
		}
		flip(v, indice_max);
		flip(v, curr_size - 1);
		curr_size--;
	}
	return;
}

