#include "prezzo.h"
#include <stdlib.h>
int main(void) {
	struct Articolo p[] = {
		{.nome = "Monopoli",.prezzo = 20 },
		{.nome = "Carcassone",.prezzo = 30 },
		{.nome = "Perudo",.prezzo = 20 },
		{.nome = "Cluedo",.prezzo = 45 },
		{.nome = "Risiko",.prezzo = 5 }
	};
	size_t size = sizeof(p) / sizeof(struct Articolo);
	TrovaArticoli(p, size, 50);
}