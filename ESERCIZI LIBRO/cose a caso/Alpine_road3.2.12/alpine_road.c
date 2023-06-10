#include "alpine_road.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
void FindPathRec(const Point* p, size_t p_size, int dh,int i,int *vcurr,int *vbest,int *distmax) {
	if (i == 2) {
		if ((fabs(p[vcurr[0]].h - p[vcurr[1]].h)) > dh) {
			return;
		}
		int dist = 0;
		for (int j = vcurr[0]; j < vcurr[1]; j++) {
			dist += p[j].s;
		}
		if (dist > distmax[0]) {
			for (int j = 0; j < p_size; j++) {
				vbest[j] = vcurr[j];
			}
			distmax[0] = dist;
		}
			return;
	}
	if (i == 0) {
		for (int j = 0; j < (int)p_size-1; j++) {
			vcurr[0] = j;
			FindPathRec(p, p_size, dh, i + 1, vcurr,vbest,distmax);
		}
	} else{
		for (int j = vcurr[0]; j < p_size; j++) {
			vcurr[1] = j;
			FindPathRec(p, p_size, dh, i + 1, vcurr,vbest,distmax);
		}
	}


	

	
	
}
	int FindPath(const Point * p, size_t p_size, int dh) {
		if (p_size < 0) {
			return -1;
		}
		int distmax = 0;
		int* vcurr = calloc(2,sizeof(int));
		int* vbest = malloc(p_size * sizeof(int));
		FindPathRec(p, 5, dh, 0, &vcurr,&vbest,&distmax);
		
	}