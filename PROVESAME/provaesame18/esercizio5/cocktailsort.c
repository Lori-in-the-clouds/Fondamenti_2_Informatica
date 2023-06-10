#include <stdlib.h>
#include <stdbool.h>
 void CocktailSort(int* v, size_t v_size) {
	 int start = 0;
	 int end = v_size - 1;
	 while (end > start) {
		 bool mod1 = false;
		 bool mod2 = false;
		 for (int i = start; i < end; i++) {
			 if (v[i] > v[i + 1]) {
				 //scambio
				 int cmp = v[i + 1];
				 v[i + 1] = v[i];
				 v[i] = cmp;
				 mod1 = true;
			 }
		 }
		 end--;
		 for (int i = end; i > start; i--) {
			 if (v[i] < v[i - 1]) {
				 //scambio
				 int cmp = v[i - 1];
				 v[i - 1] = v[i];
				 v[i] = cmp;
				 mod2 = true;
			 }
		 }
		 start++;
		 if (!mod1 && !mod2) break;
	 }
	 return;
}
