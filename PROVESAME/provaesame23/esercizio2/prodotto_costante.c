#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
bool Verifica(int* vcurr,int n) {
	//controlliamo le righe 
	int som1 = 1;
	int som2 = 1;
	bool control = false;
	for (int r = 0; r < n; r++) {
		som2 = 1;
		for (int c = 0; c < n; c++) {
			if (!control) {
				som1 *= vcurr[r * n + c];
			}
			else som2 *= vcurr[r * n + c];
		}
		if (control) {
			if (som1 != som2) return false;
		}
		control = true;
	}
	//controllaimo le colonne
	som1 = 1;
	som2 = 1;
	control = false;
	for (int c = 0; c < n; c++) {
		som2 = 1;
		for (int r = 0; r < n; r++) {
			if (!control) {
				som1 *= vcurr[r * n + c];
			}
			else som2 *= vcurr[r * n + c];
		}
		if (control) {
			if (som1 != som2) return false;
		}
		control = true;
	}
	return true;
}
void RisolviProdottoRec(int n, const int* s, int* vcurr, int* ris, int i, bool* preso) {
	if (i == n*n) {
		if (!Verifica(vcurr, n)) {
			return;
		}
		memcpy(ris, vcurr, n * n * sizeof(int));
		return;
	}
	for (int j = 0; j < n * n; j++) {
		if (!preso[j]) {
			vcurr[i] = s[j];
			preso[j] = true;
			RisolviProdottoRec(n, s, vcurr, ris, i + 1, preso);
			vcurr[i] = 0;
			preso[j] = false;
		}
	}
}
int* RisolviProdotto(int n, const int* s) {
	int* ris = calloc(n * n, sizeof(int));
	int* vcurr = calloc(n * n, sizeof(int));
	bool* preso = calloc(n * n, sizeof(bool));
	RisolviProdottoRec(n, s, vcurr, ris, 0, preso);
	free(vcurr);
	free(preso);
	return ris;
}