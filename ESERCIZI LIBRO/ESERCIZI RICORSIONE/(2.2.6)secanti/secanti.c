#include "secanti.h"
#include <math.h>
double SecantiRec(const Polinomio* p, double x0, double x1,double t, int max_iter, int i) {
	//controlli
	if (fabs(x1 - x0) <= t) {
		return x1;
	}
	if (max_iter >= 0 && i == max_iter) {
		return x1;
	}
	double f1 = 0;
	double f0 = 0;
	for (int j = 0; j < p->size; j++) {
		f1 += pow(x1, j) * p->coeffs[j];
		f0 += pow(x0, j) * p->coeffs[j];
	}
	double prev = x1;
	x1 = x1 - (((x1 - x0) / (f1 - f0)) * f1);
	SecantiRec(p, prev, x1,t, max_iter, i + 1);
}
double Secanti(const Polinomio* p, double x0, double x1,double t,int max_iter) {
	return SecantiRec(p, x0, x1, t, max_iter,0);
}