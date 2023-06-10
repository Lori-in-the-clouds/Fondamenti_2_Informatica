#include <stdlib.h>
extern int* CacciatorePreda(const char* v, size_t v_size,int u);
int main(void) {
	char v[] = { 'P','C','P','P','P' };
	CacciatorePreda(&v, 5, 1);
	return 0;
}