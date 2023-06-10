#include <stdlib.h>
#include <math.h>
void Swap(int* vector, int index1, int index2) {
	int a = vector[index1];
	vector[index1] = vector[index2];
	vector[index2] = a;
	return;
}
void Stooge(int* vector, size_t vector_size) {
	if (vector_size <= 0) return;
	if (vector == NULL) return;
	if (vector[0] > vector[vector_size - 1]) {
		Swap(vector, 0, vector_size - 1);
	}
	if (vector_size < 3) return;
	

	//i primi 2/3
	int index1 = 0;
	double prov1 = ((2. / 3) * vector_size);
	if (prov1 == ceil(prov1)) {
		index1 = ((int)ceil((2. / 3) * vector_size));
	}
	else {
		index1 = ((int)ceil((2. / 3) * vector_size));
	}
	Stooge(vector,index1);


	//gli ultimi 2/3
	int index = 0;
	double prov = ((1. / 3) * vector_size);
	if (prov == ceil(prov)) {
		index = ((int)ceil((1. / 3) * vector_size));
	}
	else {
		index = ((int)ceil((1. / 3) * vector_size)) - 1;
	}

	Stooge(vector + index, vector_size - index);


	//di nuovo i primi 2/3
	int index2 = 0;
	double prov2 = ((2. / 3) * vector_size);
	if (prov2 == ceil(prov1)) {
		index2 = ((int)ceil((2. / 3) * vector_size));
	}
	else {
		index2 = ((int)ceil((2. / 3) * vector_size));
	}
	Stooge(vector, index2);
}