#include <stdlib.h>
#include <stdio.h>
#include <math.h>
void Rec(int n,int comp,int i) {
	if (comp == n) {
		printf("4^%d = %d", i - 1, n);
		return;
	}
	if (comp > n) {
		printf("!p4");
		return;
	}
	Rec(n,pow(4,i), i + 1);
}
int main(int argc, char **argv) {
	if (argc != 2) return 1;
	int n = atoi(argv[1]);
	if (n < 0) return 1;
	Rec(n,1,0);
}