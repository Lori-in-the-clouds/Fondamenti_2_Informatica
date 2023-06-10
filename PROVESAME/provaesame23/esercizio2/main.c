#include <crtdbg.h>
#include <stdlib.h>
extern int* RisolviProdotto(int n, const int* s);
int main(void) {
	int s[] = { 1,2,5,8,9,16,18,40,45 };
	int *ris = RisolviProdotto(3, s);
	free(ris);
	_CrtDumpMemoryLeaks();
}