#include "torrecartoni.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

void TorreCartoniRec(int n, const Cartone *c, int i, Torre *vcurr, Torre *vbest, bool *usati) {

    if (i == n) {
        if (vcurr->a > vbest->a) {
            vbest->a = vcurr->a;
            vbest->peso = vcurr->peso;
            memcpy(vbest->c_ids, vcurr->c_ids, sizeof(int) * vcurr->c_size);
            vbest->c_size = vcurr->c_size;
        }
        return;
    }
    bool presi = false;
    for (int j = 0; j < n; ++j) {
        if (!usati[j] && c[j].l >= vcurr->peso) {
            presi = true;
            vcurr->a += c[j].a;
            vcurr->peso += c[j].p;
            vcurr->c_ids[vcurr->c_size] = j;
            vcurr->c_size++;

            usati[j] = true;

            TorreCartoniRec(n, c, i + 1, vcurr, vbest, usati);

            vcurr->a -= c[j].a;
            vcurr->peso -= c[j].p;
            vcurr->c_size--;

            usati[j] = false;
        }

    }

    if (!presi) {
        TorreCartoniRec(n, c, n, vcurr, vbest, usati);
    }
}

void TorreCartoni(const Cartone *c, size_t n) {
    bool *usati = calloc(n, sizeof(bool));
    Torre vcurr = { .a = 0, .c_ids = malloc(n * sizeof(int)), .c_size = 0, .peso = 0 };
    Torre vbest = { .a = 0, .c_ids = malloc(n * sizeof(int)), .c_size = 0, .peso = 0 };

    TorreCartoniRec((int)n, c, 0, &vcurr, &vbest, usati);

    for (int i = 0; i < vbest.c_size; ++i) {
        printf("%d\n", vbest.c_ids[i]);
    }
    printf("Altezza: %d cm", vbest.a);

    // Libero la memoria
    free(vcurr.c_ids);
    free(vbest.c_ids);
    free(usati);
}


