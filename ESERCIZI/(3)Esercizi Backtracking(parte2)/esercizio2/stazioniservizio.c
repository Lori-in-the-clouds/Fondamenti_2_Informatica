#include <stdlib.h>
#include <stdio.h>
#include <float.h>
//definiamo una struct del mezzo 
struct mezzo {
	double consumo;
	double serbatoio;
};
struct mezzo moto = { 0.05,30. };

static void StazioniServizioRec(size_t i, int* vcurr, int* vbest,const double* prezzolitro,const double* distanza, size_t n, double consumodeltalitri,double sommadenaro, double* max, double* serbatoioattuale, double *sommabest,double totdistanza,double m,int* ctr) {

	if (i == n) {
		//controllo la situazione di questo caso 
		for (size_t j = 0; j < n; j++) {
			consumodeltalitri += distanza[j] * moto.consumo;
			serbatoioattuale[0] -= consumodeltalitri;
			totdistanza += distanza[j];
			//arriverà alla prossima stazione di servizio?
			if (serbatoioattuale[0] < 0) {
				serbatoioattuale[0] = moto.serbatoio; 
				return;
			}
			//se si ferma alla stazione di servizio
			if (vcurr[j] == 1) {
				sommadenaro += ((moto.serbatoio - serbatoioattuale[0]) * prezzolitro[j]);
				serbatoioattuale[0] = moto.serbatoio;
			}
			consumodeltalitri = 0;
			//quando arriva all'ultima stazione riuscirà ad arrivare alla fine del tragitto?
			if (j == n - 1) {
				if ((m - totdistanza) >= (  serbatoioattuale[0] / moto.consumo)) {
					return;
				}
			}
		}
			
		if (sommadenaro < max[0]) {
			for (size_t j = 0; j < n; j++) {
				vbest[j] = vcurr[j];
			}
			sommabest[0] = sommadenaro;
			max[0] = sommabest[0];
			//controllo se esistono soluzioni
			(*ctr)++;
		}
		return;
	}
	vcurr[i] = 1;
	StazioniServizioRec(i + 1, vcurr, vbest, prezzolitro, distanza, n, 0, 0,max, serbatoioattuale,sommabest,0,m,ctr);
	vcurr[i] = 0;
	StazioniServizioRec(i + 1, vcurr, vbest, prezzolitro, distanza, n, 0, 0,max, serbatoioattuale,sommabest,0,m,ctr);
	vcurr[i] = 0;
}

void StazioniServizio(double m, const double* d, const double* p, size_t n) {
	if (d == NULL || p == NULL) {
		return;
	}
	int* vcurr = malloc(n * sizeof(int));
	for (size_t j = 0; j < n; j++) {
		vcurr[j] = 0;
	}
	int* vbest = malloc(n * sizeof(int));
	vbest[0] = 0;
	double* max = malloc(2 * sizeof(int));
	max[0] = DBL_MAX;
	double* serbatoioattuale = malloc(2 * sizeof(int));
	serbatoioattuale[0] = moto.serbatoio;
	double* sommabest = malloc(2 * sizeof(int));
	sommabest[0] = 0;
	int* ctr = malloc(1 * sizeof(int));
	ctr[0] = 0;
	
	//controlliamo fino a quante stazioni di servizio devo percorrere per arrivare a tot kilometri 
	double sum = 0;
	for (size_t i = 0; i < n; i++) {
		sum += d[i];
		if (sum > m) {
			n = i-1;
			break;
		}
	}
	StazioniServizioRec(0, vcurr, vbest, p, d, n, 0, 0,max, serbatoioattuale,sommabest,0,m,ctr);
	//se non esistono soluzioni
	if (ctr[0] == 0) {
		printf("Non esistono soluzioni");
		return;
	}
	
	//parte in cui stampiamo
	for (size_t j = 0; j < n; j++) {
		if (vbest[j] == 1) {
			printf("%ld ", j);
		}
	}
	printf("\n");
	printf("Spesa totale: %f euro", sommabest[0]);
	free(vcurr);
	free(vbest);
	free(ctr);
	free(max);
	free(serbatoioattuale);
	free(sommabest);
	return;
}