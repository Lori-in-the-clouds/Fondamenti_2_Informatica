#include "robot.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void PrintGrid(const struct Grid* g) {
	printf(" +");
	for (int i = 0; i < g->cols; i++) {
		printf(("---+"));
	}
	printf("\n");
	for (int r = 0; r < g->rows; r++) {
		for (int c = 0; c < g->cols; c++) {
			if (g->cell[g->cols * r + c] == 'B') printf(" | %c", (char)g->cell[g->cols * r + c]);
			else printf(" | %d", g->cell[g->cols * r + c]);
		}
		printf(" |\n +");
		for (int i = 0; i < g->cols; i++) {
			printf(("---+"));
		}
		printf("\n");
	}
	return;
}
void rec(struct Grid* p, int i, int* ris, int c, int r,int mosse) {
	if (p->cell[(p->rows * p->cols) - 1] == 1) {
		PrintGrid(p);
		printf("\n");
		(*ris)++;
		return;
	}
	if (mosse > 99) return;
	//MI MUOVO IN GIU
	if (r < p->rows - 1 && p->cell[i + p->cols] != 'B') {
		p->cell[i + p->cols] = 1;
		rec(p, i + p->cols, ris, c, r + 1,mosse+1);
		p->cell[i + p->cols] = 0;

	}
	//MI MUOVO A DESTRA
	if (c < p->cols - 1 && p->cell[i + 1]!='B') {
		p->cell[i + 1] = 1;
		rec(p, i + 1, ris, c + 1, r,mosse+1);
		p->cell[i + 1] = 0;
	}
}
int FindPaths(const struct Grid* g) {
	struct Grid p;
	p.cell = calloc(g->cols * g->cols, sizeof(int));
	p.cols = g->cols;
	p.rows = g->rows;
	memcpy(p.cell, g->cell, g->cols * g->cols * sizeof(int));
	int ris = 0;
	p.cell[0] = 1;
	rec(&p, 0, &ris, 0, 0,0);
	free(p.cell);
	return ris;
}