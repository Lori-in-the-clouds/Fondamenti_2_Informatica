#if !defined VETTORE_H
#define VETTORE_H
#include "elemtype.h"
typedef struct {
	size_t capacity;
	size_t size;
	ElemType* data;

} Vector;
 extern int VectorFind(const Vector* v, const ElemType* e);
#endif //VETTORE_H