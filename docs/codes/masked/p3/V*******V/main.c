#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct my_thread
{
    char* file;
    int sayi;
} my_thread;

void* bir_say(void* arg) {
    my_thread* data = (my_thread*) arg;

    FILE* file = fopen(data->file, "r");
    if (file == NULL) {
        data->sayi = 0;
        pthread_exit(NULL);
    }
    
    int sayi = data->sayi;
    char c;
    while ((c = fgetc(file)) != EOF) {
        if (c == '1') {
            sayi++;
        }
    }
    fclose(file);
    data->sayi = sayi;
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    int total = 0;
 pthread_t threads[argc - 1];
    for (int i = 1; i < argc; i++)
    {
        my_thread data;
        data.file = argv[i];
        data.sayi = 0;

        pthread_create(&threads[i - 1], NULL, bir_say, (void*)&data);
        pthread_join(threads[i - 1], NULL);

        total += data.sayi;
    }

    printf("Total Number of Ones in All Files: %d \n", total);

}