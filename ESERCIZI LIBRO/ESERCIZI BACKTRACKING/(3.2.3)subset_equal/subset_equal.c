#include <stdlib.h>
#include <stdio.h> 
#include <stdbool.h>
void SubSetEqualRec(int n, int s, int* vcurr, int i, int* nsol,int som) {
	if (som == s) {
		for (int j = 0; j < i; j++) {
			if (vcurr[j]) {
				printf("%d", j);
			}
		}
		printf("\n");
		return;
	}
	if (i > n) {
		return;
	}
	
		//Importante 
	for (int e = i; e <= n; e++) {  // questo mi cambia solo l'elemento iniziale escludendomi quello che viene prima 
		if (som + e <= s) {
			vcurr[e] = true;
			SubSetEqualRec(n, s, vcurr, e + 1, nsol, som+e);
			vcurr[e] = false;
		}

	}
}
int SubsetEqual(int n, int s) {
	if (n <= 0 || s <= 0) {
		return 0;
	}
	bool* vcurr = calloc(n+1, sizeof(bool));
	int nsol = 0;
	SubSetEqualRec(n, s, vcurr, 1, &nsol,0);
	if (nsol == 0) {
		return 0;
	}
	return nsol;

 }