#include <stdbool.h>
#include <stdlib.h>
#include<stdio.h> 
static void SubsetKrec(int n, int k, int i, bool* vcurr, int* nsol,int nolem) {
	if (i == n) {



		if (nolem == k) {
			printf("{ ");
			for (int j = 0; j < n; j++) {
				if (vcurr[j]) {
					printf("%i", j);
				}
			}
			printf("}, ");

		}
	
		return;

	}
		
		//FACCIO LA SCELTA E SCENDO DI UN LIVELLO
		vcurr[i] = 0; //ho fatto la scelta,scelgo il primo alberello 
		SubsetKrec(n, k, i + 1, vcurr, nsol,nolem); //cosi la mia i non cambia, la mia i rimane i
		//FACCIO LA SCELTA E SCENDO DI UN LIVELLO
		vcurr[i] = 1;
		SubsetKrec(n, k, i + 1, vcurr, nsol, nolem + 1);


	}



int SubsetK(int n, int k) {
	bool* vcurr = malloc(n * sizeof(int));
	int nsol = 0;
	SubsetKrec(n, k, 0, vcurr, &nsol,0);
	free(vcurr);
	return nsol;
}
