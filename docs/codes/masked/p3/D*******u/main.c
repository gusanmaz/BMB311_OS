#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


typedef struct ThreadData
{
    char* file;
    int sayac;

} ThreadData;




void* CountFile(void* arg) {
    
   ThreadData* td = (ThreadData*) arg;
    // td->file - "deneme.txt"
   
    FILE* file = fopen(td->file ,"r");
    
    if (file == NULL) {
        td->sayac = 0;
        pthread_exit(NULL);
    }
    
    int sayac = td->sayac;
    
    char rc;
    while ((rc = fgetc(file)) != EOF) {
        if (rc == '1') {
            sayac++;
        }
    }
    fclose(file);
    td->sayac = sayac;
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    int rslt = 0;

    pthread_t thread[argc - 1];
    for (int i = 1; i < argc; i++)
    {
        ThreadData td;
        td.file = argv[i];
        td.sayac = 0;

        pthread_create(&thread[i - 1], NULL, CountFile, (void*)&td);
        pthread_join(thread[i - 1], NULL);

        rslt += td.sayac;




    }

    printf("Total Number of Ones in All Files: %d \n", rslt);
}


