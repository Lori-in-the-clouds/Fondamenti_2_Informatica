#ifndef TORRE_CARTONI_H_
#define TORRE_CARTONI_H_

#include <stdint.h>

typedef struct {
	unsigned p; // Peso
	unsigned a; // Altezza
	unsigned l; // Limite
} Cartone;

typedef struct {
	unsigned a;    // Altezza della torre
	int *c_ids;	   // Vettore di Cartoni (id) --> 0, 2, 1 significa che la torre è costruita con i
				   // cartoni in posizione 0, 2 e 1
	int c_size;	   // Dimensione di c_ids
	unsigned peso; // Peso della torre (somma dei pesi dei cartoni caricati attualmente)
} Torre;

extern void TorreCartoni(const Cartone *c, size_t n);

#endif // TORRE_CARTONI_H_
