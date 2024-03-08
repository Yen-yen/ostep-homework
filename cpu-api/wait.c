#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int rc = fork();
    int status;
    if (rc < 0)
    {
        // fork failed
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0)
    {
        // Child process
        // int rc_wait = wait(NULL);
        printf("child (pid:%d)\n", (int)getpid());
        // printf("child (pid:%d) (rc_wait:%d)\n", (int)getpid(), rc_wait);
    }
    else
    {
        // Parent process
        int rc_wait = waitpid(0, &status, 0);
        if (WIFSIGNALED(status))
        {
            printf("Error\n");
        }
        else if (WEXITSTATUS(status))
        {
            printf("Exited Normally\n");
        }
        printf("parent of %d (rc_wait:%d) (pid:%d)\n", rc, rc_wait, (int)getpid());
        // printf("parent of %d (pid:%d)\n", rc, (int)getpid());
    }
    return 0;
}
