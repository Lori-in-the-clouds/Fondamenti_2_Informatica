#include "newton.h"
#include <stdlib.h>
int main(void) {
	Polinomio* p = malloc(sizeof(Polinomio));
	p->size = 4;
	p->coeffs = malloc((p->size * sizeof(Polinomio)));
	p->coeffs[0] = 0;
	p->coeffs[1] = -2;
	p->coeffs[2] = 0;
	p->coeffs[3] = 1;
	
	Polinomio* d = malloc(sizeof(Polinomio));
	d->size = 3;
	d->coeffs = malloc((d->size * sizeof(Polinomio)));
	d->coeffs[0] = -2;
	d->coeffs[1] = 0;
	d->coeffs[2] = 3;
	
	double ris = Newton(p, d,0.5,0.00001,-1);
	return 0;
}