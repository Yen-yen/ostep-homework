#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <memory_size_in_MB>\n", argv[0]);
        return 1;
    }

    // Parse the command-line argument for memory size in MB
    int memory_size_MB = atoi(argv[1]);
    long long memory_size_bytes = memory_size_MB * 1024 * 1024;

    // Allocate memory for the array
    char *memory_array = (char *)malloc(memory_size_bytes);
    if (memory_array == NULL)
    {
        printf("Failed to allocate memory.\n");
        return 1;
    }

    // Access each element of the array indefinitely
    while (1)
    {
        for (long long i = 0; i < memory_size_bytes; i++)
        {
            memory_array[i] = 0; // Access each element
        }
        usleep(10000); // Sleep for 10 milliseconds (adjust as needed)
    }

    // Free the allocated memory (unreachable in this example)
    free(memory_array);

    return 0;
}
