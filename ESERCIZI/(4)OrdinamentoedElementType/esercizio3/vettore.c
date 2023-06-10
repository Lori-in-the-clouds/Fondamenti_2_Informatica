#include <stdlib.h>
#include "elemtype.h"
#include "vettore.h"
void trovo(const Vector* v,const ElemType e, size_t inizio, size_t fine,int  *ris1) {
	ElemType pivot = v->data[(inizio + fine) / 2];
	int cmp = ElemCompare(&e,&pivot);
	if ((inizio == fine)) {
		if (ElemCompare(&v->data[fine],&e)==0) {
			*ris1 = (int)(inizio + fine) / 2;
		}
		return;
	}
	if (cmp < 0) {
		trovo(v, e, inizio,((inizio+fine)/2), ris1);
	}
	if (cmp > 0) {
		trovo(v, e, ((inizio + fine) / 2)+1, fine, ris1);
	}
	if (cmp == 0) {
		*ris1 = (int)(inizio + fine) / 2;
		int dim = *ris1;
		for (int i = 1; ElemCompare(&v->data[dim - i], &e) == 0; i++) {
			(*ris1)--;
			
		}
		return;
	}
}
int VectorFind(const Vector* v, const ElemType* e) {
	int ris = -1;
	if (v == NULL || v->size == 0 || v->capacity == 0) {
		return ris;
	}
	trovo(v, *e, 0, v->size - 1, &ris);
	return ris;
}