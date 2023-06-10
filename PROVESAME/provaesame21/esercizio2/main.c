#include <stdlib.h>
extern int CombinaMonete(int b, const int* m, size_t m_size);
int main(void) {
	int m[] = { 1,2,50,10,5,20 };
	size_t size = sizeof(m) / sizeof(int);
	CombinaMonete(4, m, size);
}