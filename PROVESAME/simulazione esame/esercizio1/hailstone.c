#include <stdlib.h>
#include <stdio.h>
void Hailstone(int n,int *nsol) {
	if (n == 1) {
		(*nsol)++;
		printf("%d", n);
		return;
	}
	if (n % 2 == 0) {
		(*nsol)++;
		printf("%d, ", n);
		n /= 2;
	}
	else {
		printf("%d, ", n);
		(*nsol)++;
		n = 3 * n + 1;
	}
	Hailstone(n,nsol);
}
int main(int argc, char** argv) {
	if (argc != 2) return 0;
	int n = atoi(argv[1]);
	if (n <= 0) return 0;
	int nsol = 0;
	Hailstone(n,&nsol);
	return nsol;
}