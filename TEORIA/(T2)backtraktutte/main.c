extern void BacktrackTutte(int n, int i, int k, int vcurr[], int* nsol);
#include <stdlib.h>
int main(void) {
	int* vcurr = malloc(3 * sizeof(int));
	int* nsol = malloc(3*sizeof(int));
	BacktrackTutte(3, 0, 2, vcurr, nsol);
	return 0;
}