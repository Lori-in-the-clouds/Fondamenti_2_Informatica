#if !defined CONCATENA_H
#define CONCATENA_H
#include "list.h"
enum ConcType {
	kCopy,
	kNoCopy
};
extern Item* Concatena(Item* i1, Item* i2, enum ConcType c);
#endif //CONCATENA_H