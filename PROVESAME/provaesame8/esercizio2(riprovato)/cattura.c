#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
size_t mx(int a, int b) {
	if (a >= b) return a;
	else return b;
}
size_t mn(int a, int b) {
	if (a <= b) return a;
	else return b;
}
void rec(const char* v, size_t v_size, int u, int* vcurr, int* vbest, int i,bool *preso,bool control,int *numca) {
	if (control) {
		int cont = 0;
		for (size_t j = 0; j < v_size; j++) {
			if ((v[j] == 'P' || v[j] == 'p') && vcurr[j] == -2) {
				cont++;
			}
		}
		if (cont > numca[0]) {
			numca[0] = cont;
			memcpy(vbest, vcurr, v_size*sizeof(int));
		}
		return;
	}

	for (size_t s = i; s < v_size; s++) {
		if (v[s] == 'C' || v[s] == 'c') {
			for (size_t j = mx((int)s - u, 0); j <= mn((int)s + u, v_size); j++) {
				if ((v[j] == 'P' || v[j] == 'p') && !preso[j]) {
					vcurr[s] = j;
					vcurr[j] = -2;
					preso[j] = true;
					rec(v, v_size, u, vcurr, vbest, s + 1, preso,false,numca);
					vcurr[s] = -1;
					vcurr[j] = -1;
					preso[j] = false;
				}
			}
		}
	}
	//non posso fare piu niente
	rec(v, v_size, u, vcurr, vbest, i + 1, preso,true,numca);
}
int* CacciatorePreda(const char* v, size_t v_size, int u) {
	
	int* vcurr = calloc(v_size, sizeof(int));
	int* vbest = calloc(v_size, sizeof(int));
	bool* preso = calloc(v_size, sizeof(int));
	for (size_t j = 0; j < v_size; j++)  vcurr[j] = -1;
	int numca = 0;
	rec(v, v_size, u, vcurr, vbest, 0,preso,false,&numca);
	free(vcurr);
	free(preso);
	return vbest;
}