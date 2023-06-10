#include <stdio.h>
#include <stdlib.h>
int rec(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (n == 2) return 3;
	return 3 * rec(n - 1) - 3 * rec(n - 2) + rec(n - 3);
}
int main(int argc, char** argv) {
	if (argc != 2) return 1;
	int n = atoi(argv[1]);
	if (n < 0) return 1;
	printf("%d",rec(n));
	return 0;
}