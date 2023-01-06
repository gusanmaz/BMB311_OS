#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct thread_data
{
    char* dosya;
    int sayac;
} 

thread_data;
void* bir_dosyadaki_miktar(void* arg) 
{
    thread_data* thrdata = (thread_data*) arg;

    FILE* dosya = fopen(thrdata->dosya, "r");

    if (dosya == NULL) 
    {
        thrdata->sayac = 0;
        pthread_exit(NULL);
    }

    int sayac = thrdata->sayac;
    char kar;
    while ((kar = fgetc(dosya)) != EOF) 
    {
        if (kar == '1') {
            sayac++;
        }
    }
    fclose(dosya);
    thrdata->sayac = sayac;
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    
    int sonuc = 0;
    pthread_t threads[argc - 1];
    for (int i = 1; i < argc; i++)
    {
        thread_data thrdata;
        thrdata.dosya = argv[i];
        thrdata.sayac = 0;
        pthread_create(&threads[i - 1], NULL, bir_dosyadaki_miktar, (void*)&thrdata);
        pthread_join(threads[i - 1], NULL);
        sonuc += thrdata.sayac;
    }
    printf("Total Number of Ones in All Files: %d \n",sonuc);
}
