#if !defined ALPINE_ROAD_H
#define ALPINE_ROAD_H
typedef struct {
	int s, h;
} Point;
extern int FindPath(const Point* p, size_t p_size, int dh);
#endif //ALPINE_ROAD_H