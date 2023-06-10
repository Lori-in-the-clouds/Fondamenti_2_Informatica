#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void rec(const char* str, int n, char* vcurr, int* nsol, int i) {
	if (i == n) {
		for (int j = 0; j < n; j++) {
			printf("%c", vcurr[j]);
		}
		printf("\n");
		(*nsol)++;
		return;
	}
	for (int j = 0; j < strlen(str); j++) {
		vcurr[i] = str[j];
		rec(str, n, vcurr, nsol, i + 1);
	}
}
int Password(const char* str, int n) {
	if (str == NULL || n <= 0) return 0;
	char* vcurr = calloc(n, sizeof(char));
	int nsol = 0;
	rec(str, n, vcurr, &nsol, 0);
	free(vcurr);
	return nsol;
}