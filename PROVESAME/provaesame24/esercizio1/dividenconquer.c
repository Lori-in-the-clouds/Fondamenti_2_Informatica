#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>

int rec(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return (rec((int)floor((double)n / 2.))) +(rec((int)ceil((double)n / 2.))) + n;
}
int main(int argc, char** argv) {
	if (argc != 2) return 1;
	int n = atoi(argv[1]);
	if (n < 0) return 1;
	printf("%d", rec(n));
	return 0;
}