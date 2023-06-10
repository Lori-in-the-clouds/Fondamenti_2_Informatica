#include "prezzo.h"
#include <stdlib.h>
int main(void) {
	struct Articolo a[] = { {.nome = "Monopoli",.prezzo = 20},{.nome = "Carcassone",.prezzo = 30}, {.nome = "Perudo",.prezzo = 20} };
	TrovaArticoli(a, 3, 50);
}