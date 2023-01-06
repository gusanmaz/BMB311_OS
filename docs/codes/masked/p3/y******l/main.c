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
    int b;
    FILE *f = fopen(str, "r");
    while(1)
    {
        b = fgetc(f);
        if(b == 49)
            x++;
        if(feof(f))
            break;
    }
    result += x;
    pthread_exit(NULL);
}

int main(int bc, char **bv)
{
    pthread_t tid[bc];
    for(int i = 1; i < bc; i++)
     {
        pthread_create(&tid[i], NULL, t_Thread, bv[i]);
     }
     for(int i = 1; i < bc; i++)
     {
        pthread_join(tid[i], NULL );
     }
     printf("Total Number of Ones in All Files: %d",result);
}
