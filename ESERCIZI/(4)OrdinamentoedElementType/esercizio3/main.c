#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include "elemtype.h"
#include "vettore.h"
int main(void) {
	Vector* v = malloc(sizeof(Vector));
	v->capacity = 24;
	v->size = 24;
	
	v->data = malloc(v->size*sizeof(ElemType));
	v->data[0] = -12;
	v->data[1] = -4;
	v->data[2] = 3;
	v->data[3] = 3;
	v->data[4] = 3;
	v->data[5] = 3;
	v->data[6] = 4;
	v->data[7] = 5;
	v->data[8] = 6;
	v->data[9] = 6;
	v->data[10] = 7;
	v->data[11] = 8;
	v->data[12] = 34;
	v->data[13] = 54;
	v->data[14] = 56;
	v->data[15] = 234;
	v->data[16] = 346;
	v->data[17] =367;
	v->data[18] = 435;
	v->data[19] = 1233;
	v->data[20] = 3453;
	v->data[21] = 3456;
	v->data[22] = 4567;
	v->data[23] = 5667;
	ElemType e = 3;
	VectorFind(v, &e);
	
	return 0;
}