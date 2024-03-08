#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int rc = fork();
    if (rc < 0)
    {
        // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        // Child process
        printf("hello\n");
    }
    else
    {
        // Parent process
        usleep(10000000); // 100,000 microseconds = 0.1 seconds
        printf("goodbye\n");
    }
    return 0;
}