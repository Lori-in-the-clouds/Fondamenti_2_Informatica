#include <math.h>
void PowerTwoRec(unsigned int n,int *ris) {
	if (n == 1) {
		return;
	}
	if (n % 2 == 0) {
		PowerTwoRec(n / 2,ris);
		ris[0]++;
	}
	else {
		int m = 3;
		while (n % m != 0) {
			m++;
		}
		PowerTwoRec(n / m,ris);
	}

}

unsigned int PowerTwo(unsigned int n) {
	int ris = 0;
	if (n == 0) {
		return 0;
	}
	PowerTwoRec(n, &ris);
	return ris;
}