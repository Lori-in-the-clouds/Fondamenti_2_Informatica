#include  <stdlib.h>
typedef struct {
	int profit;
	int duration;
	int deadline;
} job;
extern int ScheduleJobs(const job* jobs, size_t j_size);
int main(void) {
	job* p = malloc(3 * sizeof(job));
	p[0].profit = 50;
	p[0].duration = 2;
	p[0].deadline = 4;

	p[1].profit = 130;
	p[1].duration = 4;
	p[1].deadline = 25;

	p[2].profit = 35;
	p[2].duration = 1;
	p[2].deadline = 3;

	p[3].profit = 50;
	p[3].duration = 8;
	p[3].deadline = 30;

	p[4].profit = 300;
	p[4].duration = 4;
	p[4].deadline = 7;

	p[5].profit = 145;
	p[5].duration = 20;
	p[5].deadline = 30;
	ScheduleJobs(p,6);

}