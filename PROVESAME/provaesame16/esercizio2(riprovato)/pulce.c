#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
void rec(const int* f, size_t f_size, int a, int b, int n, int h, size_t* ret_size, char* vcurr, int i,int current) {
	for (size_t j = 0; j < f_size; j++) {
		if (current == f[j]) return;
	}
	if (current == h) {
		*ret_size = i;
		return;
	}
	if (i == n) return;
	
	if (current + a >= 0) {
		vcurr[i] = 'a';
		rec(f, f_size, a, b, n, h, ret_size, vcurr,i + 1, current + a);
	}
	if (current - b >= 0) {
		vcurr[i] = 'b';
		rec(f, f_size, a, b, n, h, ret_size, vcurr,i + 1, current - b);
	}
	return;
	
}
char* GuidaLaPulce(const int* f, size_t f_size, int a, int b, int n, int h, size_t* ret_size) {
	char* vcurr = calloc(n, sizeof(int));
	*ret_size = 0;
	rec(f, f_size, a, b, n, h, ret_size, vcurr,0, 0);
	vcurr[ret_size[0] + 1] = '\0';
	return vcurr;
}