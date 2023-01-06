#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
int x = 0;
int result = 0;
void *t_Thread(void *str)
{
    x = 0;
    int c;
    FILE *f = fopen(str, "r");
    while(1)
    {
        c = fgetc(f);
        if(c == 49)
            x++;
        if(feof(f))
            break;
    }
    result += x;
    pthread_exit(NULL);
}

int main(int ac, char **av)
{
    pthread_t tid[ac];
    for(int i = 1; i < ac; i++)
     {
        pthread_create(&tid[i], NULL, t_Thread, av[i]);
     }
     for(int i = 1; i < ac; i++)
     {
        pthread_join(tid[i], NULL );
     }
     printf("Total Number of Ones in All Files: %d",result);
}
