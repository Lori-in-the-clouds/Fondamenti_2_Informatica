#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
void rec(int n, int* vcurr, int i) {
	
	if (i == n) {
		bool coppia = false;
		for (int j = 0; j < n-1; j++) {
			if (vcurr[j] == vcurr[j + 1]) coppia = true;
		}
		if (coppia) {
			for (int j = 0; j < n; j++) {
				printf("%d", vcurr[j]);
			}
			printf("\n");
		}
		return;
	}

	for (int j = 0; j <= 9; j++) {
		if (j >= vcurr[i - 1] || i==0) {
			vcurr[i] = j;
			rec(n, vcurr, i + 1);
		}
		/*if (i == 0) {
			vcurr[i] = j;
			rec(n, vcurr, i + 1);
		}*/
	}

}
void Passwords(int n) {
	if (n < 0) return;
	int* vcurr = calloc(n, sizeof(int));
	rec(n, vcurr, 0);
	free(vcurr);
	return;
}