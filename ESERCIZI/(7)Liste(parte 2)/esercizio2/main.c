#include "list.h"
#include "string.h"
#include <stdlib.h>
#include <crtdbg.h>

extern Item* Delete(Item* i, const char* name);
int main(void) {
	ElemType e[] = {
		{"Michele","firenze",12,"f","f","f"},
		{"Federico","firenze",12,"f","f","f"},
		{"Lorenzo","firenze",12,"f","f","f"},
		{"Andrea","firenze",12,"f","f","f"}
	};
	Item* m = ListCreateEmpty();
	for (size_t i = 0; i < 4; i++) {
		m =ListInsertBack(m, &e[i]);
	}
	Delete(m,"Michele");

	ListDelete(m);
	_CrtDumpMemoryLeaks();

}