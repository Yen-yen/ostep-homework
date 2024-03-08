#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int pipe_fd[2];

    // Create a pipe
    if (pipe(pipe_fd) == -1)
    {
        perror("Pipe creation failed");
        exit(EXIT_FAILURE);
    }

    // Create the first child
    pid_t child1 = fork();

    if (child1 == -1)
    {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (child1 == 0)
    {
        // Child 1 process
        close(pipe_fd[0]); // Close unused read end

        // Write data to the pipe
        char data[] = "Hello from Child 1";
        write(pipe_fd[1], data, sizeof(data));

        close(pipe_fd[1]); // Close write end

        exit(EXIT_SUCCESS);
    }
    else
    {
        // Create the second child
        pid_t child2 = fork();

        if (child2 == -1)
        {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        }

        if (child2 == 0)
        {
            // Child 2 process
            close(pipe_fd[1]); // Close unused write end

            // Read data from the pipe
            char buffer[256];
            ssize_t bytesRead = read(pipe_fd[0], buffer, sizeof(buffer));

            if (bytesRead > 0)
            {
                // Print the received data
                printf("Received data in Child 2: %.*s\n", (int)bytesRead, buffer);
            }

            close(pipe_fd[0]); // Close read end

            exit(EXIT_SUCCESS);
        }
        else
        {
            // Close both ends of the pipe in the parent
            close(pipe_fd[0]);
            close(pipe_fd[1]);

            // Wait for both child processes to finish
            wait(NULL);
            wait(NULL);

            printf("\nParent process exiting.\n");
        }
    }

    return 0;
}
