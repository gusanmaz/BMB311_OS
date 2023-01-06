/*
- 2190656055
- yunusemredevyazici@gmail.com
- 2022-12-04 21:00:00
- The project opens and reads the file given as an argument and finds how many 1s there are. It calculates each argument in a different thread.
- using multithread,useing mutex,using arguments,using malloc,using free,using pointer
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <string.h>

int oneHm = 0;
pthread_mutex_t mutex;

void *count_ones(void *arg)
{
     pthread_mutex_lock(&mutex);
    char *fileName = (char *)arg;

    printf("Reading file %s \n", fileName);
    FILE *file = fopen(fileName, "r");
    char *code;
    size_t n = 0;
    int c;
    char satir[256];
    if (file == NULL)
    {
        return NULL;
    }
    while (fgets(satir, 256, file) != NULL)
    {
        for (int i = 0; i < strlen(satir); i++)
        {
            if (satir[i] == '1')
            {
                oneHm++;
            }
        }
    }
    fclose(file);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main(int argc, char const *argv[])
{
    if (argc != 1)
    {
        pthread_t th[argc - 1];
        pthread_mutex_init(&mutex, NULL);
        int i;
        for (i = 1; i < argc; i++)
        {
            if (pthread_create(th + i, NULL, &count_ones, (void *)argv[i]) != 0)
            {
                perror("Failed to create thread");
            }
            printf("Thread %d has created\n", i);
        }

        for (i = 1; i < argc; i++)
        {
            if (pthread_join(th[i], NULL) != 0)
            {
                return 2;
            }
            printf("Thread %d has finished execution\n", i);
        }

        pthread_mutex_destroy(&mutex);

        printf("Total Number of Ones in All Files: %d\n", oneHm);
    }
    else
    {
        printf("Total Number of Ones in All Files: %d\n", oneHm);

        return 0;
    }
}
