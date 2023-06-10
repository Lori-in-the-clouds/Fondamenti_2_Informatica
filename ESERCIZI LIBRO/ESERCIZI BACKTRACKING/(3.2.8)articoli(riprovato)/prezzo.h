#if !defined PREZZO_H
#define PREZZO_H
struct Articolo {
	char nome[11];
	int prezzo;
};
#include <stdlib.h>
extern void TrovaArticoli(const struct Articolo* a, size_t a_size, int sum);
#endif //PREZZO_H