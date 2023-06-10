#if !defined ROBOT_H
#define ROBOT_H
#include <stdlib.h>
struct Grid {
	size_t rows, cols;
	int* cells;
};
extern int FindPaths(const struct Grid* g);
extern int PrintGrind(const struct Grid* g);
#endif //ROBOT_H