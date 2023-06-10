#if !defined SCIATORI_H
#define SCIATORI_H
typedef struct {
	double a;
	double l;
} Sciatore;
extern Sciatore* Accoppia(double* altezze, double* lunghezze, size_t v_size);
#endif //SCIATORE_H