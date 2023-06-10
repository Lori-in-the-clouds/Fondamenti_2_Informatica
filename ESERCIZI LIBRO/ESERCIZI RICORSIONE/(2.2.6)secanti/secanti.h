#if !defined SECANTI_H
#define SECANTI_H
#include <stdlib.h>
typedef struct {
	int* coeffs;
	size_t size;
} Polinomio;
extern double Secanti(const Polinomio* p,double x0, double x1,double t, int max_iter);
#endif // NEWTON_H