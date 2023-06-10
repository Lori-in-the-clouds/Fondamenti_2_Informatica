#if !defined TORRECARTONI_H
#define TORRECARTONI_H
typedef struct {
	unsigned p;
	unsigned a;
	unsigned l;
} Cartone;
extern void TorreCartoni(const Cartone* c, size_t n);
#endif //TORRECARTONI_H