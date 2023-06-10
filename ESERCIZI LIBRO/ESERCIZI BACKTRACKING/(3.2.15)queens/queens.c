#include "queens.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
void PlaceQueensRec(int n_queens, const struct Matrix* tab, int i,int cont) {
	if (i == (tab->lato * tab->lato)) {
		if (cont != n_queens) return;
		for (int j = 0; j < i; j++) {
			if (tab->data[j] == 1) {
				//controlliamo la riga 
				int rows = j / tab->lato;
				for (int k = 0; k < tab->lato; k++) {
					if (tab->data[rows * tab->lato + k] == 1 && (rows * tab->lato + k) != j) return;
				}
				//controlliamo la colonna
				int m = j;
				while (m > tab->lato) m -= tab->lato;
				while (m < (tab->lato * tab->lato)) {
					if (tab->data[m] == 1 && (m) != j) return;
					m += tab->lato;
				}
				//troviamo le righe e le colonne 
				int r = j / tab->lato;
				int x = (tab->lato * tab->lato) - 1;
				int y = tab->lato - 1;
				int c = tab->lato -1;
				while (j > x) {
					x--;
					y--;
					c--;
				}
				//controlliamo le diagonali da sinistra a destra
				//1)troviamo la base 
				int r1 = r;
				m = j;
				if (r != 0) {
					while (r1 > 0) {  //attenzione
						m -= (tab->lato + 1);
						r1--;
					}
				}
				//2)controllo vero e proprio 
				int c1 = 0;
				while (c1 < tab->lato) {
					if (tab->data[m] == 1 && (m) != j) return;
					m += (tab->lato + 1);
					c1++;
				}
				//controlliamo le diagonali da destra a sinistra 
				//1)troviamo la base
				int r2 = r;
				m = j;
				if (c != tab->lato - 1) {
					while (r2 > 0) {
						m -= (tab->lato - 1);
						r2--;
					}
				}
				//2)controllo vero e proprio
				int c2 = c;
				while (c2 > 0) {  //attenzione
					if (tab->data[m] == 1 && (m) != j) return;
					m += (tab->lato - 1);
					c2--;
				}
			}
		}
		//stampiamo
		for (int j = 0; j < i; j++) {
				printf("[%d]", tab->data[j]);
				if ((j + 1) % tab->lato == 0) printf("\n");
		}
		printf("\n");
		return;
	}
	if (cont < n_queens) {
		tab->data[i] = 1;
		PlaceQueensRec(n_queens, tab, i + 1, cont + 1);
	}
		tab->data[i] = 0;
		PlaceQueensRec(n_queens, tab, i + 1,cont);
	}

int PlaceQueens(int chessboard_size, int n_queens) {
	struct Matrix p;
	p.lato = chessboard_size;
	p.data = calloc(p.lato, sizeof(int));
	PlaceQueensRec(n_queens, &p, 0,0);
	return 0;
}

