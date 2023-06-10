#include <stdlib.h>
#include <stdio.h>
#include <float.h>
//definiamo una struct del mezzo 
struct mezzo {
	double consumo;
	int serbatoio;
};
struct mezzo moto = { 0.05,30 };

static void stazionconvRec(int i, int* vcurr,int* vbest, int* prezzolitro, int* distanza, int n,double consumodeltalitri,double prezzodelta,double *sommadenaro,double *max,double *serbatoioattuale) {
	
	if (i == n) {
		//controllo la situazione di questo caso 
		for (int j = 0; j < n; j++) {
			consumodeltalitri += distanza[j] * moto.consumo;
			serbatoioattuale[0] -= consumodeltalitri;

			//se si ferma alla stazione di servizio
			if (vcurr[j] == 1) {
				sommadenaro[0] += (consumodeltalitri * prezzolitro[j]);
				serbatoioattuale[0] = moto.serbatoio;
			}
			//primo filtro: stimiamo se riesce ad arrivare alla prossima stazione di servizio
			if (j != n - 1) {
				if (((moto.consumo * distanza[j + 1]) > (serbatoioattuale[0])) && (j != n)) {
					return;
				}
			}
			consumodeltalitri = 0;
		}
		//se la somma è minore diventa il vbest 
		if (serbatoioattuale[0] < 0) {
			return;
		}
		if (sommadenaro[0] < max[0]) {
			for (int j = 0; j < n; j++) {
				vbest[j] = vcurr[j];
			}
		}
		sommadenaro[0] = 0;
		return;
	}

	vcurr[i] = 1;
	stazionconvRec(i+1, vcurr,vbest, prezzolitro, distanza, n,0,0,sommadenaro, max, serbatoioattuale);
	vcurr[i] = 0;
	stazionconvRec(i+1, vcurr,vbest, prezzolitro, distanza, n,0,0,sommadenaro,max,serbatoioattuale);
	vcurr[i] = 0;
}

void stazioniconv(int* prezzolitro,int* distanza,int n) {
	if (prezzolitro == NULL || distanza == NULL || (n<0)) {
		return;
	}
	int* vcurr = malloc(n * sizeof(int));
	for (int j = 0; j < n; j++) {
		vcurr[j] = 0;
	}
	int *vbest = malloc(n * sizeof(int));
	vbest[0] = 0;
	double* max = malloc(1 * sizeof(int));
	max[0] = DBL_MAX;
	double* serbatoioattuale = malloc(1 * sizeof(int));
	serbatoioattuale[0] = moto.serbatoio;
	double* sommadenaro = malloc(1 * sizeof(int));
	sommadenaro[0] = 0;
	stazionconvRec(0, vcurr,vbest, prezzolitro, distanza, n,0,0,sommadenaro,max,serbatoioattuale);
	//parte in cui stampiamo
	for (int j = 0; j < n; j++) {
		printf("%d", vbest[j]);
	}
	return;
}