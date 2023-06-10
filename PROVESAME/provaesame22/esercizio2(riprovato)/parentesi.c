#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
void rec(int n, char* vcurr, int i,int *ris) {
	if (vcurr[0] == ')' || vcurr[(n * 2) - 1] == '(') return;
	if (i == (n * 2)) {
		bool* preso = calloc(n * 2, sizeof(bool));
		for (int j = 0; j < n * 2; j++) {
			if (vcurr[j] == '(' && !preso[j]) {
				for (int m = j + 1; m < n * 2; m++) {
					if (vcurr[m] == ')' && !preso[m]) {
						preso[m] = true;
						preso[j] = true;
						break;
					}
				}
			}
		}
		for (int j = 0; j < n * 2; j++) {
			if (!preso[j]) {
				free(preso);
				return;
			}
		}
		//stampa
		for (int j = 0; j < n*2; j++) {
			printf("%c", vcurr[j]);
		}
		printf("\n");
		ris[0]++;
		free(preso);
		return;
	}

	vcurr[i] = '(';
	rec(n, vcurr, i + 1,ris);
	vcurr[i] = ')';
	rec(n, vcurr, i + 1,ris);


}
int Parentesi(int n) {
	if (n < 0) return -1;
	char* vcurr = calloc(n * 2, sizeof(char));
	int ris = 0;
	rec(n, vcurr, 0,&ris);
	free(vcurr);
	return ris;
}