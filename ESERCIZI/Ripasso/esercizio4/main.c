#include "vettore.h"
#include <stdlib.h>
#include <string.h>
int main(void) {
	struct vettore v;
	v.data = malloc(5 * sizeof(int));
	v.size = 5;
	v.data[0] = 1;
	v.data[1] = 2;
	v.data[2] = 3;
	v.data[3] = 4;
	v.data[4] = 5;
	
	/*Push(&v, 7);*/
	Pop(&v);
}