#include "newton.h"
#include <math.h>
double Newton(const Polinomio* p, const Polinomio* d, double xn, double t, int max_iter,double prev,int i) {
	double fn = 0;
	double fnn = 0;
	for (int j = 0; j < p->size; j++) {
		 fn += pow(xn, j) * p->coeffs[j];
	}
	for (int j = 0; j < d->size; j++) {
		fnn += pow(xn, j) * d->coeffs[j];
	}
	prev = xn;
	xn = xn - (fn / fnn);
	if (fabs(xn - prev) <= t) {
		return xn;
	}
	if (max_iter >= 0 && max_iter == i) {
		return xn;
	}
	Newton(p, d, xn, t, max_iter,prev,i+1);
}
