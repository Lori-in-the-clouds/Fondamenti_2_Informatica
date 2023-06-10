#include "gioielli.h"
#include <stdlib.h>
int main(void) {
	char* filename = "prova1.txt";
	size_t ret_size = 0;
	Gioiello *ris =CompraGioielli(filename, 200, &ret_size);
	return 0;
}