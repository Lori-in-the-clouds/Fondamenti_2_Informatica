#define _CRT_SECURE_NO_WARNINGS
#include "prezzo.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
void TrovaArticoliRec(const struct Articolo* a, size_t a_size, int sum, int i, struct Articolo* vcurr,int som) {
	int k = 0;
	for (int j = 0; j < i; j++) {
		k += vcurr[j].prezzo;
	}
	if (k == sum) {
		printf("{");
		for (int j = 0; j < i-1; j++) {
			if (!strcmp(vcurr[j].nome," ")) continue;
			printf("%s, ", vcurr[j].nome);
		}
		printf("%s }\n", vcurr[i - 1].nome);
		return;

	}
	if (i >= a_size || k > sum) {
		return;
	}
	for (int j = i; j < a_size ; j++) {
		if (som + a[j].prezzo <= sum) {
			
			strcpy(vcurr[i].nome, a[j].nome);
			vcurr[i].prezzo = a[j].prezzo;

			TrovaArticoliRec(a, a_size, sum, j + 1, vcurr, som + a[j].prezzo);
			vcurr[i].prezzo = 0;
			strcpy(vcurr[i].nome, " ");
		}
	}
}
void TrovaArticoli(const struct Articolo* a, size_t a_size, int sum) {
	if (a == NULL) {
		return;
	}
	struct Articolo* vcurr = calloc(a_size, sizeof(struct Articolo));
	TrovaArticoliRec(a, a_size, sum, 0, vcurr,0);
	free(vcurr);
	return;
}