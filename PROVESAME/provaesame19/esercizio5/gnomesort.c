#include <stdlib.h>
void GnomeSort(int* v, size_t v_size) {
	if (v == NULL) {
		return;
	}
	size_t j = 1;
	while (j != v_size) {
		if (v[j] >= v[j - 1]) {
			j++;
		}
		else {
			int a = v[j];
			v[j] = v[j- 1];
			v[j - 1] = a;
			j--;
		}

	}
}