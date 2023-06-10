#include "sciatori.h"
#include <stdlib.h>
int main(void) {
	int n = 4;
	double* altezze = malloc(n * sizeof(double));
	altezze[0] = 35;
	altezze[1] = 42;
	altezze[2] = 64;
	altezze[3] = 24;
	double* lunghezze = malloc(n*sizeof(double));
	lunghezze[0] = 22;
	lunghezze[1] = 54;
	lunghezze[2] = 21;
	lunghezze[3] = 33;
	Sciatore *ris =Accoppia(altezze,lunghezze, n);
}