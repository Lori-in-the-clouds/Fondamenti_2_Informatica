#if !defined ROBOT_H
#define ROBOT_H
struct Grid {
	size_t rows, cols;
	int* cell;
};
extern int FindPaths(const struct Grid* g);
extern void PrintGrid(const struct Grid* g);
#endif //ROBOT_H
