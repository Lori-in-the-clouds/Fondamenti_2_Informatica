#include "nonograms.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct {
	size_t rows, cols;
	int* data;
} Matrix;

void StampaMatrix(Matrix* p) {
	for (int r = 0; r < p->rows; r++) {
		for (int c = 0; c < p->cols; c++) {
			printf("%d", p->data[r * p->cols + c]);
		}
		printf("\n");
	}
	printf("\n");
	return;
}
//void NonogramRec(const Constraints* constr, Matrix* p, int i) {
//	
//	if (i == (p->cols * p->rows)) {
//		//controlliamo le righe 
//		bool control = false;
//		int rigas = 0;
//		for (int r = 0; r < p->rows; r++) {
//			int k = 0;
//			int cont = 0;
//			//controlliamo se la riga è tutti zero 
//			for (int c = 0; c < p->cols; c++) {
//				if (p->data[r * p->cols + c] == 1) {
//					control = true;
//					break;
//				}
//			}
//			if (!control && constr->r_constr[rigas][0] != -1) return;
//				control = false;
//			for (int c = 0; c < p->cols; c++) {
//				while (p->data[r * p->cols + c] == 1 && c < p->cols) {
//					cont++;
//					control = true;
//					c++;
//				}
//				if (control) {
//					control = false;
//					if (cont == constr->r_constr[rigas][k]) {
//						cont = 0;
//						k++;
//						c--;
//					}
//					else return;
//				}
//			}
//			rigas++;
//		}
//		//controlliamo le colonne
//		control = false;
//		int colonas = 0;
//		for (int c = 0; c < p->cols; c++) {
//			int k = 0;
//			int cont = 0;
//			//controlliamo se la colonna è tutti zero 
//			for (int r = 0; r < p->rows; r++) {
//				if (p->data[r * p->cols + c] == 1) {
//					control = true;
//					break;
//				}
//			}
//			if (!control && constr->c_constr[colonas][0] != -1) return;
//			control = false;
//			for (int r = 0; r < p->rows; r++) {
//				while (p->data[r * p->cols + c] == 1 && r < p->rows) {
//					cont++;
//					control = true;
//					r++;
//				
//				}
//				if (control) {
//					control = false;
//					if (cont == constr->c_constr[colonas][k]) {
//						cont = 0;
//						k++;
//						r--;
//					}
//					else return;
//				}
//			}
//			colonas++;
//		}
//		StampaMatrix(p);
//		return;
//	}
//	for (int j = 0; j <=1; j++) {
//		p->data[i] = j;
//		NonogramRec(constr, p, i + 1);
//	}
//}
bool Verifica(const Constraints* constr, Matrix* p,int r1,int c1,int i) {
	//controlliamo la riga 
	int cont = 0;
	for (int c = 0; c < p->cols; c++) {
		while (p->data[r1 * p->cols + c] == 1) {
			cont++;
			c++;
		}
		if (cont > constr->r_constr[r1][c]) return false;
	
	}
}
void NonogramRec(const Constraints* constr, Matrix* p, int i) {
	int c1 = i % constr->cols;
	int r1 = i / constr->cols;
	if (i == p->cols * p->rows) {
		StampaMatrix(p);
		return;
	}
	p->data[i] = 1;
	if (Verifica(constr, p, r1, c1,i)) {//verifica
		NonogramRec(constr, p, i + 1);
	}
	p->data[i] = 0;
	if (Verifica(constr, p, r1, c1,i)) {//verifica
		NonogramRec(constr, p, i + 1);
	}
}
void Nonogram(const Constraints* constr) {
	Matrix p;
	p.cols = constr->cols;
	p.rows = constr->rows;
	p.data = calloc(p.cols * p.rows, sizeof(int));
	/*p.data[0] = 1;
	p.data[1] = 1;
	p.data[2] = 0;
	p.data[3] = 0;*/
	NonogramRec(constr, &p,0);
}