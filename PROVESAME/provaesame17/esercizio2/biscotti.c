#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
void rec(const int* bam, size_t bam_size, const int* bis, size_t bis_size,size_t i,int *vcurr,int *best,bool *sodd) {
	if (i == bis_size) {
		for (size_t j = 0; j < bam_size; j++) {
			int sum = 0;
			for (size_t m = 0; m < bis_size; m++) {
				if (vcurr[m] == (int)j) {
					sum += bis[m];
				}
				if (sum >= bam[j]) {
					sodd[j] = true;
				}
			}
		}
		//contiamo quanti true ci sono e vediamo se è il migliore e azzeriamo tutto
		int sum = 0;
		for (size_t j = 0; j < bam_size; j++) {
			if (sodd[j]) {
				sum++;
			}
			sodd[j]= false;
		}
		//controlliamo se è il vbest
		if (sum > best[0]) {
			best[0] = sum;
		}
		return;
	}
	for (size_t j = 0; j < bam_size; j++) {
		vcurr[i] = (int)j;
		rec(bam, bam_size, bis, bis_size, i + 1, vcurr,best,sodd);
	}
}
int AssegnaBiscotti(const int* bam, size_t bam_size, const int* bis, size_t bis_size) {
	int* vcurr = calloc(bis_size, sizeof(int));
	int best = 0;
	bool* sodd = calloc(bam_size, sizeof(bool));
	rec(bam, bam_size, bis, bis_size, 0, vcurr,&best,sodd);
	free(sodd);
	free(vcurr);
	return best;
}
