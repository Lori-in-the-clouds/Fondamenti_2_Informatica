#include <stdlib.h>

int Minimo(const int* v, int v_size) {
	
	if (v_size == 1) {
		return *v;
	}
		int min =  Minimo(v+1, v_size - 1);
	

	if (*v < min) {
		return *v;
	}
	else {
		return min;
	}

}
// min(7,3,4,2) = min(7,min(3,4,2))

//						min(3,min(4,2))
//								min(4,min(2))
//										2

/*int Minimo(const int* v, int v_size) {
* v->size--;
* if (v_size==0) {
* return [0];
* }
* int min = Minimo(v,v_size);
* if(v[v_size] < min) {
* return v[v_size];
* }
* else {
* return min;
* }







*/