#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
void CacciatorePredaRec(const char* v,size_t v_size,int u,int i,int *vcurr,int *vbest,bool *control) {
	int j = 0;
	for (j = i; j < v_size; j++) {
		if (v[j] == 'C') {
			break;
		}
	}
	if (j == v_size) {
		if (!(*control)) {
			printf("|");
			for (int j = 0; j < v_size; j++) {
				printf(" %d-%c |", j, v[j]);
			}
			printf("\n");
			*control = true;
		}
		printf("|");
		for (int j = 0; j < v_size; j++) {
			if (vcurr[j] > 0) printf("  %d  |", vcurr[j]);
			else printf(" %d  |", vcurr[j]);
		}
		printf("\n");
		return;
	}
	//individuiamo la preda
	for (int k = max(j - u,0); k <= min(j + u, v_size - 1); k++) {
		if (v[k] == 'P') {
			vcurr[k] = -2;
			vcurr[j] = k;
			CacciatorePredaRec(v, v_size, u, j + 1, vcurr, vbest,control);
			vcurr[k] = -1;
			vcurr[j] = -1;
		}
	}
			CacciatorePredaRec(v, v_size, u, i + 1, vcurr, vbest,control);
}
int* CacciatorePreda(const char* v, size_t v_size, int u) {
	int* vcurr = malloc(v_size, sizeof(int));
	int *vbest = malloc(v_size, sizeof(int));
	bool control = false;
	for (int j = 0; j < v_size; j++) {
		vbest[j] = -1;
		vcurr[j] = -1;
	}
	CacciatorePredaRec(v,v_size,u,0,vcurr,vbest,&control);
}