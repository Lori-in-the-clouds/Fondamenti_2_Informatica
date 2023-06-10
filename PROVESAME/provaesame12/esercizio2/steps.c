#include <stdio.h>
#include <stdlib.h>
void StepsRec(int n, int* vcurr, int i, int* nsol,int som) {
	if (som > n) return;
	if (som == n) {
		(*nsol)++;
		printf("[");
		for (int j = 0; j < i - 1; j++) {
			printf("%d, ", vcurr[j]);
		}
		printf("%d], ", vcurr[i - 1]);
		return;
	}
	for (int j = 1; j <= 3; j++) {
		if (som <= n) {
			vcurr[i] = j;
			StepsRec(n, vcurr, i + 1, nsol, som + j);
			vcurr[i] = 0;
		}
	}
}
int Steps(int n) {
	if (n <= 0) return 0;
	int* vcurr = calloc(n,sizeof(int));
	int nsol = 0;
	StepsRec(n, vcurr, 0, &nsol,0);
	free(vcurr);
	return nsol;
}