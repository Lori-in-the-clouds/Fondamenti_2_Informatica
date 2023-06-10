#include <stdlib.h>
#include <stdio.h>
void CombinaMoneteRec(int b, const int* m, size_t m_size, int* vcurr, int* nsol, int i,int som) {
	if (som > b) return;
	if (som == b) {
		(*nsol)++;
		for (int j = 0; j < m_size; j++) {
			printf("%d ", vcurr[j]);
		}
		printf("\n");
		return;
	}
	if (i == m_size) return;
	for (int j = 0; j < b + 1; j++) {
		if (som < b) {
			vcurr[i] = j;
			CombinaMoneteRec(b, m, m_size, vcurr, nsol, i + 1, som + (j * m[i]));
			vcurr[i] = 0;
		}
	}
}
int CombinaMonete(int b, const int* m, size_t m_size) {
	if (m_size <= 0) return 0;
	int* vcurr = calloc(m_size, sizeof(int));
	int nsol = 0;
	CombinaMoneteRec(b, m, m_size, vcurr, &nsol, 0,0);
	free(vcurr);
	return nsol;
}