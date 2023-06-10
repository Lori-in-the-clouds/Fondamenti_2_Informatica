#include <stdlib.h>
extern int* CacciatorePreda(const char* v, size_t v_size, int u);
int main(void) {
	char v[] = { 'C','P','C','C','P','P'};
	int *ris = CacciatorePreda(v, sizeof(v) / sizeof(char), 1);
}