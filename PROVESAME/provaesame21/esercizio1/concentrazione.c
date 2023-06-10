#include <stdio.h>
#include <stdlib.h>
void Rec(int n,int i,double *ris) {
	if (i == n - 1) {
		printf("%f", ris[0]);
		return;
	}
	*ris = (0.3 * (*ris)) + 0.2;
	Rec(n, i + 1,ris);
}
int main(int argc, char** argv) {
	if (argc != 2) return 1;
	int n = atoi(argv[1]);
	if (n < 1) return 1;
	double ris = 0;
	Rec(n,0,&ris);
	return 0;
}