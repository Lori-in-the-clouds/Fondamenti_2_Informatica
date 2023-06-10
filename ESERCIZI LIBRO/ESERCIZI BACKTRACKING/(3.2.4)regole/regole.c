#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
void RegoleRec(const char* r, int i, int* vcurr,bool *usati) {
	//primo filtro, incremento e decremento
	if (i == strlen(r) + 1) {
		for (int j = 0; j <= strlen(r) + 1; j++) {
			if (r[j] == 'd') {
				if (vcurr[j] <= vcurr[j + 1]) return;
			}
			if (r[j] == 'i') {
				if (vcurr[j] >= vcurr[j+1]) return;
			}
		}
		for (int j = 0; j < strlen(r) + 1; j++) {
			printf("%d", vcurr[j]);
		}
		printf("\n");
		return;
	}
	for (int j = 1; j <= strlen(r)+1; j++) {
		if (!usati[j]) {
			usati[j] = true;
			vcurr[i] = j;
			RegoleRec(r, i + 1, vcurr, usati);
			usati[j] = false;
		}
	}
}
void Regole(const char* r) {
	if (r == "") {
		printf("1");
		return;
	}
	int* vcurr = calloc(strlen(r) + 1, sizeof(int));
	bool* usati = calloc(strlen(r) + 1, sizeof(int));
	RegoleRec(r, 0, vcurr,usati);
	free(vcurr);
	free(usati);
}