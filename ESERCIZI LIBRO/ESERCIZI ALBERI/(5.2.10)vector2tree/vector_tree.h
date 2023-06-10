#if !defined VECTOR_TREE_H
#define VECTOR_TREE_H
#include "tree.h"
enum TreeType {
	kZeroBased,
	kOneBased
};
extern Node* Vector2Tree(const ElemType* v, size_t v_size, enum TreeType type);
#endif //VECTOR_TREE_H