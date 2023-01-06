#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

int toplam=0;
void *getCount(void* data)
    {
    char* fileName=(char*)data;
    int count=0;   
    FILE* file;
    char ch;
    file = fopen(fileName, "r");
    if (NULL == file) 
        {
        fclose(file);
        return NULL;
        }
    ch = fgetc(file);
    while (ch != EOF) 
        {
        if(ch=='1')
        count++;
        ch = fgetc(file);
        }   
    fclose(file);
    toplam+=count;
    return NULL;
    }

int main(int argc, char *argv[])
    {
    pthread_t myThread[argc-1];
    int status;
    toplam=0;
    for(int i=1;i<argc;i++){
   	status =  pthread_create(&myThread[i], NULL, getCount,(void*)argv[i]);
    } 
    for(int i = 1; i < argc; i++)
        { 
        pthread_join(myThread[i], NULL);
        }
    printf("\nTotal Number of Ones in All Files: %d\n",toplam);
    return 0;
    }
