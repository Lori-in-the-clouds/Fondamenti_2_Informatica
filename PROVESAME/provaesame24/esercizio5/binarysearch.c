#include <stdlib.h>
int rec(const int* v,int starter,int finisher,int value, int pivot) {
	if (value == v[pivot]) return pivot;
	if (starter == finisher - 1) return -1;
	if (value > v[pivot]) return rec(v, pivot, finisher, value, (starter + finisher) / 2);
	if (value < v[pivot]) return  rec(v, starter, pivot, value, pivot / 2);
}
int BinarySearch(const int* v, size_t v_size, int value) {
	if (v_size == NULL || v_size <= 0) return - 1;
	return rec(v, 0, (int)v_size, value, (int)v_size / 2);
}