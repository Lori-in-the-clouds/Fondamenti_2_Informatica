#include <stdlib.h>
#include <stdio.h>
void BabboNataleRec(int i, int* vcurr, int* vbest, int* min,int sum,int cont, const int* pacchi, size_t pacchi_size, int p,int*cbest) {
	//primo filtro 
	for (int j = 0; j < i; j++) {
		if (vcurr[j] == 1) {
			sum += pacchi[j];
			cont++;
		}
	}
	if (sum >= p) {
		return;
	}
	//taglio finale
	if (i == pacchi_size) {
		if ((cont >= cbest[0])) {
			//controll se il peso si eguaglia 
				cbest[0] = cont;
				for (int j = 0; j < pacchi_size; j++) {
					vbest[j] = vcurr[j];
				}

				if (cont == cbest[0]) {
					if ((p - sum) < min[0]) {
						(min[0]) = p - sum;
						for (int j = 0; j < pacchi_size; j++) {
							vbest[j] = vcurr[j];
						}

					}
				}
			}
			return;
		
	}
	//creiamo l'albero
	vcurr[i] = 1;
	BabboNataleRec(i + 1,vcurr, vbest, min, 0,0,pacchi, pacchi_size, p,cbest);
	vcurr[i] = 0;
	BabboNataleRec(i + 1,vcurr, vbest, min, 0,0,pacchi, pacchi_size, p,cbest);
	vcurr[i] = 0;
}
void BabboNatale(const int* pacchi, size_t pacchi_size, int p) {
	if ((pacchi == NULL) || (pacchi_size <= 0) || (p < 0)) {
		return 0;
	}
	int* vcurr = malloc(pacchi_size * sizeof(int));
	int* vbest = malloc(pacchi_size * sizeof(int));
	int* min = p;
	int* cbest = 0;
	BabboNataleRec(0, vcurr, vbest, &min,0,0, pacchi, pacchi_size, p,&cbest);
	free(vcurr);
	for (int j = 0; j < pacchi_size; j++) {
			printf("%d ", vbest[j]);
		}
	printf("\n");
	free(vbest);

	return;
}