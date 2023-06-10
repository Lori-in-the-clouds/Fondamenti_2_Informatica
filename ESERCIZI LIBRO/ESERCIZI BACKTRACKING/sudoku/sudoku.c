#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "sudoku.h"
void PrintSudoku(Matrix* p) {
	printf("+---+---+---++---+---+---++---+---+---+\n");
	int k = 0;
	for (int i = 0; i < 9; i++) {
		printf("|");
		for (int j = 0; j < 9; j++) {
			if (j == 3 || j == 6) printf("|");
			printf(" %d |", p->data[k]);
			k++;
		}
		printf("\n");
		if (i==2 || i==5) printf("+---+---+---++---+---+---++---+---+---+\n");
		printf("+---+---+---++---+---+---++---+---+---+\n");
	}
	printf("\n\n");
}
bool verifica(Matrix* p,int c, int r,int candidato,int i) {
	//controlliamo la riga 
	for (int cols = 0; cols < 9; cols++) {
		if (p->data[(r * 9) + cols] == candidato && (((r * 9) + cols) != i)) return false;
	}
	//contolliamo la collonna
	for (int rows = 0; rows < 9; rows++) {
		if (p->data[c + (rows * 9)] == candidato && ((c + (rows * 9)) != i)) return false;
	}
	//controlliamo i riquadri
	if (r < 3 && c < 3) {
		for (int rows = 0; rows < 3; rows++) {
			for (int cols = 0; cols < 3; cols++) {
				if (p->data[(rows * 9) + cols] == candidato && (((rows * 9) + cols) != i)) return false;
			}
		}
	}
	if ((c >= 3 && c < 6) && r < 3) {
		for (int rows = 0; rows < 3; rows++) {
			for (int cols = 3; cols < 6; cols++) {
				if (p->data[(rows * 9) + cols] == candidato && (((rows * 9) + cols) != i)) return false;
			}
		}
	}
	if (c >= 6  && r < 3) {
		for (int rows = 0; rows < 3; rows++) {
			for (int cols = 6; cols < 9; cols++) {
				if (p->data[(rows * 9) + cols] == candidato && (((rows * 9) + cols) != i)) return false;
			}
		}
	}
	if (c < 3 && (r > 3 && r < 6)) {
		for (int rows = 3; rows < 6; rows++) {
			for (int cols = 0; cols < 3; cols++) {
				if (p->data[(rows * 9) + cols] == candidato && (((rows * 9) + cols) != i)) return false;
			}
		}
	}
	if ((c >= 3 && c < 6) && (r > 3 && r < 6)) {
		for (int rows = 3; rows < 6; rows++) {
			for (int cols = 3; cols < 6; cols++) {
				if (p->data[(rows * 9) + cols] == candidato && (((rows * 9) + cols) != i)) return false;
			}
		}
	}
	if (c >= 6 && (r > 3 && r < 6)) {
		for (int rows = 3; rows < 6; rows++) {
			for (int cols = 6; cols < 9; cols++) {
				if (p->data[(rows * 9) + cols] == candidato && (((rows * 9) + cols) != i)) return false;
			}
		}
	}
	if (c < 3 && (r > 6 && r < 9)) {
		for (int rows = 6; rows < 9; rows++) {
			for (int cols = 0; cols < 3; cols++) {
				if (p->data[(rows * 9) + cols] == candidato && (((rows * 9) + cols) != i)) return false;
			}
		}
	}
	if ((c >= 3 && c < 6) && (r > 6 && r < 9)) {
		for (int rows = 6; rows < 9; rows++) {
			for (int cols = 3; cols < 6; cols++) {
				if (p->data[(rows * 9) + cols] == candidato && (((rows * 9) + cols) != i)) return false;
			}
		}
	}
	if (c > 6 && (r > 6 && r < 9)) {
		for (int rows = 6; rows < 9; rows++) {
			for (int cols = 6; cols < 9; cols++) {
				if (p->data[(rows * 9) + cols] == candidato && (((rows * 9) + cols) != i)) return false;
			}
		}
	}
	return true;
}
void ResolveSudokuRec(Matrix* p,int i,int c,int r,Matrix *p1) {
	if (i == 81) {
		PrintSudoku(p1);
		printf("Soluzione trovata:\n");
		PrintSudoku(p);
		return;
	}
	int c1 = c + 1;
	int r1 = r;
	if (c1 == 9) {
		c1 = 0;
		r1 = r + 1;
	}
	if (p->data[i] == 0) {
		for (int j = 1; j < 10; j++) {
			p->data[i] = j;
			if (verifica(p, c, r, j,i) == true) {
				ResolveSudokuRec(p, i + 1, c1, r1,p1);
			}
			p->data[i] = 0;
		}
	}
	else {
		ResolveSudokuRec(p, i + 1, c1, r1,p1);
	}
	return; //nel caso non riesca a trovare nessuna combinazione giusta 
}
void ResolveSudoku(Matrix* p) {
	Matrix p1;
	p1.data = malloc(81 * sizeof(int));
	p1.size = 81;
	memcpy(p1.data, p->data, 81 * sizeof(int));
	ResolveSudokuRec(p,0,0,0,&p1);
	free(p1.data);
	return;
}
		