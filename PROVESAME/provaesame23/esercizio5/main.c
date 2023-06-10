#include <stdlib.h>
extern char* SolveSuperstring(const char** v, size_t v_size);
int main(void) {
	char *v[] = { "FEDERICO", "MAURIZIO", "GIANPAOLO" };
	SolveSuperstring(v,3);
}