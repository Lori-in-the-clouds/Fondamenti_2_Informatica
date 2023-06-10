#include <stdlib.h>
#include "alpine_road.h"
#include <stdio.h>
#include <math.h>
void rec(const Point* p, size_t p_size, int dh, int* vcurr, int i, int* ris, Point* vbest) {
	int control = 0;
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	for (int j = 0; j < i; j++) {
		if (vcurr[j] == 1) {
			control++;
			if (control == 1) {
				a = p[j].h;
				c = p[j].s;
			}
			if (control == 2) {
				b = p[j].h;
				d = p[j].s;
			}
		}
	}
	if (control > 2) return;
	if (control == 2) {
		//vediamo se la distaza è giusta 
		int sum = abs(a - b);
		for (int j = 0; j < i; j++) {
			if (vcurr[j] == 1) {
				for (int m = j + 1; m < i; m++) {
					if (abs(p[j].h - p[m].h) > dh) return;
				}
			}
		}
			//vediamo se è il pi lungo
			sum = d - c;
			if (sum > *ris) {
				*ris = sum;
				vbest[0].h = a;
				vbest[1].h = b;
				vbest[0].s = c;
				vbest[1].s = d;
			}
		
		return;
	}

	if (i == p_size) return;
	vcurr[i] = 1;
	rec(p, p_size, dh, vcurr, i + 1, ris, vbest);
	vcurr[i] = 0;
	rec(p, p_size, dh, vcurr, i + 1, ris, vbest);
}
int FindPath(const Point* p, size_t p_size, int dh) {
	int* vcurr = calloc(p_size, sizeof(int));
	
	Point* vbest = calloc(2, sizeof(Point));
	int ris = 0;
	rec(p, p_size, dh, vcurr,0, &ris,vbest);
	return ris;
}