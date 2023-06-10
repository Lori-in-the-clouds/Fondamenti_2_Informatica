#include "tree.h"
#include <limits.h>
#include <math.h>
#include <stdint.h>
int MAX(int a, int b) {
    if (a >= b) return a;
    else return b;
}
void HeighLevel(const Node* t,int i,int *max) {
    if (TreeIsEmpty(t)) {
        if (i > *max) {
            *max = i;
        }
        return;
    }
    HeighLevel(TreeLeft(t),i + 1,max);
    HeighLevel(TreeRight(t), i + 1,max);
}
int Diameter(const Node* t) {
    if (TreeIsEmpty(t)) {
        return 0;
    }
    int sx = Diameter(TreeLeft(t));
    int dx = Diameter(TreeRight(t));
    int max1 = 1;
    int max2 = 1;
    HeighLevel(TreeLeft(t), 0, &max1);
    HeighLevel(TreeRight(t), 0, &max2);
    return MAX(MAX(sx, dx), max1 + max2 + 1);
}