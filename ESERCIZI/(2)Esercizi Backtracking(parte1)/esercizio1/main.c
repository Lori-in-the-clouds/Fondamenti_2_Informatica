#include <time.h>
extern int Ombrelloni(int k, int n);

int main(void) {
	int tick = clock();
	Ombrelloni(4, 100);
	int tock = clock();
	
	double elapsed = (tock - tick)/(double)CLOCKS_PER_SEC;
	return 0;
}