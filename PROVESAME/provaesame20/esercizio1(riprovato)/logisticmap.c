#include <stdio.h>
#include <stdlib.h>
void rec(double x0, double r, double n,int i) {
	if (i == n) {
		printf("%f", x0);
		return;
	}
	rec((r * x0) * (1 - x0), r, n, i + 1);
}
int main(int argc, char** argv) {
	if (argc != 4) return 1;
	double x0 = atof(argv[1]);
	double r = atof(argv[2]);
	double n = atof(argv[3]);
	if (x0 < 0 || x0 > 1 || r < 0 || n < 0) return 1;
	rec(x0,r,n,0);
	return 0;
}