#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

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
        printf("Child process printing\n");
        close(STDOUT_FILENO);
        // Write to the file in the child process

        printf("Child process finished printing\n");
    }
    else
    {
        // Parent process
        printf("Parent process printing\n");

        // Wait for the child to finish
        wait(NULL);

        printf("Parent process finished printing\n");
    }
    return 0;
}
