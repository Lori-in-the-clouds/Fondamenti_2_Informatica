#include <stdlib.h>
#include <stdio.h>
#include <math.h>
double rec(int n) {
	if (n == 0) return 4;

	return ((4. * pow(-1., n)) / ((2 * (double)n) + 1)) + rec(n - 1);
}

int main(int argc,char **argv) {
	if (argc != 2) return 1;
	int n = atoi(argv[1]);
	if (n < 0) return 1;
	printf("%f", rec(n));
	return 0;
}