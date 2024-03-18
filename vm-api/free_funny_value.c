#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int *ptr = (int *)malloc(100 * sizeof(int));
    free(&ptr[50]);
    return 0;
}