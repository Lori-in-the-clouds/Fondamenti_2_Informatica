#include "list.h"
extern Item* Sort(const Item* i);
int main(void) {
	ElemType e[] = {
		{"3","f",12,"Firenze","f","f"},
		{"1","f",12,"f","f","f"},
		{"4","f",12,"Firenze","f","f"},
		{"2","f",12,"f","f","f"}
	};
	/*ElemType c[] = {
		{"Giovanni","f",12,"Firenze","f","f"},
		{"Daniele","f",12,"f","f","f"},
		{"Marco","f",12,"Firenze","f","f"},
		{"gabbo","f",12,"f","f","f"}
	};*/
	Item* m = ListCreateEmpty();
	//Item* s = ListCreateEmpty();

	for (size_t i = 0; i < 4; i++) {
		m = ListInsertBack(m, &e[i]);
		//s = ListInsertBack(s, &c[i]);

	}
	Sort(m);
}