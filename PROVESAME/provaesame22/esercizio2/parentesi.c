#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
void ParentesiRec(int n, int i, int* vcurr, int* nsol) {
	//caso base
	if (i == n) {
		bool* preso = calloc(n,sizeof(bool));
		for (int j = 0; j < n; j++) {
			if (vcurr[j] == 0) {
				for (int k = j + 1; k < n; k++) {
					if (vcurr[k] == 1 && !preso[k]) {
						preso[k] = true;
						preso[j] = true;
						break;
					}
				}
			}
		}
		for (int j = 0; j < n; j++) {
			if (!preso[j]) {
				free(preso);
				return;
			}
		}
		(*nsol)++;
		for (int j = 0; j < n; j++) {
			printf("%c", vcurr[j] + 40);
		}
		printf("\n");
		free(preso);
		return;
	}
	for (int j = 0; j <= 1; j++) {
		vcurr[i] = j;
		ParentesiRec(n, i + 1, vcurr, nsol);
	}
}
int Parentesi(int n) {
	if (n < 0) return -1;
	if (n == 0) return 0;
	int* vcurr = calloc(2*n, sizeof(int));
	int nsol = 0;
	ParentesiRec(n*2, 0, vcurr, &nsol);
	free(vcurr);
	return nsol;
}