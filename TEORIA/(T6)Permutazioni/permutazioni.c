#include <stdlib.h>
#include <stdio.h>
void PermutazioniRec(int n, int i, int vcurr[],int *nsol) {
	//filtro
	for (int j = 0; j < i; j++) {
		for (int m = 0; m < i; m++) {
			if (j == m) {
				continue;
			}
			if (vcurr[j] == vcurr[m]) {
				return;
			}
		}
	}
	if (i == n) {
		for (int j = 0; j < n; j++) {
			printf("%d ", vcurr[j]);
		}
		printf("\n");
		(*nsol)++;
		return;
	}
	for (int j = 1; j < n+1; j++) {
		vcurr[i] = j;
		PermutazioniRec(n, i + 1, vcurr,nsol);
	}
}
	void Permutazioni(int n) {
		if (n < 0 || n == 0) {
		return;
		}
		int* vcurr = malloc(n * sizeof(int));
			for (int j = 0; j < n; j++) {
				vcurr[j] = 0;
			}
			int* nsol = malloc(1 * sizeof(int));
			nsol[0] = 0;
			PermutazioniRec(n, 0, vcurr,nsol);
			printf("Numero di soluzioni: %d", nsol[0]);
			return;
}