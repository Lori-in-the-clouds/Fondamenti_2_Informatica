#include "list.h"
#include "minheap.h"
#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
//int rec1(int n) {
//
//    if (n== 0) {
//        return 0;
//    }
//
//    if (n == 1) {
//        return 1;
//    }
//    return rec(ceil(n / 2.)) + n;
//}
//int rec2(int n) {
//    if (n == 0) {
//        return 0;
//    }
//
//    if (n == 1) {
//        return 1;
//    }
//    return rec(round(n / 2.)) + n;
//}

int main(int argc, char **argv) {
    if (argc != 2) return 1;
    int n = atoi(argv[1]);
    if (n < 0) return 1;
 /*   printf("%d",rec1(n)+rec2(n));*/
    return 0;

}
