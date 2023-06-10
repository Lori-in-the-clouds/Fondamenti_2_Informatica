#include  <stdlib.h>
typedef struct {
	int profit;
	int duration;
	int deadline;
} job;
extern int ScheduleJobs(const job* jobs, size_t j_size);
int main(void) {
	job* p = malloc(3 * sizeof(job));
	p[0].profit = 2;
	p[0].duration = 1;
	p[0].deadline = 3;

	p[1].profit = 5;
	p[1].duration = 4;
	p[1].deadline = 9;

	p[2].profit = 8;
	p[2].duration = 7;
	p[2].deadline = 18;
	/*p[0].profit = 50;
	p[0].duration = 2;
	p[0].deadline = 4;

	p[1].profit = 100;
	p[1].duration = 4;
	p[1].deadline = 7;

	p[2].profit = 30;
	p[2].duration = 1;
	p[2].deadline = 3;*/

	ScheduleJobs(p, 3);

}