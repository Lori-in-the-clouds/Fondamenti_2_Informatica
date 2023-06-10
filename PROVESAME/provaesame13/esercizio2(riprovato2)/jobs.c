#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct {
    int profit;
    int duration;
    int deadline;
}job;
int comp(const void* a,const void* b) {
    job arg1 = *(const job*)a;
    job arg2 = *(const job*)b;
    if ((arg1.profit / arg1.duration) < (arg2.profit / arg2.duration)) return 1;
    if ((arg1.profit / arg1.duration) > (arg2.profit / arg2.duration)) return -1;
    else {
        if (arg1.duration < arg2.duration) return -1;
        if (arg1.duration > arg2.duration) return  1;
        return 0;
    }
}
int ScheduleJobs(const job* jobs, size_t j_size) {
    if (j_size <= 0) return 0;
    job* news = calloc(j_size, sizeof(job));
    memcpy(news, jobs, j_size * sizeof(job));
    qsort(news, j_size, sizeof(job), comp);
    int som = 0;
    int temp = 0;
    for (int i = 0; i < j_size; i++) {
        if (temp+news[i].duration <= news[i].deadline) {
            temp += news[i].duration;
            som += news[i].profit;
            for (int j = 0; j < j_size; j++) {
                if (memcmp(&news[i], &jobs[j], sizeof(job)) == 0) {
                    printf("%d", j);
                    break;
                }
            }
       }
    }
    return som;
}


//int main(void) {
//    job a[] = { {.duration = 2,.profit = 80,.deadline = 4 },{.duration = 5,.profit = 100,.deadline = 6 },{.duration = 1,.profit = 30,.deadline = 3 } };
//    ScheduleJobs(a, 3);
//    return 0;
//}