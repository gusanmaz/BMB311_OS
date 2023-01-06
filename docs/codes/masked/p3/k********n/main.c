#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
int a = 0;
int result = 0;
void *threadFunction(void *str)
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
    result += a;
    pthread_exit(NULL);
}

int main(int ac, char **av)
{
    pthread_t newThread[ac];
    for(int i = 1; i < ac; i++)
     {
        pthread_create(&newThread[i], NULL, threadFunction, av[i]);
     }
     for(int i = 1; i < ac; i++)
     {
        pthread_join(newThread[i], NULL );
     }
     printf("Total Number of Ones in All Files: %d",result);
}
