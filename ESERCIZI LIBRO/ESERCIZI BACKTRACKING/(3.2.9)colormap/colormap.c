#include "colormap.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
bool Verifica(const struct SquareMatrix* m, int i, char* vcurr, char colore) {
	int riga = i;
	int dim = sqrt(m->side);
	for (int j = 0; j < i; j++) {
		if (m->data[dim * riga + j] == 1 && vcurr[j] == colore) return false;
	}
	return true;
}
void ColorMapRec(const struct SquareMatrix* m, const char* c, int i, char* vcurr,int *nsol,int rows) {
	//PRIMA VERSIONE CON PRUNING
	/*if (i != 1) {
		for (int k = 0; k < i; k++) {
			for (int j = 0; j < strlen(c); j++) {
				if (vcurr[k] == c[j]) {
					for (int s = k + 1; s < i; s++) {
						if (vcurr[k] == vcurr[s]) {
							if (m->data[(rows * k) + s] == 1) {
								return;
							}
						}
					}
				}
			}
		}
	}*/
	if (i == sqrt(m->side)) {
		//stampiamo 
		for (int j = 0; j < i; j++) {
			printf("%d -> %c; ", j, vcurr[j]);
		}
		printf("\n");
		(*nsol)++;
		return;
	}
	for (int j = 0; j < strlen(c); j++) {
		if (Verifica(m, i, vcurr, c[j])) {
			vcurr[i] = c[j];
			ColorMapRec(m, c, i + 1, vcurr, nsol, rows);
		}
	}
}
int ColorMap(const struct SquareMatrix* m, const char* c) {
	char* vcurr = malloc((size_t)sqrt(m->side) * sizeof(char));
	int nsol = 0;
	ColorMapRec(m, c, 0, vcurr,&nsol,sqrt(m->side));
	free(vcurr);
	return nsol;

}