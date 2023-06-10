#include <stdlib.h>
#include <stdio.h>
void BacktrackStrRec(int n, int* vcurr, int i) {
	if (i == n) {
		printf(" { ");
		for (int j = 0; j < n; j++) {
			char lettera = 'a';
			printf("%c", lettera + vcurr[j]);
		}
		printf(" },");
		return;
	}
	for (int j = 0; j < n; j++) {
		vcurr[i] = j;
		BacktrackStrRec(n, vcurr, i + 1);
	}
}
void BacktrackStr(int n) {
	if (n <= 0 || n>26) {
		return;
	}
	int* vcurr = calloc(n,sizeof(int));
	BacktrackStrRec(n, vcurr, 0);
 }
