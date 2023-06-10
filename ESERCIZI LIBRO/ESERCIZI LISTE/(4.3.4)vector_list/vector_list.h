#if !defined VECTOR_LIST_H
#define VECTOR_LIST_H
#include "list.h"
enum ConversioneType {
	kInOrder,
	kReverse
};
extern Item* Vector2List(const ElemType* v, size_t v_size, enum ConversionType c);
extern ElemType* List2Vector(const Item* i, size_t* v_size, enum ConversionType c);
#endif //VECTOR_LIST_H