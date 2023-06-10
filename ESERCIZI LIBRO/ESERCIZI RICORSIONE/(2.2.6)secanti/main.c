#include "secanti.h"
#include <stdlib.h>
int main(void) {
	Polinomio* p = malloc(sizeof(Polinomio));
	p->size = 4;
	p->coeffs = malloc((p->size * sizeof(Polinomio)));
	p->coeffs[0] = 1;
	p->coeffs[1] = -12;
	p->coeffs[2] = -3;
	p->coeffs[3] = 2;
	double n = Secanti(p, -2, 4, 0.00001, 4);

}