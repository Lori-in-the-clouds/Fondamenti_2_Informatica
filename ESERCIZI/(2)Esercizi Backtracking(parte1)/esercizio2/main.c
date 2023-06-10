#include <stdlib.h>
extern void BabboNatale(const int* pacchi, size_t pacchi_size, int p);
int main(void) {
	const int pacchi[] = { 10,11,1,3,3 };
	const int pacchi1[] = {1,2,20,10,15,13,100,23,49,30,5};
	const int pacchi2[] = {10,15,13,100,23,49,30,5 };
	BabboNatale(&pacchi, 5, 20);
	BabboNatale(&pacchi1,11,100);
	BabboNatale(&pacchi1, 11, 200);
	BabboNatale(&pacchi1, 8, 100);
	return 0;
}