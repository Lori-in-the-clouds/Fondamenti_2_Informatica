#include "colora.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>S
bool Verifica(const struct Matrix* m, char* vcurr) {
	for (int r = 0; r < m->size; r++) {
		for (int c = 0; c < m->size; c++) {
			if (m->data[r * m->size + c]) {
				if (vcurr[r] == vcurr[c] && r!=c) return false;
			}
		}
	}
	return true;
}
void rec(const struct Matrix* m, const char* c, size_t c_size,char *vcurr,int i,int *ris) {
	if (i == m->size) {
		if (Verifica(m,vcurr)) {
			for (int j = 0; j < m->size; j++) {
				printf("%d -> %c;",j, vcurr[j]);
			}
			printf("\n");
			ris[0]++;
		}
		return;
	}
	for (int j = 0; j < c_size; j++) {
		vcurr[i] = c[j];
		rec(m, c, c_size, vcurr, i + 1, ris);
	}
}
int MappaColori(const struct Matrix* m, const char* c, size_t c_size) {
	if (c_size < 0) return 0;
	char* vcurr = calloc(m->size, sizeof(char));
	int ris = 0;
	rec(m, c, c_size, vcurr, 0, &ris);
	free(vcurr);
	return ris;
}