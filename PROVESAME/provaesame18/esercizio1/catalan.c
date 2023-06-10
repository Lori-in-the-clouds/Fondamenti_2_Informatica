#include <stdlib.h>
#include <stdio.h>
int MainRec(int n) {
	long long r = 0;
	if (n<=1) {
		return 1;
	}
	for (int i = 0; i < n; i++) {
	r += MainRec(i) * MainRec(n - i - 1);
	}
	return r;
}

int main(int argc, char** argv) {
	if (argc != 2) {
		return 1;
	}
	int n = atoi(argv[1]);
	if (n < 0) {
		return 1;
	}
	printf("%d",MainRec(n));
	return 0;
}