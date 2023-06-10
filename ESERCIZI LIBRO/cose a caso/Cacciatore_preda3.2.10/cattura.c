#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
void* CacciatorePredaRec(const char* v, size_t v_size, int u,int* vcurr, int i,bool *control,int *vbest,int* max,int*quanti,int *vcurr2) {
	int j = i;
	
	while (v[j] != 'C') {
		j++;
		if (j == v_size) {
			//completo ciò che è rimasto vuoto e rimetto a posto il control
			for (size_t m = 0; m < v_size; m++) {
				if (vcurr[m] == 0) {
					vcurr[m] = -1;
				}
				control[j] = false;
			}
			//stampiamo il vcurr
			for (int j = 0; j < v_size; j++) {
				printf("%d ", vcurr[j]);
			}
			printf("\n");
			//metto il max
			if (quanti[0] > max[0]) {
				max[0] = quanti[0];
				quanti[0] = 0;
				for (int j = 0; j < v_size; j++) {
					vbest[j] = vcurr[j];
				}
			}
			return;
		}
	}
	
	i = j;
	if (vcurr2[i] == -1) {
		for (int m = j - u; m <= j; m++) {
			if (v[m] == 'P' && control[m] == false) {
				vcurr[m] = -2;
				vcurr[j] = m;
				control[m] = true;
				quanti[0]++;
				break;
			}
		}
	}
	if (vcurr2[i] == 1) {
		for (int m = j; m <= j + u ; m++) {
			if (v[m] == 'P' && control[m] == false) {
				vcurr[m] = -2;
				vcurr[j] = m;
				control[m] = true;
				quanti[0]++;
				break;
			}
		}
	}
	vcurr2[i] = 0;
	CacciatorePredaRec(v, v_size, u, vcurr, i + 1, control, vbest, max,quanti,vcurr2);
	vcurr2[i] = 1;
	CacciatorePredaRec(v, v_size, u, vcurr, i + 1, control, vbest, max, quanti, vcurr2);
	vcurr2[i] = -1;
	CacciatorePredaRec(v, v_size, u, vcurr, i + 1, control, vbest, max, quanti, vcurr2);

}
int* CacciatorePreda(const char* v, size_t v_size, int u) {
	if (v == NULL || v_size <= 0) {
		return NULL;
	}
	int vcurr2 = calloc(v_size, sizeof(int));
	int* vcurr = calloc(v_size, sizeof(int));
	bool* control = calloc(v_size+1, sizeof(bool));
	int* vbest = calloc(v_size, sizeof(int));
	int max = 0;
	int quanti = 0;
	CacciatorePredaRec(v, v_size, u, vcurr, 0, control,vbest,&max,&quanti,vcurr2);
	return vbest;
}