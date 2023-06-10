#include <stdlib.h>
#include <stdio.h>
void HailstoneRec(int n, size_t* ris) {
	if (n == 1) {
		printf("%d", n);
		return;
	}
	if (n % 2 == 0) {
		(*ris)++;
		printf("%d, ", n);
		HailstoneRec(n / 2, ris);
	}
	else {
		(*ris)++;
		printf("%d, ",n);
		HailstoneRec((3 * n) + 1, ris);
	}
}
size_t Hailstone(int n) {
	if (n <= 0) {
		return 0;
	}
	size_t ris = 0;
	HailstoneRec(n, &ris);
	return ris;
 }
