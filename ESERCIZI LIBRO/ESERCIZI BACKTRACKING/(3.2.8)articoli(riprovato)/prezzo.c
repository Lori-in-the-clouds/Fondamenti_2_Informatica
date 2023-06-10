#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "prezzo.h"
void rec(const struct Articolo* a, size_t a_size, int sum, int tmp,int i,bool *preso) {
	if (tmp > sum) return;
	if (tmp == sum) {
		for (int j = 0; j < i; j++) {
			if (preso[j]) {
				printf("%s,", a[j].nome);
			}
		}
		printf("\n");
		return;
	}
	if (i == a_size) return;
		if (!preso[i]) {
			if (tmp < sum) {
				preso[i] = true;
				rec(a, a_size, sum, tmp + a[j].prezzo,i + 1, preso);
				preso[i] = false;
			}
		}
	
	 rec(a, a_size, sum, tmp, i + 1, preso);

}
void TrovaArticoli(const struct Articolo* a, size_t a_size, int sum) {
	int* vcurr = calloc(a_size, sizeof(int));
	bool* preso = calloc(a_size, sizeof(bool));
	rec(a, a_size, sum, 0,0,preso);
}