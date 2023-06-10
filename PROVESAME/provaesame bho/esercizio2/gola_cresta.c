#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
void GolaCrestaRec(size_t n, int* vcurr, int i) {
	if (i == n) {
		bool control1 = false;
		bool control2 = false;
		for (int j = 0; j < n-2; j++) {
			
			if (vcurr[j] < vcurr[j + 1] && vcurr[j + 1] > vcurr[j + 2]) {
				control1 = true;
			}
			if (vcurr[j] > vcurr[j + 1] && vcurr[j + 1]  < vcurr[j + 2]) {
				control2 = true;
			}
		}
		if ((control1 || control2) == false) return;

		printf("(");
		for (int j = 0; j < n-1; j++) {
			printf("%d,",vcurr[j]);
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
	if (n < 3) return;
	int* vcurr = calloc(n,sizeof(int));
	GolaCrestaRec(n, vcurr, 0);
	free(vcurr);
	return;
}