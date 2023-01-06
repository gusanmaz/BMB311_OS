#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct thread_data
{
    char* file;
    int count;
} thread_data;

void* countOneInFile(void* arg) {
    thread_data* threaddata = (thread_data*) arg;

    FILE* f = fopen(threaddata->file, "r");
    if (f == NULL) {
        threaddata->count = 0;
        pthread_exit(NULL);
    }
    
    int cnt = threaddata->count;
    char ch;
    while ((ch = fgetc(f)) != EOF) {
        if (ch == '1') {
            cnt++;
        }
    }
    fclose(f);
    threaddata->count = cnt;
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    int sonuc = 0;

    pthread_t threadArr[argc - 1];
    for (int i = 1; i < argc; i++)
    {
        thread_data threaddata;
        threaddata.file = argv[i];
        threaddata.count = 0;

        pthread_create(&threadArr[i - 1], NULL, countOneInFile, (void*)&threaddata);
        pthread_join(threadArr[i - 1], NULL);

        sonuc += threaddata.count;
    }
    printf("Total Number of Ones in All Files: %d \n", sonuc);
}
