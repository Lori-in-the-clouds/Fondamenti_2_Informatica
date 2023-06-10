#include "vettore.h"
#include <stdlib.h>

void Push(struct vettore* v, int d) {
	int num = v->size + 1;
	
	v->data = realloc(v->data, num * sizeof(int));
	v->data[v->size] = d;
	v->size += 1;
	return EXIT_SUCCESS;

}
int Pop(struct vettore* v) {
	int* ris = malloc(v->size * sizeof(int));
	for (int i = 0; i < v->size; i++) {
		ris[i] = v->data[i];
	}
	int ris1 = v->data[0];
	v->data = realloc(v->data, (v->size - 1) * sizeof(int));
	int j = 1;
	for (int i = 0; i < v->size-1; i++) {
		v->data[i] = ris[j];
		j++;

	}
	v->size = v->size - 1;
	free(ris);
	return ris1;
 }