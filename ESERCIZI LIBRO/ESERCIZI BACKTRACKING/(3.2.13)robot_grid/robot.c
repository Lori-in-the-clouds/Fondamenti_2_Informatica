#include "robot.h"
#include <stdlib.h>
#include <stdio.h>
void PrintGrid(const struct Grid* g) {
	printf(" +");
	for (int i = 0; i < g->cols; i++) {
		printf(("---+"));
	}
	printf("\n");
	for (int r = 0; r < g->rows; r++) {
		for (int c = 0; c < g->cols; c++) {
			if (g->cell[g->cols * r + c]=='B') printf(" | %c",(char)g->cell[g->cols * r + c]);
			 else printf(" | %d",g->cell[g->cols*r + c]);
		}
		printf(" |\n +");
		for (int i = 0; i < g->cols; i++) {
			printf(("---+"));
		}
		printf("\n");
	}
	return;
}

void FindPathsRec(struct Grid* g, int i,int r,int c,int *nsol) {
	if (g->cell[g->rows * g->cols -1] != 0) {
		PrintGrid(g);
		(*nsol)++;
		return;
	}
	if (g->cell[g->cols * r + c + 1] != 'B' && (c < g->cols)) {
		g->cell[g->cols * r + c + 1] = i + 1;
		FindPathsRec(g, i + 1, r, c + 1,nsol);
		g->cell[g->cols * r + c + 1] = 0;
	}
	if (g->cell[g->cols * (r + 1) + c] != 'B' && (r < g->rows)) {
		g->cell[g->cols * (r + 1) + c] = i + 1;
		FindPathsRec(g, i + 1, r + 1, c,nsol);
		g->cell[g->cols * (r + 1) + c] = 0;
	}
}
int FindPaths(const struct Grid* g) {
	int* nsol = 0;
	g->cell[0] = 1;
	FindPathsRec(g, 1,0,0,&nsol);
	return nsol;
}