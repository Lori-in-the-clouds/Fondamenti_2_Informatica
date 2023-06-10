#include <stdlib.h>
extern void StazioniServizio(double m,const double* d, const double *p, size_t n);
int main(void) {
	double prezzolitro[] = {45,45,43,39,33};
	double distanza[] = {300,324,348,372,396};
	int n = 5;
	
	StazioniServizio(1740, &distanza,&prezzolitro, n);
}