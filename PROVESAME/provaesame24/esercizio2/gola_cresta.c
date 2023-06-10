#include <stdlib.h>
#include <stdio.h>

void rec(size_t n, int* vcurr, int i) {
	if (i == n) {
		printf("(");
		for (int j = 0; j < n-1; j++) {
			printf("%d,", vcurr[j]);
		}
		printf("%d),", vcurr[n-1]);
		return;
	}
	for (int j = 0; j < 3; j++) {
		vcurr[i] = j;
		if (i == 0) {
			rec(n, vcurr, i + 1);
		}
		if (i == 1) {
			if (vcurr[0]<vcurr[1] || vcurr[0]>vcurr[1]) rec(n,vcurr,i+1);
		}
		if (i>1) {
		if (vcurr[i - 2]<vcurr[i - 1] && vcurr[i - 1]>vcurr[i]) rec(n, vcurr, i + 1);
		if (vcurr[i - 2]>vcurr[i - 1] && vcurr[i - 1]<vcurr[i]) rec(n, vcurr, i + 1);
		}
	}
}
void GolaCresta(size_t n) {
	int* vcurr = calloc(n, sizeof(int));
	rec(n, vcurr, 0);
	free(vcurr);
}
