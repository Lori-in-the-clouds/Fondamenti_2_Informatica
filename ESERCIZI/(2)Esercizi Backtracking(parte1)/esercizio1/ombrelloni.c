#include <stdlib.h>
#include <stdio.h>
void OmbrelloniRec(int k, int n,int i,int vcurr[],int *nsol,int sss) {
	//ottimizzazione
	if ((vcurr[i] == 1) && (vcurr[i + 1] == 1)) {
		return;
	}
	//parte senza ottimizzazione, si taglia solo 
	if (i == n) {
		for (int j = 0; j < n; j++) {
			if ( (vcurr[j] == 1) && (vcurr[j + 1] == 1)) {
				return;
			}
		}
		if ((sss) != k) {
			return;
		}
		int cont = 0;
		for (int j = 0; j < n; j++) {
			if (cont == 0) {
				if (*nsol < 9) printf(" %i) ", (*nsol) + 1);
				else {
					printf("%i) ", (*nsol) + 1);
				}
				(*nsol)++;
				cont++;
			}
			printf(" %i", vcurr[j]);
		}
		printf("\n");
		return;
	}
	vcurr[i] = 0;
	OmbrelloniRec(k, n, i + 1, vcurr, nsol,sss);
	//if(vcurr[i-1]!=0) {
	vcurr[i] = 1;
	OmbrelloniRec(k, n, i + 1, vcurr, nsol,sss+1);
	//}
	vcurr[i] = 0;
}


int Ombrelloni(int k, int n) {
	if (k < 0 || n < 0) {
		return 0;
	}
	int* vcurr = malloc(n * sizeof(int));
	int *nsol = 0;
	OmbrelloniRec(k, n, 0, vcurr, &nsol,0);
	free(vcurr);
	return nsol;
}