#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
void rec(char* str, int i, int* vcurr,char **s,int *numeri,int*ris) {
	if (i == strlen(str)) {
		for (size_t j = strlen(str); j>0; j--) {
			printf("%c",s[numeri[j-1]][vcurr[j-1]]);
		}
		printf("\n");
		ris[0]++;
		return;
	}
	for (int j = 0; j < 3; j++) {
		vcurr[i] = j;
		rec(str, i + 1, vcurr,s,numeri,ris);
	}
}
int ParoleT9(const char* str) {
	if (str == NULL) {
		return 0;
	}
	char* s[] = { {"00"},{"00"}, {"ABC"},{"DEF"},{"GHI"},{"JKL"},{"MNO"},{"PQRS"},{"TUV"},{"WXYZ"}};
	int n = atoi(str);
	int ris = 0;
	int m = n;
	int num = 0;
	while (m != 0) {
		m = m / 10;
		num++;
	}
	m = n;
	int* numeri = malloc(num*sizeof(int));
	for (int i = 0; i < num; i++) {
		int po = (int)pow(10, i);
		numeri[i] = (m/po)%10;
	}
	int* vcurr = calloc(num, sizeof(int));
	rec(str, 0, vcurr,s,numeri,&ris);
	free(numeri);
	free(vcurr);
	return ris;
}
