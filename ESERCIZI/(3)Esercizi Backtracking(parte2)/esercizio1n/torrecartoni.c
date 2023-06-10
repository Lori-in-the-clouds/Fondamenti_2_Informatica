#include "torrecartoni.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
void TorreCartoniRec(const Cartone* c, size_t n,int i,Cartone *vcurr,int *h_max,Cartone *vbest,bool *presi,int peso,int altezza,bool finito) {
	if (finito) {
		if (altezza > *h_max) {
			*h_max = altezza;
			memcpy(vbest, vcurr, n * sizeof(Cartone));
		}
		return;
	}
	
	for (int j = 0; j < (int)n; j++) {
		if (!presi[j]) {
			if (c[j].l >= (unsigned)peso) {
				memcpy(&vcurr[i], &c[j], sizeof(Cartone));
				presi[j] = true;
				TorreCartoniRec(c, n, i + 1, vcurr, h_max, vbest, presi, (unsigned)peso + vcurr[i].p, (unsigned)altezza + vcurr[i].a,false);
				vcurr[i].a = 0;
				vcurr[i].l = 0;
				vcurr[i].p = 0;
				presi[j] = false;
			}
		}
	}
	TorreCartoniRec(c, n, i, vcurr, h_max, vbest, presi, peso, altezza, true);

}

void TorreCartoni(const Cartone* c, size_t n) {
	if (n < 0 || c == NULL) return;
	Cartone* vcurr = calloc(n, sizeof(Cartone));
	Cartone* vbest = calloc(n, sizeof(Cartone));
	bool* presi = calloc(n, sizeof(bool));
	int h_max = 0;
	TorreCartoniRec(c, n, 0, vcurr, &h_max, vbest,presi,0,0,false);
	for (int i = 0; i < (int)n; i++) {
		if ((vbest[i].a == 0 || vbest[i].a == -1) && (vbest[i].l == 0 || vbest[i].l == -1) && (vbest[i].p == 0 || vbest[i].p == -1)) continue;
		for (int j = 0; j < (int)n; j++) {
			if (memcmp(&vbest[i], &c[j], sizeof(Cartone)) == 0) {
				printf("%d\n", j);
			}
		}
	}
	printf("Altezza: %dcm", h_max);
	free(vcurr);
	free(vbest);
	free(presi);
	return;
}