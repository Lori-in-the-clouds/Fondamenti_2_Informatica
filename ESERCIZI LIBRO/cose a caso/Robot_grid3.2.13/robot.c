#include <stdlib.h>
#include <stdio.h>
#include "robot.h"
#include <stdbool.h>

int PrintGrind(const struct Grid* g) {
	//stampiamo prima linea
	printf(" +---");
	for (size_t c = 0; c < g->cols-2; c++) {
		printf("+---");
	}
		printf("+---+\n");
	//stampiamo il corpo
		int cont = 0;
		for (size_t r = 0; r < g->rows+1; r++) {
			if (cont != 0) {
				printf(" | \n +---");
				for (size_t c = 0; c < g->cols - 2; c++) {
					printf("+---");
				}
				printf("+---+\n");
			}
			if (r == g->rows) {
				break;
			}
			cont++;
			for (size_t c = 0; c < g->cols; c++) {
				printf(" | ");
				if (g->cells[r * g->cols + c] == 0) {
					printf("0");
				}
				if (g->cells[r * g->cols + c] == -1) {
					printf("B");
				}
				if (g->cells[r * g->cols + c] != 0 && g->cells[r * g->cols + c]!=-1) {
					printf("%i", g->cells[r * g->cols + c]);
				}
			}
		}
}
void FindPathsRec(const struct Grid* g, int c, int r,int gps) {
	if (g->cells[(g->cols * g->rows) - 1] != 0) {
		PrintGrind(g);
		g->cells[(g->cols * g->rows)- 1] = 0;
		return;
	}


	if ((c < g->cols - 1) && g->cells[r * g->cols + c + 1] != -1) {
		g->cells[r * g->cols + c+1] = gps;
		FindPathsRec(g, c + 1, r,gps+1);
		g->cells[r * g->cols + c + 1] = 0;
	}
	if ((r < g->rows - 1) && g->cells[(r + 1) * g->cols + c]!=-1) {
		g->cells[(r+1)*g->cols+c] = gps;
		FindPathsRec(g, c, r + 1,gps+1);
		g->cells[r * g->cols + c + 1] = 0;
	}
	

}
int FindPaths(const struct Grid* g) {
	g->cells[0] = 1;
	int gps = 2;
	
	

	FindPathsRec(g,0,0,gps);
}


