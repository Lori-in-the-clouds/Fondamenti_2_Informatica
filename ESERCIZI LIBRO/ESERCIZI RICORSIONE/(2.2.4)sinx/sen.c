#include <math.h> 
#include <float.h>
double fatt(int k) {
	if (k == 0) {
		return 1;
	}
	return fatt(k - 1) * k;
}
double SenRec(double x, int i, int n) {
	if (n > i) {
		return 0;
	}
	double ris = (pow(-1, n) / fatt(2 * n + 1)) * pow(x, 2 * n + 1);
	return SenRec(x, i, n+1)+ris;

}

double Sen(double x, int i) {
	if (i < 0) {
		return DBL_MIN;
	}
	return SenRec(x, i, 0);
	
}