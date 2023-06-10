#include <stdlib.h>
extern char* GuidaLaPulce(const int* f, size_t f_size, int a, int b, int n, int h, size_t* ret_size);
int main(void) {
	int f[] = { 8,3,16,6,12,20 };
	int a = 15;
	int b = 13;
	int h = 11;
	int n = 5;
	int ret_size = 0;
	GuidaLaPulce(f, sizeof(f) / sizeof(int), a, b, n, h, &ret_size);
}