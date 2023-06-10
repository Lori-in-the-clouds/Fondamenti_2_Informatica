#include <stdlib.h>
typedef struct {
	int profit;
	int duration;
	int deadline;
} job;
extern int ScheduleJobs(const job* jobs, size_t j_size);
int main(void) {
	job c[] = { {.duration = 2,.profit = 80,.deadline = 4},{.duration = 5,.profit = 100,.deadline = 6},{.duration = 1,.profit = 30,.deadline = 3} };
	ScheduleJobs(c, sizeof(c) / sizeof(job));
}