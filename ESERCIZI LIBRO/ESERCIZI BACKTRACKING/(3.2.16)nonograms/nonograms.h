#if !defined NONOGRAMS_H
#define NONOGRAMS_H
#include <stdlib.h>
typedef struct {
	size_t rows, cols;
	int** r_constr, **c_constr;
} Constraints;
extern void Nonogram(const Constraints* constr);
#endif //NONOGRAMS_H