#include <stdlib.h>
#include <stdbool.h>
#include "domino.h"
#include <crtdbg.h>
int main(void) {
	const Tessera v[] = { {.val1 = 5, .val2 = 3 }, {.val1 = 5, .val2 = 6 }, {.val1 = 6, .val2 = 2 } };
	int n = sizeof(v) / sizeof(Tessera);
	size_t ret_size = 0;
	Placing* ris = Domino(v, n, &ret_size);
	free(ris);
	_CrtDumpMemoryLeaks();
	return 0;
}