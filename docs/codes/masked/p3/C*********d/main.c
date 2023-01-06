#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct thread_data
{
    char* file;
    int count;
} thread_data;

void* count_one_in_file(void* arg) {
    thread_data* t_data = (thread_data*) arg;

    FILE* file = fopen(t_data->file, "r");
    if (file == NULL) {
        t_data->count = 0;
        pthread_exit(NULL);
    }
    
    int counter = t_data->count;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '1') {
            counter++;
        }
    }
    fclose(file);
    t_data->count = counter;
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    int result = 0;

    pthread_t threadList[argc - 1];
    for (int i = 1; i < argc; i++)
    {
        thread_data t_data;
        t_data.file = argv[i];
        t_data.count = 0;

        pthread_create(&threadList[i - 1], NULL, count_one_in_file, (void*)&t_data);
        pthread_join(threadList[i - 1], NULL);

        result += t_data.count;
    }
    printf("Total Number of Ones in All Files: %d \n", result);
}
