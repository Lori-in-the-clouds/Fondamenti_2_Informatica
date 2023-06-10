#include <stdlib.h>
#include <string.h>
extern int* CacciatorePreda(const char* v, size_t v_size, int u);
int main(void) {
	char v[] = { "CPPCP" };
	int n = strlen(v);
	size_t v_size = sizeof(v) / sizeof(char);
	int *ris = CacciatorePreda(v,5, 1);
}