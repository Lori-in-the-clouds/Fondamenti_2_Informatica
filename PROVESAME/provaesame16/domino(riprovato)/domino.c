#include "domino.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
void rec(const Tessera* t, size_t t_size, size_t* ret_size, Placing* vcurr, Placing* vbest, int i, bool* preso, int lengh, bool bloccato) {
	if (bloccato == true) {
		if (lengh > (int)*ret_size) {
			*ret_size = lengh;
			memcpy(vbest, vcurr, t_size * sizeof(Placing));
		}
		return;
	}
	for (size_t j = 0; j < t_size; j++) {
		if (!preso[j]) {
		//PRIMA TESSERA
		if (i == 0) {
			//FLIPPIAMO IL PRIMO
			vcurr[i].indice = j;
			vcurr[i].flipped = true;
			preso[j] = true;
			rec(t, t_size, ret_size, vcurr, vbest, i + 1, preso, lengh + 1, false);
			//NON FLIPPIAMO IL PRIMO
			vcurr[i].indice = j;
			vcurr[i].flipped = false;
			preso[j] = true;
			rec(t, t_size, ret_size, vcurr, vbest, i + 1, preso, lengh + 1, false);
			preso[j] = false;
			vcurr[i].indice = 0;
		}

		else {
			//SE QUELLO PRIMA NON è FLIPPATO
			if (vcurr[i - 1].flipped == false) {
				//NON FLIPPIAMO QUELLO DOPO
				if (t[vcurr[i - 1].indice].val2 == t[j].val1) {
					vcurr[i].indice = j;
					vcurr[i].flipped = false;
					preso[j] = true;
					rec(t, t_size, ret_size, vcurr, vbest, i + 1, preso, lengh + 1, false);
					vcurr[i].indice = 0;
					preso[j] = false;
				}
				//FLIPPIAMO QUELLO DOPO
				if (t[vcurr[i - 1].indice].val2 == t[j].val2) {
					vcurr[i].indice = j;
					vcurr[i].flipped = true;
					preso[j] = true;
					rec(t, t_size, ret_size, vcurr, vbest, i + 1, preso, lengh + 1, false);
					vcurr[i].indice = 0;
					vcurr[i].flipped = false;
					preso[j] = false;
				}
			}

			//SE QUELLO PRIMA è FLIPPATO
			if (vcurr[i - 1].flipped == true) {
				//NON FLIPPIAMO QUELLO DOPO
				if (t[vcurr[i - 1].indice].val1 == t[j].val1) {
					vcurr[i].indice = j;
					vcurr[i].flipped = false;
					preso[j] = true;
					rec(t, t_size, ret_size, vcurr, vbest, i + 1, preso, lengh + 1, false);
					vcurr[i].indice = 0;
					preso[j] = false;
				}
				//FLIPPIAMO QUELLO DOPO
				if (t[vcurr[i - 1].indice].val1 == t[j].val2) {
					vcurr[i].indice = j;
					vcurr[i].flipped = true;
					preso[j] = true;
					rec(t, t_size, ret_size, vcurr, vbest, i + 1, preso, lengh + 1, false);
					vcurr[i].indice = 0;
					vcurr[i].flipped = false;
					preso[j] = false;
				}
			}
		}
	}
}
	//non poss fare niente 
	rec(t, t_size, ret_size, vcurr, vbest, i + 1, preso, lengh, true);
}
Placing* Domino(const Tessera* t, size_t t_size, size_t* ret_size) {
	if (t == NULL || t_size <= 0) return NULL;
	*ret_size = 0;
	Placing* tmp = calloc(t_size, sizeof(Placing));
	Placing* vbest = calloc(t_size, sizeof(Placing));
	bool* preso = calloc(t_size, sizeof(bool));
	rec(t, t_size, ret_size, tmp, vbest, 0, preso,0,false);
	vbest = realloc(vbest, ret_size[0] * sizeof(Placing));
	free(preso);
	free(tmp);
	return vbest;
}