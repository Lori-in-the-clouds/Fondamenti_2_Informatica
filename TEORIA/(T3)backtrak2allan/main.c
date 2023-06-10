extern void BacktrackSubset(int n, int i, int vcurr[], int* nsol);
#include <stdlib.h>
int main(void) {
	int* vcurr = malloc(2 * sizeof(int));
	int* nsol = malloc(2 * sizeof(int));
	BacktrackSubset(2, 0, vcurr, nsol);
	return 0;
}