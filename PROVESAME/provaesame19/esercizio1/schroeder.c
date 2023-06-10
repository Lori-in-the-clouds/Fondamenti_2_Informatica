#include <stdlib.h>
#include <stdio.h>
int mainRec(int n) {
	if (n == 0) {
		return 1;
	}
	if (n == 1) {
		return 2;
	}
	else {
		return (((6 * n) - 3) * mainRec(n - 1) / (n + 1)) - (((n - 2) * mainRec(n - 2)) / (n + 1));
	}
}
int main(int argc, char** argv) {
	if (argc != 2) {
		return 1;
	}
	int n = atoi(argv[1]);
	if (n < 0) {
		return 1;
	}
	int ris =mainRec(n);
	printf("%d", ris);
	return 0;
}