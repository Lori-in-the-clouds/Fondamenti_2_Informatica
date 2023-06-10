#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include "prezzo.h"
#include <stdio.h>
#include <string.h>
void TrovaArticoliRec(struct Articolo* a, size_t a_size, int sum,int moment,int i,struct Articolo *vcurr) {
	if (moment > sum) return;
	if (moment == sum) {
		for (int j = 0; j < a_size; j++) {
			if (strcmp(vcurr[j].nome,"")!=0) {
				printf("%s, ", vcurr[j].nome);
			}
		}
		printf("\n");
		return;
	}
	if (i == a_size) return;
	for (int j = i; j < a_size; j++) {
		if (moment < sum) {
			strcpy(vcurr[i].nome,a[j].nome);
			TrovaArticoliRec(a, a_size, sum, moment + a[j].prezzo, j + 1, vcurr);
			strcpy(vcurr[i].nome, "");
		}
	}
}
void TrovaArticoli(const struct Articolo* a, size_t a_size, int sum) {
	if (a == NULL) return;
	struct Articolo* vcurr = calloc(a_size, sizeof(struct Articolo));
	TrovaArticoliRec(a, a_size, sum, 0, 0,vcurr);
	free(vcurr);
	return;
}