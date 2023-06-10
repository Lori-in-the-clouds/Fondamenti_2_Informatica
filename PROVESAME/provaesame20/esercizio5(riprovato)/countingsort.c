#include <stdlib.h>
void CountingSort(int* v, size_t v_size) {
	if (v == NULL || v_size == 0) return;
	int max = v[0];
	int min = v[0];
	for (int j = 0; j < v_size; j++) {
		if (v[j] > max) max = v[j];
		if (v[j] < min) min = v[j];
	}
	int* v1 = calloc(max - min + 1, sizeof(int));
	for (int i = min; i <= max; i++) {
		int curr = 0;
		for (int j = 0; j < v_size; j++) {
			if (v[j] == i) curr++;
		}
		v1[i-min] = curr;
	}
	int size = 0;
	for (int j = 0; j < max - min + 1; j++) {
		for (int i = 0; i < v1[j]; i++) {
			v[size] = j + min;
			size++;
		}
	}
	free(v1);
	return;
}
