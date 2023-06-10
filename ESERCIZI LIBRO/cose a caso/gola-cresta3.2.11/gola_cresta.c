#include <stdlib.h>
#include <stdio.h>
void GolaCrestaRec(size_t n,int *vcurr,int i,int *cont) {
	
	if (i == n) {
		//filtro
		int m = 0;
		for (int j = 0; j < n; j += 3) {
			int cont = 0;
			if ((vcurr[m] < vcurr[m + 1]) && (vcurr[m + 1] > vcurr[m + 2])) {
				cont++;
			}
			if ((vcurr[m] > vcurr[m + 1]) && (vcurr[m + 1] < vcurr[m + 2])) {
				cont++;
			}
			if (cont == 0) {
				return;
			}
			m++;
		}
		//stampiamo 
		printf("(");
		for (size_t j = 0; j < n-1; j++) {
			printf("%d, ",vcurr[j]);
		}
		printf("%d", vcurr[n-1]);
		printf(")\n");
		(*cont)++;
		return;
	}
	vcurr[i] = 0;
	GolaCrestaRec(n, vcurr, i + 1,cont);
	vcurr[i] = 1;
	GolaCrestaRec(n, vcurr, i + 1,cont);
	vcurr[i] = 2;
	GolaCrestaRec(n, vcurr, i + 1,cont);

}
void GolaCresta(size_t n) {
	if (n <= 0) {
		return NULL;
	}
	int* vcurr = calloc(n, sizeof(int));
	int cont = 0;
	GolaCrestaRec(n, vcurr, 0,&cont);
	printf("%d", cont);
}