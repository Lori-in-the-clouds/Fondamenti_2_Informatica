#include <stdlib.h>
extern int* CacciatorePreda(const char* v, size_t v_size, int u);
int main(void) {
	const char v[] = { 'C','P','P','C','P' };
	CacciatorePreda(v, 5, 1);
}