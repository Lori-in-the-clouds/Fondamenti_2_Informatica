#if !defined NEWTON_H
#define NEWTON_H
typedef struct {
	int* coeffs;
	size_t size;
} Polinomio;
extern double Newton(const Polinomio* p, const Polinomio* d, double xn, double t, int max_iter);
#endif // NEWTON_H