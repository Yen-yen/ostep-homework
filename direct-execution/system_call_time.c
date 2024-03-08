#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>

int main()
{
    struct timespec start, end;

    // Measure the precision of the timer
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);

    uint64_t timer_precision = (end.tv_sec - start.tv_sec) * 1000000000 + (end.tv_nsec - start.tv_nsec);
    printf("Timer precision: %llu nanoseconds\n", timer_precision);

    // Measure the cost of a system call using clock_gettime
    for (int i = 0; i < 200; i++)
    {
        clock_gettime(CLOCK_MONOTONIC_RAW, &start);

        // Perform a simple system call, e.g., 0-byte read
        read(STDIN_FILENO, NULL, 0);

        clock_gettime(CLOCK_MONOTONIC_RAW, &end);

        uint64_t syscall_cost = (end.tv_sec - start.tv_sec) * 1000000000 + (end.tv_nsec - start.tv_nsec);
        printf("System call cost: %llu nanoseconds\n", syscall_cost);
    }

    return 0;
}
