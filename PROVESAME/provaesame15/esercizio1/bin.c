#include <stdlib.h>
#include <stdio.h>
void  rec(int n) {
	if (n == 1) {
		printf("%d", n);
		return;
	}
		rec(n / 2);
		printf("%d",n % 2);
}
int main(int argc, char** argv) {
	if (argc != 2) {
		return 1;
	}
	int n = atoi(argv[1]);
	if (n < 0) {
		return 1;
	}
	if (n == 0) {
		printf("0");
	} else rec(n);
	return 0;
}