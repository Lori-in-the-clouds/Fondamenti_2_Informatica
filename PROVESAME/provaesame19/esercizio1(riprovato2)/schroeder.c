#include <stdlib.h>
#include <stdio.h>
int rec(int n) {
	if (n == 0) return 1;
	if (n == 1) return 2;
	return  ((((6 * n) - 3) * rec(n - 1)) - ((n - 2) * rec(n - 2))) / (n + 1);
}
int main(int argc, char** argv) {
	if (argc != 2) return 1;
	int n = atoi(argv[1]);
	if (n < 0) return 1;
	printf("%d", rec(n));
	return 0;
}