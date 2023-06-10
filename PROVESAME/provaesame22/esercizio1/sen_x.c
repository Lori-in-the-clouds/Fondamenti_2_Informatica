#include <stdlib.h>
#include <math.h>
#include <stdio.h>
double Fattoriale(int n) {
	if (n == 0) return 1; 
	else return n * Fattoriale(n - 1);
}
void Rec(long double x,int i, double *ris,int n) {
	if (n == i + 1) {
		printf("%lf", ris[0]);
		return;
	}
	(*ris) += ((double)pow(-1, n) / (double)Fattoriale(2 * n + 1)) * (double)pow(x, 2 * n + 1);
	Rec(x, i,ris, n + 1);
}
int main(int argc, char** argv) {
	if (argc != 3) return 1;
	double x = atof(argv[1]);
	double i = atof(argv[2]);
	if (i == 0) {
		double ris = 0.00000;
		printf("%lf",ris);
		return 0;
	}
	if (i < 0) return  1;
	long double ris = 0;
	Rec(x, i,&ris,0);
	return 0;
}