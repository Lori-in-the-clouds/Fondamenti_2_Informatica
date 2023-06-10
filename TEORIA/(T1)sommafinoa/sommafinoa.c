#include <stdlib.h>
int sommafinoa(int n) {
	if (n <= 0) {
		return -1;
	}
	sommafinoaRec(n);
}
static int sommafinoaRec(int n) {  
	//spezzo il tutto in due cos� � pi� veloce, e poi metto davanti static in questo modo non posso richiamarlo dal main 
	if (n == 1) {
		return 1;
	}
	else { //l'else � superfluo, meglio senza
		return sommafinoaRec(n - 1) + n;
	}
}
//cosa manca?
//manca la gestione del caso particolare n=0;


//VERSIONE TAIL
/*
static int sommafinoaRec(int n, int s) {  
	 
	if (n == 1) {
		return s+1;
	}
	else {
		return sommafinoaRec(n - 1,s + n);
	}
}*/
//meglio la versione tail, perche il compilatore pu0 tasformalo in iterattiva 