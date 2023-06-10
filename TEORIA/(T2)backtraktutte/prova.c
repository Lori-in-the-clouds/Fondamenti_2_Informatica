#include <stdio.h>
void BacktrackTutte(int n, int i, int k, int vcurr[], int* nsol) {

	if (i == n) {
		printf("%d) ", *nsol);
		(*nsol)++;
		for (int j = 0; j < n; j++) {
			printf("%d ", vcurr[j]);
		}
		printf("\n");
		return;
	}
	for (int j = 0; j < k/*2*/; j++) {
		vcurr[i] = j;
		BacktrackTutte(n, i + 1, k, vcurr, nsol);
	}
	//arrivando qui finisce la funzione e ritorna al record di attivazione di prima 
}