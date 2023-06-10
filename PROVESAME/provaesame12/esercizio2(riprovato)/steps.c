#include <stdlib.h>
#include <stdio.h>
void rec(int n, int* vcurr, int* ris, int i,int som) {
	if (som > n) return;
	if (som == n) {
		printf("[");
		for (int j = 0; j < i-1; j++) {
			printf("%d, ", vcurr[j]);
		}
		printf("%d], ", vcurr[i - 1]);
		ris[0]++;
		return;
	}
	if (i == n) return;
	for (int j = 1; j <= 3; j++) {
		vcurr[i] = j;
		rec(n, vcurr, ris, i + 1, som + j);
	}
}
int Steps(int n) {
	if (n <= 0) return 0;
	int* vcurr = calloc(n,sizeof(int));
	int ris = 0;
	rec(n, vcurr, &ris, 0,0);
	free(vcurr);
	return ris;
}