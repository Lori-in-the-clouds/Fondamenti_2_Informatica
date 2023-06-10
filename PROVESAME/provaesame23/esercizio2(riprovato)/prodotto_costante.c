#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
//bool Verifica(int* vcurr, int n) {  //VA BENE MA è TROPPO LENTO MI DA INFINITE LOOP
//	//controllo righe 
//	int* somriga = malloc((n+1)*sizeof(int));
//	for (int j = 0; j < n; j++) somriga[j] = 1;
//	for (int r = 0; r < n; r++) {
//		for (int c = 0; c < n; c++) {
//			somriga[r] *= vcurr[r * n + c];
//		}
//	}
//	for (int j = 0; j < n-2; j++) {
//		if (somriga[j] != somriga[j + 1]) return false;
//	}
//	free(somriga);
//	//controllo colonne
//	int* somcolonne = malloc((n+1)* sizeof(int));
//	for (int j = 0; j < n; j++) somcolonne[j] = 1;
//	for (int c = 0; c < n; c++) {
//		for (int r = 0; r < n; r++) {
//			somcolonne[c] *= vcurr[r * n + c];
//		}
//	}
//	for (int j = 0; j < n - 2; j++) {
//		if (somcolonne[j] != somcolonne[j + 1]) return false;
//	}
//	free(somcolonne);
//	return true;
//}
bool Verifica(int* vcurr, int n) {
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
void rec(int n,const int* s, int* vcurr, bool* preso, int i, int* ris) {
	if (i == n*n) {
		if (!Verifica(vcurr, n)) return;
		memcpy(ris, vcurr, n * n * sizeof(int));
		return;
	}
	for (int j = 0; j < n * n; j++) {
		if (!preso[j]) {
			vcurr[i] = s[j];
			preso[j] = true;
			rec(n, s, vcurr, preso, i + 1, ris);
			vcurr[i] = 0;
			preso[j] = false;
		}
	}
}
int* RisolviProdotto(int n, const int* s) {
	int* vcurr = calloc((n * n), sizeof(int));
	bool* preso = calloc((n * n), sizeof(bool));
	int *ris = calloc(n * n, sizeof(int));
	rec(n, s, vcurr, preso, 0, ris);
	free(vcurr);
	free(preso);
	int control = 0;
	for (int j = 0; j < n * n; j++) {
		if (ris[j] == 0) control++;
	}
	if (control == n * n) {
		free(ris);
		return NULL;
	}
	return ris;
}