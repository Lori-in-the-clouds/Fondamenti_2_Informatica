#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>
void rec(uint8_t n, int* vcurr, int i,int cont) {
	if (cont > n) return;
	if (i == 11) {
		if (cont == n) {
			int ris1 = 0;
			int ris2 = 0;
			int s = 0;
			for (int j = 4; j >= 0; j--) {
				if (vcurr[j] == 1) {
					ris1 += (int)pow(2,s);
				}
				s++;
			}
			if (ris1 > 23) return;
			s = 0;
			for (int j = 10; j >= 5; j--) {
				if (vcurr[j] == 1) {
					ris2 += (int)pow(2, s);
				}
				s++;
			}
			if (ris2 > 59) return;
			printf("%02d:%02d, ",ris1,ris2);
		}
		return;
	}
	for (int j = 0; j <= 1; j++) {
		vcurr[i] = j;
		if (j == 1) {
			rec(n, vcurr, i + 1, cont + 1);
		}
		else {
			rec(n, vcurr, i + 1, cont);
		}
	}
}
void ValidTimes(uint8_t n) {
	if (n == 0) {
		printf("00:00,");
		return;
	}
	int* vcurr = calloc(11, sizeof(int));
	rec(n, vcurr, 0,0);
	free(vcurr);

}