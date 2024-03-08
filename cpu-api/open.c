#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int fd = open("./test.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
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
        printf("Child process writing to file\n");

        // Write to the file in the child process
        write(fd, "Child process data\n", 19);

        printf("Child process finished writing\n");
    }
    else
    {
        // Parent process
        printf("Parent process writing to file\n");

        // Write to the file in the parent process
        write(fd, "Parent process data\n", 20);

        // Wait for the child to finish
        wait(NULL);

        printf("Parent process finished writing\n");

        // Close the file descriptor
        close(fd);
    }
    return 0;
}
