#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct thread_data
{
    char* file;
    int count;
}

thread_data;
void* all_ones(void* arg)
{
    thread_data* thrdata = (thread_data*) arg;

    FILE* file = fopen(thrdata->file, "r");

    if (file == NULL)
    {
        thrdata->count = 0;
        pthread_exit(NULL);
    }

    int count = thrdata->count;
    char kar;
    while ((kar = fgetc(file)) != EOF)
    {
        if (kar == '1') {
            count++;
        }
    }
    fclose(file);
    thrdata->count = count;
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
   
    int result = 0;
    pthread_t threads[argc - 1];
    for (int i = 1; i < argc; i++)
    {
        thread_data thrdata;
        thrdata.file = argv[i];
        thrdata.count = 0;
        pthread_create(&threads[i - 1], NULL, all_ones, (void*)&thrdata);
        pthread_join(threads[i - 1], NULL);
        result += thrdata.count;
    }
    printf("Total Number of Ones in All Files: %d \n",result);
}
