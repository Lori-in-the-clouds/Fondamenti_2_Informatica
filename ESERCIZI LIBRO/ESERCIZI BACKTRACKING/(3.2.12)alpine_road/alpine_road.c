#include "alpine_road.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
void FindPathRec(const Point* p, size_t p_size, int dh,int i,int *vcurr,int* distmax,int *vbest) {
	if (i == 2) {
		//controllo dh
		for (int j = vcurr[0]; j < vcurr[1] + 1; j++) {
			if (fabs(p[j].h - p[vcurr[0]].h) > dh) return;
		}
		if (vcurr[0] == 0 && vcurr[1] == 0) return;
		int som = 0;
		//è il vbest???
		som = p[vcurr[1]].s-p[vcurr[0]].s;
		if (som > (*distmax)) {
			*distmax = som;
			vbest[0] = vcurr[0];	
			vbest[1] = vcurr[1];
		}
		return;
	}
	if (i == 0) {
		for (int j = 0; j < p_size - 1; j++) {
			vcurr[i] = j;
			FindPathRec(p, p_size, dh, i + 1, vcurr, distmax,vbest);
		}
	}
	if (i == 1) {
		for (int j = vcurr[0]; j < p_size; j++) {
			vcurr[i] = j;
			FindPathRec(p, p_size, dh, i + 1, vcurr, distmax,vbest);
		}
	}
}
int FindPath(const Point* p, size_t p_size, int dh) {
	int* vcurr = calloc(2, sizeof(int));
	int* vbest = calloc(2, sizeof(int));
	int distmax = 0;
	FindPathRec(p, p_size,dh, 0, vcurr, &distmax,vbest);
	//stampiamo
	char lettera = 'A';
	for (int j = vbest[0]; j < vbest[1] + 1; j++) {
		printf("%c: (%d, %d)\n", ++lettera,p[j].s,p[j].h);
	}
	int ris = (int)fabs(p[vbest[1]].s - p[vbest[0]].s);
	free(vcurr);
	free(vbest);
	return ris;
}