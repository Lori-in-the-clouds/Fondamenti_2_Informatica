#include <stdlib.h>
#include <string.h>
#include <stdio.h>
void PasswordRec(const char* str, int n,size_t *vcurr,int i,size_t m,int* ris) {
	if (i == n) {
		(*ris)++;
		for (int j = 0; j < n; j++) {
			printf("%c", str[vcurr[j]]);
		}
		printf("\n");
		return;
	}
	for (size_t j = 0; j < m; j++) {
		vcurr[i] = j;
		PasswordRec(str, n, vcurr, i + 1,m,ris);
	}
}

int Password(const char* str, int n) {
	size_t* vcurr = calloc(n, sizeof(int));
	size_t m = strlen(str);
	int ris = 0;
	if (str == NULL) {
		
		return ris;
	}
	PasswordRec(str, n, vcurr, 0, m, &ris);
	
	return ris;
}