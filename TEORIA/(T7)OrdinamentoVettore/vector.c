#include <stdint.h>
#include <stdlib.h>
#include <math.h>
typedef struct {
	size_t capacity; //quanto spazio ho a disposizione adesso 
	size_t size;
	int* data;
} Vector;
void Pushback(Vector *v,int e) {
	if (v->size = v->capacity) {
		v->capacity *= 2;
		v->data = realloc(v->data, v->capacity * sizeof(int));
	}
	v->data[v->size] = e;
	v->size++;
}
void NaiveSort(Vector* v) {
	for (size_t i = 0; i < v->size; i++) {
		size_t minpos = i;
		for (size_t j = i + 1; j < v->size; j++) {
			if (v->data[j] < v->data[minpos]) {
				minpos = j;
			}
		}
		if (minpos != i) {
			Swap(v->data + minpos, v->data + i);
	}
	}
}
void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int main(void) {
	Vector v = { .capacity = 1,.size = 0,.data = malloc(sizeof(int)) };
	srand(0);
	for (int i = 0; i < 20; i++) {
		PushBack(&v, rand());
	}

	NaiveSort(&v);
	free(v.data);
	return EXIT_SUCCESS;
}