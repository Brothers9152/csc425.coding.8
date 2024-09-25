#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <memory_in_MB> <time_in_seconds>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("PID: %d\n", getpid());

    int memory = atoi(argv[1]) * 1024 * 1024;  // Convert memory argument to bytes
    int length = memory / sizeof(int);         // Calculate the number of integers
    int runTime = atoi(argv[2]);               // Get the runtime in seconds
    int *arr = malloc(memory);                 // Allocate memory

    if (!arr)                                  // Check for successful memory allocation
    {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    clock_t begin = clock();                   // Start the clock
    double time_spent;

    while (1)
    {
        time_spent = (double)(clock() - begin) / CLOCKS_PER_SEC;
        if (time_spent >= runTime)
            break;

        for (int i = 0; i < length; i++)
            arr[i] += 1;                       // Simulate memory usage
    }

    free(arr);                                 // Free allocated memory
    return EXIT_SUCCESS;
}

