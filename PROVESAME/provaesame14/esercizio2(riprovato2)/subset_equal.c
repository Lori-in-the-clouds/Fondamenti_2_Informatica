#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
void rec(int n, int s, bool* preso, int som, int i) {
	
	if (som == s) {
		for (int j = 1; j <= n; j++) {
			if (preso[j]) {
				printf("%d", j);
			}
		}
		printf("\n");
		return;
	}
	if (i > n) return;
	if (som > s) return;


	for (int j = i; j <= n; j++) {
		if (!preso[j]) {
			preso[j] = true;
			rec(n, s, preso, som + j, j + 1);
			preso[j] = false;
		}
	}
	//li ho presi tutti 
	return;


}
void SubsetEqual(int n, int s) {
	bool* preso = calloc(n+1, sizeof(bool));
	rec(n, s,preso, 0, 1);
}
int main(void) {
	SubsetEqual(5, 7);
}
