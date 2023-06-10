#include <stdlib.h>
#include "elemtype.h"
#include "vettore.h"
void VectorSort(Vector* v) { //bubble sort 
	if (v == NULL) {
		return;
	}
	bool ordinato = false;
	int dim = v->size;
	while (dim > 1 && !ordinato) {
		ordinato = true;
		for (int i = 0; i < dim - 1; i++) {
			if (ElemCompare(&v->data[i], &v->data[i + 1])>0) {
				ElemSwap(&v->data[i], &v->data[i + 1]);
				ordinato = false;
			}
		}
		dim--;
	}

}