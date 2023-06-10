#if !defined VETTORE_H
#define VETTORE_H
struct vettore {
	int* data;
	size_t size;
};
extern void Push(struct vettore* v, int d);
extern int Pop(struct vettore* v);
#endif //VETTORE_H