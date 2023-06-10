#define _CRT_SECURE_NO_WARNINGS
#include "elemtype.h"
#include <stdio.h>
#include <stdlib.h>
void ordino(int* v,int first, int last) {
	int i,j,pivot;
	if (first < last) {
		i = first;
		j = last;
		pivot = v[(first + last) / 2];
		do {
			while (v[i] < pivot) {
				i++;
			}
			while (v[j] > pivot) {
				j--;
			}
			if (i <= j) {
				ElemSwap(&v[i], &v[j]);
				i++;
				j--;
			}
		} while (i <= j); 
			
		ordino(v,first, j);
		ordino(v,i, last);
	}
}
int main(int argc, char *argv[]) {
	if (argc != 3) {
		fprintf(stderr, "Errore");
		return 1;
	}
	FILE* f = fopen(argv[1], "r");
	if (f == NULL) {
		return 1;
	}
	FILE* s = fopen(argv[2], "w");
	if (s == NULL) {
		return 1;
	}
	int n = 1;
	size_t turn1 = 1;
	int* ris = malloc(sizeof(int));
	for (int i = 0; turn1 != EOF; i++) {
		turn1 = fscanf(f, "%d", &ris[i]);
		n++;
		ris = realloc(ris,n*sizeof(int));
		
	}
	ordino(ris,0,n-3);
	return 0;
}