#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
void GolaCrestaRec(size_t n, int* vcurr, int i) {
	for (int j = 0; j < i - 2; j++) {
		bool a = (vcurr[j] < vcurr[j + 1]) && (vcurr[j + 1] > vcurr[j + 2]);
		bool b = (vcurr[j] > vcurr[j + 1] && vcurr[j + 1] < vcurr[j + 2]);
		if (!(a || b)) return;
	}
	if (i == n) {
		printf("(");
		for (int j = 0; j < n-1; j++) {
			printf("%d, ", vcurr[j]);
		}
		printf("%d), ", vcurr[n - 1]);
		return;
	}
	for (int j = 0; j < 3; j++) {
		vcurr[i] = j;
		GolaCrestaRec(n, vcurr, i + 1);
	}
}
void GolaCresta(size_t n) {
	if (n < 3) {
		return;
	}
	int* vcurr = calloc(n, sizeof(int));
	GolaCrestaRec(n, vcurr, 0);
	free(vcurr);
	return;
}