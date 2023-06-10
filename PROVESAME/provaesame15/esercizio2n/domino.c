#include <stdbool.h>
#include "domino.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void DominoRec(const Tessera* t, size_t t_size, size_t* ret_size,Placing *vcurr,Placing *vbest,int i,bool *presi,int ris,bool fatto,int *max) {
	if (fatto) {
		if (ris > (int)(*ret_size)) {
			memcpy(vbest, vcurr, t_size * sizeof(Placing));
			*ret_size = ris;
		}
		return;
	}
	for (int j = 0; j < (int)t_size; j++) {
		if (!presi[j]) {
			if (i == 0) {
				vcurr[i].indice = j;
				vcurr[i].flipped = false;
				presi[j] = true;
				DominoRec(t, t_size, ret_size,vcurr,vbest,i + 1,presi,ris +1,false,max);
				vcurr[i].indice = j;
				vcurr[i].flipped = true;
				presi[j] = true;
				DominoRec(t, t_size, ret_size, vcurr, vbest, i + 1, presi, ris + 1, false, max);
				presi[j] = false;
				vcurr[i].indice = 0;
			}
			if (vcurr[i - 1].flipped == true) {
				if (t[vcurr[i - 1].indice].val1 == t[j].val1) {
					vcurr[i].indice = j;
					vcurr[i].flipped = false;
					presi[j] = true;
					DominoRec(t, t_size, ret_size, vcurr, vbest, i + 1, presi, ris + 1, false, max);
					vcurr[i].indice = 0;
					presi[j] = false;
				}
				if (t[vcurr[i - 1].indice].val1 == t[j].val2) {
					vcurr[i].indice = j;
					vcurr[i].flipped = true;
					presi[j] = true;
					DominoRec(t, t_size, ret_size, vcurr, vbest, i + 1, presi, ris + 1, false, max);
					vcurr[i].indice = 0;
					vcurr[i].flipped = false;
					presi[j] = false;
				}
			}
			if (vcurr[i - 1].flipped == false) {
				if (t[vcurr[i - 1].indice].val2 == t[j].val1) {
					vcurr[i].indice = j;
					vcurr[i].flipped = false;
					presi[j] = true;
					DominoRec(t, t_size, ret_size, vcurr, vbest, i + 1, presi, ris + 1, false, max);
					vcurr[i].indice = 0;
					presi[j] = false;
				}
				if (t[vcurr[i - 1].indice].val2 == t[j].val2) {
					vcurr[i].indice = j;
					vcurr[i].flipped = true;
					presi[j] = true;
					DominoRec(t, t_size, ret_size, vcurr, vbest, i + 1, presi, ris + 1, false, max);
					vcurr[i].indice = 0;
					vcurr[i].flipped = false;
					presi[j] = false;
				}
			}
		}
	}
	DominoRec(t, t_size, ret_size, vcurr, vbest, i + 1, presi, ris,true, max);
}
Placing* Domino(const Tessera* t, size_t t_size, size_t* ret_size) {
	*ret_size = 0;
	if (t == NULL || t_size <= 0) return NULL;
	Placing* vcurr = calloc(t_size, sizeof(Placing));
	Placing* vbest = calloc(t_size, sizeof(Placing));
	bool* presi = calloc(t_size, sizeof(bool));
	int max = 0;
	DominoRec(t, t_size, ret_size, vcurr, vbest, 0, presi, 0, false, &max);
	vbest = realloc(vbest,ret_size[0] * sizeof(Placing));
	free(vcurr);
	free(presi);
	return vbest;
}
