#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

long unsigned int counter = 0;

void *
myThread(void *arg)
{
    char *filename = (char *)arg;

    FILE *file;

    file = fopen(filename, "r");

    char digit;
    do
    {
        digit = (char)fgetc(file);

        if (digit == '1')
        {
            counter++;
        }

    } while (digit != EOF);

    return NULL;
}

int main(int argc, char *argv[])
{

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    
    pthread_t *threads;

    threads = (pthread_t *)malloc((argc - 1) * sizeof(pthread_t));

    for (int i = 1; i < argc; i++)
    {
        pthread_create(&threads[i], NULL, myThread, argv[i]);
        pthread_join(threads[i], NULL);
    }

    printf("Number of total '1' --> %lu \n", counter);

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\n%lf cpu time used.\n", cpu_time_used);
    return 0;
}
