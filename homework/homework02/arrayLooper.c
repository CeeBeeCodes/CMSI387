#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[])
{
    int size;
    double start_t, end_t, total_t;

    size = atoi(argv[1]);

    const int sizeOfTotalTimes = size / 4096;
    double totalTimes[sizeOfTotalTimes];
    int timesIndex = 0;

    // ASSIGN RANDOM VALUES TO ARRAY
    int* array = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        int randomValue = rand() % 101;
        array[i] = randomValue;
    }

    printf("Array has been filled with values.\n");
    start_t = clock();
    for (int i = 0; i < size; i++)
    {
        int mod = i % 4096;
        if (mod == 0 && i != 0)
        {
            end_t = clock();
            total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
            totalTimes[timesIndex] = total_t;
            timesIndex++;
            printf("Access has happened at index %d. Value: %d. Time elapsed: %f\n", i, array[i], total_t);
        }
    }

    // CALCULATE AVERAGE
    double addedTimes;
    for (int i = 0; i < sizeOfTotalTimes; i++)
    {
        addedTimes += totalTimes[i];
    }
    double average = (double)addedTimes / sizeOfTotalTimes;
    printf("Average time: %f\n", average);

    free(array);

    return 0;
}