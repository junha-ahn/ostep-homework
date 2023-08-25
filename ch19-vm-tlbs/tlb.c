#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sched.h>
#include <time.h>
#include <sys/time.h>



#define PAGESIZE sysconf(_SC_PAGE_SIZE) // Adjust this to your system's page size

int main(int argc, char *argv[]) {
    cpu_set_t mask;
    CPU_ZERO(&mask);
    CPU_SET(0, &mask);
    sched_setaffinity(0, sizeof(mask), &mask);

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <num_pages_to_touch> <num_trials>\n", argv[0]);
        exit(1);
    }

    int num_pages = atoi(argv[1]);
    int num_trials = atoi(argv[2]);
    
    volatile int* a = malloc(sizeof(int) * num_pages * PAGESIZE); // 페이지를 위한 메모리 할당

    if (a == NULL) {
        perror("Memory allocation failed");
        exit(2);
    }

    struct timeval start, end;
    
    int jump = PAGESIZE / sizeof(int);
    
    for(int i = 0; i < num_pages*jump; i+=jump)
            a[i] = 0;

    gettimeofday(&start, NULL);
    for (int t = 0; t < num_trials; t++) {
        for (int i = 0; i < num_pages * jump; i += jump) {
            a[i] += 1;
        }
    }

    // End timing
    gettimeofday(&end, NULL);

    long long elapsed = (end.tv_sec - start.tv_sec) * 1000000LL + (end.tv_usec - start.tv_usec);
    double avg_access_time = (double)elapsed / num_pages; // Calculate average access time

    printf("Average access time: %.2lf microseconds\n", avg_access_time);
    free((void*)a); // 할당된 메모리 해제

    return 0;
}
