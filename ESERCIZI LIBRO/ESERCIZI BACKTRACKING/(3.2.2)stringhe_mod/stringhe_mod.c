#include <stdlib.h>
#include <stdio.h>
void BackTrackStrModRec(int n, int k, int* vcurr, int i) {
	if (i == k) {
		printf(" { ");
		for (int j = 0; j < k; j++) {
			char lettera = 'a';
			printf("%c", lettera + vcurr[j]);
		}
		printf(" },");
		return;
	}
	for (int j = 0; j < n; j++) {
		vcurr[i] = j;
		BackTrackStrModRec(n, k, vcurr, i + 1);
	}
}
void BackTrackStrMod(int n, int k) {
	if (k <= 0 || k > 26 || n <= 0) {
		return;
	}
	int* vcurr = calloc(k, sizeof(int));
	BackTrackStrModRec(n, k, vcurr, 0);
	return;
}

void rec(int n, int* vcurr, int i) {
	if (i == n) {
		for (int j = 0; j < n; j++) {
			printf("%d", vcurr[j]);
		}
		printf("\n");
		return;
	}

	for (int j = i; j <= n; j++) {
		vcurr[i] = j;
		rec(n, vcurr, j+1);
	}
}
void prova(int n) {
	int *vcurr = calloc(n,sizeof(int));
	rec(n,vcurr, 0);
}