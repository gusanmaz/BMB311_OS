#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef struct thread_data
{
    char* file;
    int count;
} thread_data;

void* count_one_in_file(void* arg) {
    thread_data* tdata = (thread_data*) arg;

    FILE* file = fopen(tdata->file, "r");
    if (file == NULL) {
        tdata->count = 0;
        pthread_exit(NULL);
    }
    
    int count = tdata->count;
    char c;
    while ((c = fgetc(file)) != EOF) {
        if (c == '1') {
            count++;
        }
    }
    fclose(file);
    tdata->count = count;
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    int result = 0;
    pthread_t threads[argc - 1];
    for (int i = 1; i < argc; i++)
    {
        thread_data tdata;
        tdata.file = argv[i];
        tdata.count = 0;

        pthread_create(&threads[i - 1], NULL, count_one_in_file, (void*)&tdata);
        pthread_join(threads[i - 1], NULL);

        result += tdata.count;
    }

    printf("Total Number of Ones in All Files: %d \n", result);
    
}
