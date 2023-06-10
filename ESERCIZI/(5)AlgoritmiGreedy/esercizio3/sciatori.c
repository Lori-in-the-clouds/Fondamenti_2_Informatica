#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>
#include "sciatori.h"
int comp(const void* a,const void* b) {
	const double* g1 = (const double*)a;
	const double* g2 = (const double*)b;
	if (*g1 > *g2) return 1;
	if (*g1 == *g2) return 0;
	else return -1;
}
Sciatore* Accoppia(double* altezze, double* lunghezze, size_t v_size) {
	if (v_size <= 0) {
		return NULL;
	}
	qsort(altezze, v_size, sizeof(double), comp);
	qsort(lunghezze, v_size, sizeof(double), comp);
	Sciatore* ris = malloc(v_size * sizeof(Sciatore));
	bool *control = calloc(v_size,sizeof(bool));
	int max = INT_MAX;
	int n = 0;
	double a = 0;
	double l = 0;
	int c = 0;
	for (size_t i = 0; i < v_size+1; i++) {
		if (i != 0) {
			ris[n].a = a;
			ris[n].l = l;
			n++;
			max = INT_MAX;
			if (i == v_size + 1) {
				break;
			}
		}
		for (size_t j = 0; j < v_size; j++) {
			if ((fabs(altezze[i] - lunghezze[j]) < max) && control[j] == false) {
				max = fabs(altezze[i] - lunghezze[j]);
				a = altezze[i];
				l = lunghezze[j];
				c = j;
			}
					if (j == v_size - 1) {
						control[c] = true;
					}
		}
	}
	free(control);
	return ris;
}

