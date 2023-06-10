#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include "gioielli.h"
#include <stdio.h>
int comp(const void* a, const void* b) {
	const Gioiello* g1 = (const Gioiello*)a; //faccio un cast: faccio diventare a un const gioiello.
	const Gioiello* g2 = (const Gioiello*)b;
	if ((g1->peso/g1->prezzo) > (g2->peso/g2->prezzo)) return -1;		//li ordino in senso decrescente 
	if ((g1->peso / g1->prezzo) == (g2->peso / g2->prezzo)) return 0;
	else return 1;
}
Gioiello* CompraGioielli(const char* filename, float budget, size_t* ret_size) {
	if (budget <= 0) {
		return NULL;
	}
	Gioiello* ris = malloc(sizeof(Gioiello));
	//leggiamo 
	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		free(ris);
		return NULL;
	}
	int i = 0;
	while (1) {
		int turn1 = fscanf(f, "%i %f %f", &ris[i].codice,&ris[i].peso ,&ris[i].prezzo);
		if (turn1 == EOF) {
			break;
		}
		i++;
		ris = realloc(ris, (i + 1) * sizeof(Gioiello));
	}
	fclose(f);
	qsort(ris, i, sizeof(Gioiello),comp);
	Gioiello* ris2 = malloc(sizeof(Gioiello));
	int n = 1;
	int m = 0;
	for (int j = 0; j < i && budget>0;j++) {
		int s = budget / ris[j].prezzo;
		if (s > 0) {
			ris2[m] = ris[j];
			m++;
			n++;
			ris2 = realloc(ris2,n*sizeof(Gioiello));
			(*ret_size)++;
			budget -= ris[j].prezzo;
		}
		
	}
	free(ris);
	return ris2;
}