#if !defined MERGE_H
#define MERGE_H
#include "list.h"
enum MergeType {
	kcopy,
	kNoCopy
};
extern Item* OrderedMerge(Item* i1, Item* i2, enum MergeType m);
#endif //MERGE_H
