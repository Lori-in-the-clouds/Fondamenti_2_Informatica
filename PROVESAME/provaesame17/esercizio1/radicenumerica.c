#include <stdlib.h>
#include <math.h>
#include <stdio.h>
void rec(int n) {
	int m = 0;
	int j = 0;
	int s = 1;
	while (s > 0) {
		 s =n /pow(10,j);
		j++;
		m += s%10;
	}
	if (j == 2) {
		printf("%d",m);
		return;
	}
	rec(m);
	
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
		printf("%d", n);
		return 0;
	}
	rec(n);
	return 0;
}