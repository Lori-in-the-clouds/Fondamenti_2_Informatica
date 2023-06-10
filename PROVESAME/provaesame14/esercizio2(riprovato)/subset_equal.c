#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
void rec(int n, int s,int i, int som,bool *preso) {
	if (som == s) {
		//printiamo
		printf("{ ");
		for (int j = 1; j <= n; j++) {
			if (preso[j]) {
				printf("%d ", j);
			}
		}
		printf("}, ");
		return;
	}
	if (som > s) return;
	if (i > n) return;
	for (int j = i; j <= n; j++) {
		if (!preso[j]) {
			preso[j] = true;
			rec(n, s, j + 1, som + j, preso); //importante: al posto di i ci va j se non vuoi ripetizioniiii
			preso[j] = false;
		}
	}
	return;
}
void SubsetEqual(int n, int s) {
	if (n <= 0 || s <= 0) return;
	bool* preso = calloc(n+1, sizeof(bool));
	rec(n, s,1,0,preso);
}