#include <stdlib.h>
void rec(int* v, int lastpos) {
	int i = 0;
	int x = v[lastpos];
	for (i = lastpos - 1; i >= 0 && x < v[i]; i--) {
		v[i + 1] = v[i];
	}
	v[i + 1] = x;
	return;
}
void InsertionSort(int* v, size_t v_size) {
	for (size_t j = 1; j < v_size; j++) {
		rec(v, j);
	}
	return;
}



//int main(void) {
//	int v[] = { 5,3,7,9,8,1 };
//	InsertionSort(v, sizeof(v) / sizeof(int));
//}