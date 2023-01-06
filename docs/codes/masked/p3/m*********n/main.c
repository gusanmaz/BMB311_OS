#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
int a = 0;
int sonuc = 0;
void *myThread(void *str)
{
    a = 0;
    int c;
    FILE *f = fopen(str, "r");
    while(1)
    {
        c = fgetc(f);
        if(c == 49)
            a++;
        if(feof(f))
            break;
    }
    sonuc += a;
    pthread_exit(NULL);
}

int main(int ac, char **av)
{
    pthread_t tid[ac];
    for(int i = 1; i < ac; i++)
     {
        pthread_create(&tid[i], NULL, myThread, av[i]);
     }
     for(int i = 1; i < ac; i++)
     {
        pthread_join(tid[i], NULL );
     }
     printf("Total Number of Ones in All Files: %d",sonuc);
}
