#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int *ptr = (int *)malloc(100 * sizeof(int));
    ptr[100] = 0; // nothing happened, no seg fault immediately, but unpredictable behavior
    return 0;
}