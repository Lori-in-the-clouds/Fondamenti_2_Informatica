#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
typedef struct {
	int profit;
	int duration;
	int deadline;
} job;
int comp(const void* a, const void* b) {
	job arg1 = *(const job*)a;
	job arg2 = *(const job*)b;
	double ris1 = arg1.profit / arg1.duration;
	double ris2 = arg2.profit / arg2.duration;
	if (ris1 < ris2) return 1;
	if (ris1 > ris2) return -1;
	if (ris1 == ris2) {
		if (arg1.duration < arg2.duration) return -1;
		if (arg1.duration > arg2.duration) return 1;
		return 0;
	}
}
int ScheduleJobs(const job* jobs, size_t j_size) {
	if (j_size <= 0) return 0;
	job* current = calloc(j_size, sizeof(job));
	memcpy(current, jobs, j_size * sizeof(job));
	qsort(current, j_size, sizeof(job), comp);
	int temp = 0;
	int ris = 0;
	for (size_t j = 0; j < j_size; j++) { 
		if (temp + current[j].duration <= current[j].deadline) {
			for (size_t s = 0; s < j_size; s++) {
				if (current[j].deadline == jobs[s].deadline && current[j].profit == jobs[s].profit && current[j].duration == jobs[s].duration) {
					printf("%d ", s);
				}
			}
			ris += current[j].profit;
			temp += current[j].duration;
		}
	}
	free(current);
	return ris;
}