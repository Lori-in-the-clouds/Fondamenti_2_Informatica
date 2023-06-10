#include <stdlib.h>
#include <stdbool.h>
int TempoTrasporto(int n, const int* t, int p) {
	int size = 1;
	int* vcurr = calloc(size+1, sizeof(int));
	int* prec = calloc(size + 1, sizeof(int));

	vcurr[0] = p;
	prec[0] = p;

	while (1) {
		for (int j = 0; j < size; j++) {
			
			if (prec[j] > 0) {
				if (prec[j] > t[j]) {
					vcurr[j + 1] += t[j];
					vcurr[j] -= t[j];
				}
				else if (prec[j] == t[j]) {
					vcurr[j] = 0;
					vcurr[j + 1] += t[j];
				}
				else if (prec[j] < t[j]) {
					vcurr[j + 1] += prec[j];
					vcurr[j] = 0;
				}
			}
		}
		//ricopiamolo
		for (int j = 0; j <= size; j++) {
			prec[j] = vcurr[j];
		}
		
		size++;
		prec = realloc(prec, (size + 1) * sizeof(int));
		vcurr = realloc(vcurr, (size+1) * sizeof(int));
		vcurr[size] = 0;
		prec[size] = 0;
	}
}