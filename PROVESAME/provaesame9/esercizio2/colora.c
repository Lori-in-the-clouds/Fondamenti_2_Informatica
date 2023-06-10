#include <stdbool.h>
#include <stdlib.h>
#include "colora.h"
#include <math.h>
#include <stdio.h>
void MappaColoriRec(const struct Matrix* m, const char* c, size_t c_size,char *vcurr,int i,int *nsol) {
	for (int j = 0; j < i; j++) {
		for (int k = 0; k < i; k++) {
			if (k == j) continue;
			if (vcurr[k] == vcurr[j]) {
				if (m->data[k * m->size + j] == true) {
					return;
				}
			}
		}
	}
	if (i == (int)m->size) {
		(*nsol)++;
		for (int j = 0; j < i; j++) {
			printf("%d -> %c; ",j, vcurr[j]);
		}
		printf("\n");
		return;
	}
	for (int j = 0; j < c_size; j++) {
		vcurr[i] = c[j];
		MappaColoriRec(m, c, c_size, vcurr, i + 1, nsol);
	}
}
int MappaColori(const struct Matrix* m, const char* c, size_t c_size) {
	if (c < 0 || c == NULL) return 0;
	char* vcurr = malloc(m->size);
	int nsol = 0;
	MappaColoriRec(m, c, c_size, vcurr, 0, &nsol);
	free(vcurr);
	return nsol;
}


