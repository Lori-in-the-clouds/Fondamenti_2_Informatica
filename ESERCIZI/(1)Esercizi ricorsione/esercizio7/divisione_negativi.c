#include <limits.h>
#include <math.h>
static int DivisioneNegativiRec(int a, int b) {
	
	if (a <= 0 && b > 0  || (a >= 0 && b < 0)) {
		if (a == 0) {
			return 0;
		}
		if (a == -1 && (b != 1 && b != -1 )) {
			return 0;
		}
		a = a + b;
		int ris = DivisioneNegativiRec(a, b) - 1;
		return ris;
		
}
	if ((a >= 0 && b > 0) || (a <= 0 && b < 0)) {
		if (a == 0) {
			return 0;
		}
		if (a == 1 && b != 1) {
			return 0;
		}
		a = a - b;
		int ris2 = DivisioneNegativiRec(a, b) + 1;
		return ris2;
	}
	
}
int DivisioneNegativi(int a, int b) {
	if (b == 0) {
		return INT_MAX;
	}
	if (fabs(b) > fabs(a)) {
		return 0;
	}
	
	return DivisioneNegativiRec(a, b);
}