#include <stdlib.h>
extern int CombinaMonete(int b, const int* m, size_t m_size);
int main(void) {
	int b = 4;
	int m[] = { 1,2,50,10,5,20 };
	CombinaMonete(b, m, sizeof(m) / sizeof(int));
}


