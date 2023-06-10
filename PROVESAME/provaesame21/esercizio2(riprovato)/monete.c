#include <stdlib.h>
#include <stdio.h>
void rec(int b, const int* m, size_t m_size, int* vcurr, int i,int *ris,int som) {
	if (som == b) {
		for (int j = 0; j < m_size; j++) {
			printf("%d ", vcurr[j]);
		}
		printf("\n");
		ris[0]++;
		return;
	}
	if (som > b) return;
	if (i == m_size) return;
	for (int j = 0; j <= b; j++) {
		vcurr[i] = j;
		rec(b, m, m_size, vcurr, i + 1, ris,som+(j*m[i]));
		vcurr[i] = 0;
	}
}
int CombinaMonete(int b, const int* m, size_t m_size) {
	int* vcurr = calloc(m_size, sizeof(int));
	int ris = 0;
	rec(b, m, m_size, vcurr, 0, &ris,0);
	free(vcurr);
	return ris;
}