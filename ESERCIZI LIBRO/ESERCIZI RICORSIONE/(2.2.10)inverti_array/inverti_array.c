#include <stdlib.h>
void InvertiArrayRec(int* arr, size_t size,int i) {
	if (size == 0) {
		int tmp = arr[size];
		arr[size] = arr[i];
		arr[i] = tmp;
		return;
	}
	InvertiArrayRec(arr, size-1,i+1);
	if (size >= i) {
		return;
	}
	int tmp = arr[size];
	arr[size] = arr[i];
	arr[i] = tmp;
}
void InvertiArray(int* arr, size_t size) {
	InvertiArrayRec(arr, size-1,0);
}