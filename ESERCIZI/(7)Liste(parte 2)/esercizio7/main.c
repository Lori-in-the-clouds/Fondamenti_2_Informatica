#include "list.h"
extern Item* AppendMod(const Item* i1, const Item* i2);
int main(void) {
	ElemType e[] = {
		{"Michele","f",12,"Firenze","f","f"},
		{"Federico","f",12,"f","f","f"},
		{"Lorenzo","f",12,"Firenze","f","f"},
		{"Andrea","f",12,"f","f","f"}
	};
	ElemType c[] = {
		{"Giovanni","f",12,"Firenze","f","f"},
		{"Daniele","f",12,"f","f","f"},
		{"Marco","f",12,"Firenze","f","f"},
		{"gabbo","f",12,"f","f","f"}
	};
	Item* m = ListCreateEmpty();
	Item* s = ListCreateEmpty();

	for (size_t i = 0; i < 4; i++) {
		m = ListInsertBack(m, &e[i]);
		s = ListInsertBack(s, &c[i]);

	}
	Item* r = AppendMod(m, s);
}