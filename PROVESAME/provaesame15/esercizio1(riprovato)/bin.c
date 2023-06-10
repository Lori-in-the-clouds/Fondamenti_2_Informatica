#include <stdlib.h>
#include <stdio.h>
void rec(int n) {
	if (n == 1) {
		printf("1");
		return;
	}
	rec(n / 2);
	if (n % 2 == 0) {
		printf("0");
		return;
	}
	else {
		printf("1");
		return;
	}
}
int main(int argc, char** argv) {
	if (argc != 2) return 1;
	int n = atoi(argv[1]);
	if (n < 0) return 1;
	if (n == 0) {
		printf("0");
		return 0;
	}
	rec(n);
	return 0;
}