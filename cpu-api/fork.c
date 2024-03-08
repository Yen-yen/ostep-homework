#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("hello (pid:%d)\n", (int)getpid());
    int x = 100;
    int rc = fork();
    if (rc < 0)
    {
        // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        // child (new process)
        x = x - 10;
        printf("child (pid:%d)\n", (int)getpid());
        printf("x: %d\n", x);
    }
    else
    {
        // parent goes down this path (main)
        x = x - 1;
        printf("parent of %d (pid:%d)\n", rc, (int)getpid());
        printf("x: %d\n", x);
    }
    return 0;
}
