#include  <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
typedef struct {
	int profit;
	int duration;
	int deadline;
} job;
int comp(const void* a, const void* b) {
	const job* arg1 = (const job*)a;
	const job* arg2 = (const job*)b;
	if ((arg1->profit / arg1->duration) < (arg2->profit / arg2->duration)) return 1;
	if ((arg1->profit / arg1->duration) > (arg2->profit / arg2->duration)) return -1;
	if ((arg1->profit / arg1->duration) == (arg2->profit / arg2->duration)) {
		if (arg1->duration < arg2->duration) return -1;
		if (arg1->duration > arg2->duration) return 1;
		else return 0;
	}
}
int ScheduleJobs(const job* jobs, size_t j_size) {
	job* h = calloc(j_size, sizeof(job));
	memcpy(h, jobs, j_size * sizeof(job));
	qsort(h, j_size, sizeof(job), comp);
	bool* preso = calloc(j_size, sizeof(bool));
	int som = 0;
	int result = 0;
	for (int i = 0; i < (int)j_size; i++) {
		if (som + h[i].duration <= h[i].deadline) {
			preso[i] = true;
			som += h[i].duration;
			result += h[i].profit;
		}
	}
	for (int i = 0; i < (int)j_size; i++) {
		for (int j = 0; j < (int)j_size; j++) {
			if ((h[i].duration == jobs[j].duration && h[i].profit == jobs[j].profit && h[i].deadline == jobs[j].deadline) && preso[i] == true) {
				printf("%d ", j);
				break;
			}
		}
	}
	return result;
}