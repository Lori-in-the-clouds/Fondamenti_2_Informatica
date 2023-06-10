#include <stdio.h>
void BacktrackSubset(int n, int i, int vcurr[], int* nsol) {

	if (i == n) {
		printf("%d) ", *nsol);
		(*nsol)++;
		for (int j = 0; j < n; j++) {
			printf("%d ", vcurr[j]);
		}
		printf("\n");
		return;
	}
	vcurr[i] = 0;
	BacktrackSubset(n, i + 1, vcurr, nsol);
	vcurr[i] = 1;
	BacktrackSubset(n, i + 1, vcurr, nsol);
}