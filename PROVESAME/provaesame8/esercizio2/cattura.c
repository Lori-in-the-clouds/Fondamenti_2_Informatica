#include <stdlib.h>
#include <string.h>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

void CacciatorePredaRec(const char* v, size_t v_size, int u,int *vcurr,int *vbest,int i) {
	int j = 0;
	for (j = i; j < v_size; j++) {
		if (v[j] == 'C' || v[j] == 'c') {
			break;
		}
	}
	if (j == (int)v_size) {
		int cont1 = 0;
		int cont2 = 0;
		for (int j = 0; j <(int)strlen(v); j++) {
			if (vcurr[j] == -2) cont1++;
			if (vbest[j] == -2) cont2++;
		}
		if (cont1 > cont2) {
			for (int j = 0; j < (int)strlen(v); j++) {
				vbest[j] = vcurr[j];
			}
		}
		return;
	}
	for (int k = MAX(0,j-u); k <= MIN((int)v_size - 1,j+ u); k++) {
		if ((v[k] == 'P' || v[k] == 'p') && vcurr[k] != -2) {
			vcurr[j] = k;
			vcurr[k] = -2;
			CacciatorePredaRec(v,v_size,u,vcurr,vbest,j + 1);
			vcurr[j] = -1;
			vcurr[k] = -1;
		}
	}
	CacciatorePredaRec(v, v_size, u, vcurr, vbest, j + 1);
}

int* CacciatorePreda(const char* v, size_t v_size, int u) {
	if (v_size <= 0 || u <= 0) return 0;
	int* vcurr = malloc((int)v_size * sizeof(int));
	memset(vcurr, -1, sizeof(int) * v_size);
	int* vbest = calloc(strlen(v), sizeof(int));
	CacciatorePredaRec(v, v_size, u, vcurr, vbest, 0);
	free(vcurr);
	return vbest;
}