#define _CRT_SECURE_NO_WARNINGS
#include "prezzo.h"
int main(void) {
	struct Articolo p[] = {
		{.nome = "Monopoli",.prezzo = 20 },
		{.nome = "Carcassone",.prezzo = 30 },
		{.nome = "Perudo",.prezzo = 20 },
		{.nome = "Cluedo",.prezzo = 45 },
		{.nome = "Risiko",.prezzo = 5 }
	};
	
	TrovaArticoli(p, 5, 50);
}