#include <stdlib.h>
#include <stdio.h>
void LogisticMapRec(double x0, double r, double n,int i) {
	if (i == n) {
		//printiamo
		printf("%f", x0);
		return;
	}
	double res = r * x0 * (1 - x0);
	LogisticMapRec(res, r, n, i + 1);
}
int main(int argc, char** argv) {
	if (argc != 4) return 1;
	double x0 = atof(argv[1]);
	double r = atof(argv[2]);
	double n = atof(argv[3]);
	if (x0 < 0 || x0 > 1 || r < 0 || n < 0) return 1;
	double ris = 0;
	LogisticMapRec(x0, r, n, 0);
	return 0;
}