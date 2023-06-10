#include "robot_mod.h"
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
			if (g->cells[g->cols * r + c] == 'B') printf(" | %c", (char)g->cells[g->cols * r + c]);
			else printf(" | %d", g->cells[g->cols * r + c]);
		}
		printf(" |\n +");
		for (int i = 0; i < g->cols; i++) {
			printf(("---+"));
		}
		printf("\n");
	}
	return;
}

void FindPathsRec(struct Grid* g, int i, int r, int c, int* nsol,int max_moves) {
	if (g->cells[g->rows * g->cols - 1] != 0) {
		PrintGrid(g);
		(*nsol)++;
		return;
	}
	if (max_moves == 0) {
		return;
	}
	if (g->cells[g->cols * r + c + 1] == 0 && (c < g->cols)) {
		g->cells[g->cols * r + c + 1] = i + 1;
		FindPathsRec(g, i + 1, r, c + 1, nsol, max_moves-1);
		g->cells[g->cols * r + c + 1] = 0;
	}
	if (g->cells[g->cols * (r + 1) + c] == 0 && (r < g->rows)) {
		g->cells[g->cols * (r + 1) + c] = i + 1;
		FindPathsRec(g, i + 1, r + 1, c, nsol, max_moves-1);
		g->cells[g->cols * (r + 1) + c] = 0;
	}
	if (g->cells[g->cols * (r - 1) + c] == 0 && (r > 0)) {
		g->cells[g->cols * (r - 1) + c] = i + 1;
		FindPathsRec(g, i + 1, r - 1, c, nsol, max_moves-1);
		g->cells[g->cols * (r - 1) + c] = 0;
	}
}
int FindPaths(const struct Grid* g,int max_moves) {
	int* nsol = 0;
	g->cells[0] = 1;
	FindPathsRec(g, 1, 0, 0, &nsol,max_moves);
	return nsol;
}