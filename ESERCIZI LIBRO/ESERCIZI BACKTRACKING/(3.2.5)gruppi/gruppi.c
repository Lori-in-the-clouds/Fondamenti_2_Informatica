#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
struct alunno {
	char name[21];
};
static bool Verifica(struct alunno* p, struct alunno* vcurr, int vcurr_size) {
	for (int j = 0; j < vcurr_size; j++) {
		bool a = vcurr[j].name[0] == p->name[0];
		bool b = (vcurr[j].name[0] == p->name[0] + 1) || (vcurr[j].name[0] == p->name[0] -1);
		if (a || b) return false;
	}
	return true;
}

void GruppiRec(const struct alunno* p, int n, int* nsol, struct alunno* vcurr, int i, int size) {
	if (i == n) {
		(*nsol)++;
		printf("{");
		for (int j = 0; j < n - 1; j++) {
			printf("%s, ", vcurr[j].name);
		}
			printf("%s }\n", vcurr[n - 1].name);
			return;
	}
	for (int j = 0; j < size; j++) {
			if (Verifica(p+j,vcurr,i)) {
				strcpy(vcurr[i].name, p[j].name);
				GruppiRec(p, n, nsol, vcurr, i + 1, size);
			}
		}
}
int Gruppi(const char* filename, int n) {
	if (n < 1) {
		return 0;
	}
	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return 0;
	}
	int size = 0;
	struct alunno* p = malloc(n * sizeof(struct alunno));
	struct alunno* vcurr = malloc(n * sizeof(struct alunno));
	size_t turn1 = 0;
	int nsol = 0;
	for (int i = 0;turn1 != EOF; i++) {
		turn1 = fscanf(f, "%s", &p[i]);
		size++;
	}
	GruppiRec(p, n, &nsol, vcurr, 0,size-1);
	return nsol;
}