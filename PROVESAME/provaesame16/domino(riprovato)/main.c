#include "domino.h"
int main(void) {
	Tessera t[] = {{.val1 = 5, .val2 = 3}, {.val1 = 5, .val2 = 6},{.val1 = 6, .val2 = 2}};
	size_t ret_size = 0;
	Domino(t, sizeof(t) / sizeof(Tessera), &ret_size);
}