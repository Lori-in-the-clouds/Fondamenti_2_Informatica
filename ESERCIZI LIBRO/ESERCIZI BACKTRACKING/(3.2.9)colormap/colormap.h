#if !defined COLORMAP_H
#define COLORMAP_H
#include  <stdbool.h>
#include <stdlib.h>
struct SquareMatrix {
	size_t side;
	bool* data;
};
extern int ColorMap(const struct SquareMatrix* m, const char* c);
#endif //COLORMAP_H