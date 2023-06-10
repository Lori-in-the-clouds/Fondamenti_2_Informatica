#include <stdlib.h>
#include <stdio.h>
void rec(int n, int s, int i,int *vcurr) {
	//primo filtro: sono in ordine crescente??
	for (int j = 0; j < i-1; j++) {
		if (vcurr[j] > vcurr[j + 1]) {
			return;
		}
	}
	if (i == n) {
		
		//secondo filtro: ci sono doppioni
		for (int j = 0; j < n; j++) {
			for (int m = 0; m < n; m++) {
				if (j == m) {
					continue;
				}
				if (vcurr[j] == vcurr[m] && vcurr[j]!=0) return;
			}
		}
		////controlliamo che la somma faccia s
		int sum = 0;
		for (int j = 0; j < n; j++) {
			sum += vcurr[j];
		}

		if (sum == s) {
			//stampiamo
			for (int j = 0; j < n; j++) {
				if (vcurr[j] == 0) continue;
				printf("%d", vcurr[j]);
			}
			printf("\n");
		}
		return;
	}
	
	for (int j = 0; j <= n; j++) {
		vcurr[i] = j;
		rec(n, s, i + 1, vcurr);
	}
}

void SubsetEqual(int n, int s) {
	int* vcurr = calloc(n, sizeof(int));
	rec(n, s, 0,vcurr);
}