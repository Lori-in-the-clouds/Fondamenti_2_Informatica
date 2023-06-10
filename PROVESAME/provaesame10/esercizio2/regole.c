#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void RegoleRec(const char* r, int* vcurr, int n, int i) {
	for (int j = 0;j < i; j++) {
		for (int k = 0; k < i; k++) {
			if (j == k) continue;
			if (vcurr[j] == vcurr[k]) return;
		}
	}
	if (i == n) {
		for (int j = 0; j < n; j++) {
			printf("%d ", vcurr[j]);
		}
		printf("\n");
		return;
	}
	for (int j = 1; j < n+1; j++) {
		vcurr[i] = j;
		if (i != 0) {
			if (r[i-1] == 'I' || r[i-1]== 'i') {
				if (j > vcurr[i - 1]) {
					RegoleRec(r, vcurr, n, i + 1);
				}
			}
			if (r[i-1] == 'D' || r[i - 1] == 'd') {
				if (j < vcurr[i - 1]) {
					RegoleRec(r, vcurr, n, i + 1);
				}
			}
		}
		if (i == 0) RegoleRec(r, vcurr, n, i + 1);
	}
}
void Regole(const char* r) {
	int n = strlen(r);
	if (r == "") {
		printf("1");
		return;
	}
	int* vcurr = calloc(n+1, sizeof(int));
	RegoleRec(r, vcurr, n + 1, 0);
	free(vcurr);

}