#include "list.h"
extern Item* Reverse(const Item* i);
int main(void) {
	ElemType e[] = {
		{"Michele","f",12,"Firenze","f","f"},
		{"Federico","f",12,"f","f","f"},
		{"Lorenzo","f",12,"Firenze","f","f"},
		{"Andrea","f",12,"f","f","f"}
	};
	Item* m = ListCreateEmpty();
	for (size_t i = 0; i < 4; i++) {
		m = ListInsertBack(m, &e[i]);
	}
	Reverse(m);
}