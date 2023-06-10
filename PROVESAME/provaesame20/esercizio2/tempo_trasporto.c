#include <stdlib.h>
int mn(int a, int b) {
	if (a < b) return a;
	if (a > b) return b;
	else return a;
}
int TempoTrasporto(int n, const int* t, int p) {
	int* vcurr = calloc(n+1, sizeof(int));
	int* prec = calloc(n+1, sizeof(int));
	prec[0] = p;
	int j = 1;
	while (1) {
		for (int i = 0; i < mn(n-1,j); i++) {
			if (prec[i] == 0) continue;
			if (prec[i] > t[i]) {
				vcurr[i + 1] += t[i];
				vcurr[i] = vcurr[i] + prec[i] - t[i];
			}
			else {
				vcurr[i + 1] += prec[i];
			}
			if (i == n - 2) {
				int cont = 0;
				for (int m = 0; m < n + 1; m++) {
					cont += vcurr[m];
				}
				if (cont < p) {
					vcurr[n-1] = vcurr[n-1] + (p - cont);
				}
			}
		}
		for (int k = 0; k < n+1 ; k++) {
			prec[k] = vcurr[k];
			vcurr[k] = 0;
		}
		if (prec[n - 1] == p) {
			free(vcurr);
			free(prec);
			return j;
		}
		j++;
	}
}
	

