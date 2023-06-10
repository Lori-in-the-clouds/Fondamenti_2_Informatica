#include "list.h"
#include <stdlib.h>
extern Item* CreaDaInterni(const Item* i, double r);
typedef struct {
    int x;
    int y;
} Point2D;

typedef Point2D ElemType;
int main(void) {
    ElemType* e = malloc(sizeof(ElemType));
    e[0].x = 0;
    e[0].y = 0;
}