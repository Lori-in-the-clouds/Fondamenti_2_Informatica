#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
void rec(const char* r, int* vcurr, int i,bool *preso) {
	if (i == strlen(r) + 1) {
		for (int j = 0; j < i; j++) {
			printf("%d ", vcurr[j]);
		}
		printf("\n");
		return;
	}
	for (int j = 1; j <= strlen(r) + 1; j++) {
		if (preso[j-1] == false) {
			if (i != 0) {
				if (((r[i-1] == 'I' || r[i-1] == 'i') && j > vcurr[i - 1]) || ((r[i - 1] == 'D' || r[i-1] == 'd') && j < vcurr[i - 1])) {
					vcurr[i] = j;
					preso[j - 1] = true;
					rec(r, vcurr, i + 1, preso);
					preso[j - 1] = false;
				}
			}
			else {
				vcurr[i] = j;
				preso[j - 1] = true;
				rec(r, vcurr, i + 1, preso);
				preso[j - 1] = false;
			}
			
		}
	}
	//sono bloccato
	return;
}
void Regole(const char* r) {
	int len = strlen(r);
	if (len == 0) {
		printf("1");
		return;
	}
	int* vcurr = calloc(len + 1, sizeof(int));
	bool *preso = calloc(len + 1, sizeof(bool));
	rec(r, vcurr, 0,preso);
	free(vcurr);
	free(preso);
	return;
}