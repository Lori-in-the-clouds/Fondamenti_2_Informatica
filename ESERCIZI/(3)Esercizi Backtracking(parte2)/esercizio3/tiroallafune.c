#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
void tiroallafune(int i, int* vcurr, int m, int* vbest, int n, char** argv, int* vmin,int cont) {
	//usa la calloc per memorizzare array a tutti 0 coglione 
	//usa memcpy per copiare un array in un altro

	if (i == m) {
		for (int j = 0; j < m; j++) {
			if (vcurr[j] == 1) {
				cont++;
			}
		}
		if (cont != n) {
			return;
		}
		int cont1 = 0;
		int cont2 = 0;
		//trovo la somma del primo gruppo
		for (int j = 0; j < m; j++) {
			if (vcurr[j] == 1) {
				cont1 += atoi(argv[j + 1]);
			}
			else {
				cont2 += atoi(argv[j + 1]);
			}
		}
		//cerco il vmin e inserisco il vbest
		if (abs(cont1 - cont2) < (*vmin)) {
			*vmin = abs(cont1 - cont2);
			for (int j = 0; j < m; j++) {
				vbest[j] = vcurr[j];
			}
		}
		return;
	}
	vcurr[i] = 0;
	tiroallafune(i + 1, vcurr, m, vbest, n, argv, vmin,0);
	vcurr[i] = 1;
	tiroallafune(i + 1, vcurr, m, vbest, n, argv, vmin,0);
	vcurr[i] = 0;
}
int main(int argc, char** argv) {
	if (argc == 1) {
		return EXIT_FAILURE;
	}
	int n = (argc - 1) / 2;
	int* vcurr = malloc((argc - 1) * sizeof(int));
	int* vbest = malloc((argc - 1) * sizeof(int));
	int* secbest = malloc((argc - n) * sizeof(int));
	int* vmin = malloc(1 * sizeof(int));
	*vmin = INT_MAX;
	int* cont = malloc(1 * sizeof(int));
	cont[0] = 0;
	for (int i = 0; i < (argc-1); i++) {
		vcurr[i] = 0;
		vbest[i] = 0;
	}
	tiroallafune(0, vcurr, (argc - 1), vbest, n, argv, vmin,0);
	
	//stampiamo
	printf("{");
	int cos = 0;
	for (int i = 0; i < argc - 1; i++) {
		if (vbest[i] == 1) {
			if (cos == n - 1) {
				printf(" %s ", argv[i + 1]);
				cos = 0;
				break;
			}
			printf(" %s,", argv[i + 1]);
			cos++;
		}
	}
	printf("}");
	printf(" {");
	for (int i = 0; i < argc - 1; i++) {
		if (vbest[i] == 0) {
			if (cos == ((argc-1) - n) - 1) {
				printf(" %s ", argv[i + 1]);
				break;
			}
			printf(" %s,", argv[i + 1]);
			cos++;
		}
	}
	printf("}");
	free(vcurr);
	free(vbest);
	free(secbest);
	free(vmin);
	return EXIT_SUCCESS;
	

}