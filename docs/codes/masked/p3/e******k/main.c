#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int totalctr = 0;
pthread_mutex_t lock;

int read(char *path){
    int ctr = 0;
    char ch;
    FILE *fp = fopen(path,"r");
    if (fp == NULL)
        return 0;
    do
    {
        ch = fgetc(fp);
        if(ch == 49)
            ctr++; 
    } while(ch != EOF);

    pthread_mutex_lock(&lock);
    totalctr += ctr;
    pthread_mutex_unlock(&lock);

    fclose(fp);
    return(0);
}

void *Task(void *ptr) {
    int count = read((char *) ptr);
    pthread_exit(&count);
}

int main(int argc, char** argv) {
    argc--;
    //printf("%d files detected.\n",argc);
    pthread_t tid[argc];
    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("mutex init has failed\n");
        return 1;
    }
    for (int i = 0; i < argc; ++i){
        pthread_create( &(tid[i]), NULL, Task, (void *) argv[i+1]);
    }
    for (int i2 = 0; i2 < argc; ++i2){
        pthread_join( tid[i2], (void **) NULL);
        //printf("Thread %d done.\n", i2);
    }
    pthread_mutex_destroy(&lock);
    printf("Total Number of Ones in All Files: %d\n",totalctr);
}
