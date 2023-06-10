#include <stdlib.h>
#include "nonograms.h"
void SetLineConstraints(int*** dst_constr, size_t* dst_size, const int* src_constr, size_t src_size) {
	*dst_size = 0;
	*dst_constr = NULL;
	for (int j = 0; j < (int)src_size;) {
		(*dst_size)++;
		*dst_constr = realloc(*dst_constr, *dst_size * sizeof(int*));
		int id = *dst_size - 1;
		(*dst_constr)[id] = NULL;
		size_t curr_size = 0;
		do {
			curr_size++;
			(*dst_constr)[id] = realloc((*dst_constr)[id], sizeof(int) * curr_size);
			(*dst_constr)[id][curr_size - 1] = src_constr[j];
			j++;
		} while (src_constr[j - 1] != -1);
	}
}
Constraints* SetConstraints(const int* r_constr, size_t r_constr_size, const int* c_constr, size_t c_constr_size) {
	Constraints* constr = malloc(sizeof(Constraints));
	SetLineConstraints(&constr->r_constr,&constr->rows,r_constr,r_constr_size);
	SetLineConstraints(&constr->c_constr, &constr->cols, c_constr, c_constr_size);
	return constr;
}

int main(void) {
	//int r_constr[] = {1,1,-1,1,1,-1,7,-1,2,3,2,-1,11,-1,1,7,1,-1,1,1,1,1,-1,2,2,-1};
	//int c_constr[] = {3,-1,2,-1,1,5,-1,2,2,1,-1,4,1,-1,4,-1,4,1,-1,2,2,1,-1,1,5,-1,2,-1,3,-1 };
	/*int r_constr[] = {2,-1,1,-1};
	int c_constr[] = {1,-1,2,-1};*/
	int r_constr[] = { 2,-1,2,-1,1,-1 };
	int c_constr[] = { 1,1,-1,2,-1,1,-1 };
	Constraints* constr;
	constr = SetConstraints(r_constr, sizeof(r_constr) / sizeof(int), c_constr, sizeof(c_constr) / sizeof(int));
	Nonogram(constr);
}
