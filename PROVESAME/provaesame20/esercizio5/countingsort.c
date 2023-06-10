#include <stdlib.h>
#include <string.h>
int mx(int* v,size_t v_size) {
	int max = v[0];
	for (int i = 0; i < (int)v_size; i++) {
		if (v[i] > max) max = v[i];
	}
	return max;
}
int mn(int* v,size_t v_size) {
	int min = v[0];
	for (int i = 0; i < (int)v_size; i++) {
		if (v[i] < min) min = v[i];
	}
	return min;
}
void CountingSort(int* v, size_t v_size) {
	if (v == NULL || v_size <= 0) return;
	int n = mx(v, v_size) - mn(v,v_size) + 1;
	int* tmp = calloc(n, sizeof(int));
	int m = 0;
	for (int i = mn(v, v_size); i <= mx(v, v_size); i++) {
		int cont = 0;
		for (int j = 0; j < (int)v_size; j++) {
			if (v[j] == i) cont++;
		}
		tmp[m] = cont;
		m++;
	}
	int x = mn(v, v_size);
	int j = 0;
	for (int i = 0; i < n; i++) {
		int m = j;
		for (j; j < tmp[i] + m; j++) {
			v[j] = x;
		}
		x++;
	}
	free(tmp);
}
		
