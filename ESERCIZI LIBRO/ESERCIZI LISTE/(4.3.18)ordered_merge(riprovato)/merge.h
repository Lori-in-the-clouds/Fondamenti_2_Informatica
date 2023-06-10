#if !defined ORDERED_MERGE_H
#define ORDERED_MERGE_H

#include "elemtype.h"
#include "list.h"
enum MergeType {
	kCopy,
	kNoCopy
};
extern Item* Orderedmerge(Item* i1, Item* i2, enum MergeType m);
#endif //ORDERED_MERGE_H