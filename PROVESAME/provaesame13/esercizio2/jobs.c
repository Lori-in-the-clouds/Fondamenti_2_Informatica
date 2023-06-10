#include  <stdlib.h>
#include <string.h>
#include <stdio.h>
typedef struct {
	int profit;
	int duration;
	int deadline;
} job;
int comp(const void* a,const void* b) {
	const job* arg1 = (const job*)a;
	const job* arg2 = (const job*)b;
	if ((arg1->profit / arg1->duration) < (arg2->profit / arg2->duration)) return 1;
	if ((arg1->profit / arg1->duration) < (arg2->profit / arg2->duration)) return -1;
	return 0;
}
int comp1(const void* a,const void* b) {
	const job* arg1 = (const job*)a;
	const job* arg2 = (const job*)b;
	if ((arg1->profit / arg1->duration) == (arg2->profit / arg2->duration)) {
		if (arg1->duration < arg2->duration) return -1;
		if (arg1->duration > arg2->duration) return 1;
	}
	return 1;
}
int ScheduleJobs(const job* jobs, size_t j_size) {
	job* h1 = malloc(j_size * sizeof(job));
	job* h2 = malloc(j_size * sizeof(job));
	memcpy(h1, jobs, j_size * sizeof(job));
	memcpy(h2, jobs, j_size * sizeof(job));
	qsort(h1, j_size, sizeof(job), comp);
	qsort(h1, j_size, sizeof(job), comp1);
	int* parz = calloc(j_size , sizeof(job));
	for (int j = 0; j < (int)j_size; j++) parz[j] = -1;
	int som = 0;
	for (int i = 0; i < (int)j_size; i++) {
		if (som + h1[i].duration <= h1[i].deadline) {
			parz[i] = i;
			som += h1[i].duration;
		}
	}
	int size = 1;
	int* ris = malloc(sizeof(int));
	int m = 0;
	int result = 0;
	for (int i = 0; i < (int)j_size; i++) {
		if (parz[i] != -1) {
			for (int j = 0; j < (int)j_size; j++) {
				if (h1[parz[i]].profit == h2[j].profit && (h1[parz[i]].duration == h2[j].duration)) {
					ris[m] = j;
					ris = realloc(ris, (++size) * sizeof(int));
					m++;
					result += h1[parz[i]].profit;
				}
			}
		}
	}
	for (int j = 0; j < size - 1; j++) {
		fprintf(stdout,"%d ", ris[j]);
	}
	free(h1);
	free(h2);
	free(ris);
	free(parz);
	return result;
}