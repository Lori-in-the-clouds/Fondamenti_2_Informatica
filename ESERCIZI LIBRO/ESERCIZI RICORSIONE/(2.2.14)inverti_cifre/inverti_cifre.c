#include <math.h>
//PRIMO METODO
//void InvertiCifreRec(int or,int n,int i,int *ris,int len) {
//	if (n == 0) {
//		return;
//	}
//	int m = or / pow(10, i);
//	ris[0] += (m % 10) * pow(10, len-i);
//	InvertiCifreRec(or,m % 10, i + 1, ris,len);
//}

//int InvertiCifre(int n) {
//	int ris = 0;
//	int m = n;
//	int j = 0;
//	while (m != 0) {
//		m = m / 10;
//		j++;
//	}
//	InvertiCifreRec(n,n,0,&ris,j-1);
//	return ris;
//}

int InvertiCifreRec(int n, int n_prev) {
	if (n == 0) {
		return n_prev;
	}
	InvertiCifreRec(n / 10, n_prev * 10 + n % 10);
}
int InvertiCifre(int n) {
	InvertiCifreRec(n, 0);
}