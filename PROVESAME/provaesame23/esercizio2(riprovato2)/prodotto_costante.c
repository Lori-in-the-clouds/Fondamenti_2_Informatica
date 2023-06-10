#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
void rec(int n, const int* s, int* vcurr, int* vbest, bool* preso, int i,bool control) {
	if (control || i==n*n) {
		int* som1 = calloc(n, sizeof(int));
		int s = 0;
		for (int j = 0; j < n; j++) som1[j] = 1;
		for (int r = 0; r < n; r++) {
			for (int c = 0; c < n; c++) {
				som1[s] *= vcurr[r * n + c];
			}
			s++;
		}
		for (int j = 0; j < n-1; j++) {
			if (som1[j] != som1[j + 1]) {
				control = false;
				free(som1);
				return;
			}
		}
		//controlliamo colonne
		for (int j = 0; j < n; j++) som1[j] = 1;
		s = 0;
		for (int c = 0; c < n; c++) {
			for (int r = 0; r < n; r++) {
				som1[s] *= vcurr[r * n + c];
			}
			s++;
		}
		for (int j = 0; j < n - 1; j++) {
			if (som1[j] != som1[j + 1]) {
				control = false;
				free(som1);
				return;
			}
		} 
		memcpy(vbest, vcurr, n * n * sizeof(int));
		control = false;
		free(som1);
		return;
	}
	for (int j = 0; j < n*n; j++) {
		if (!preso[j]) {
			vcurr[i] = s[j];
			preso[j] = true;
			rec(n, s, vcurr, vbest, preso, i + 1,false);
			preso[j] = false;
		}
	}
	rec(n, s, vcurr, vbest, preso, i,true);
}
int* RisolviProdotto(int n, const int* s) {
	int* vcurr = calloc(n*n , sizeof(int));
	int* vbest = calloc(n*n, sizeof(int));
	bool* preso = calloc(n * n, sizeof(bool));
	rec(n, s, vcurr, vbest, preso, 0,false);
	bool control = false;
	for (int j = 0; j < n * n; j++) {
		if (vbest[j] != 0) control = true;
	}
	free(vcurr);
	free(preso);
	if (control) {
		return vbest;
	}
	else {
		free(vbest);
		return NULL;
	}
}
