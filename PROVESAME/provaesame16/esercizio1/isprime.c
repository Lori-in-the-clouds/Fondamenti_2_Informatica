#include <stdlib.h>
#include <stdio.h>
void mainRec(int n,int i) {
	if (i == n) {
		printf("true");
		return;
	}
	if (n % i == 0) {
		printf("false");
		return;
	}
	mainRec(n, i + 1);
}
int main(int argc, char** argv) {
	if (argc != 2) {
		return 1;
	}
	int n = atoi(argv[1]);
	if (n < 0) {
		return 1;
	}
	if (n == 0 || n==1) {
		printf("false");
		return  0;
	}
	mainRec(n,2);
	return 0;
}