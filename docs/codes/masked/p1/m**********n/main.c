#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    printf("hello world (pid=%d)\n", (int)getpid());
    int childeren[10], i;
    for (i = 0; i < 10; i++)
    {
        childeren[i] = fork();
        if (childeren[i] < 0)
        {
            fprintf(stderr, "fork failed\n");
            exit(1);
        }
        else if (childeren[i] == 0)
        {
            printf("im child: (pid=%d)\n", (int)getpid());
        }
        else
        {
            wait(&childeren[i]);
            printf("im parent: (pid=%d)\n", (int)getpid());
        }
    }
    exit(0);
}
