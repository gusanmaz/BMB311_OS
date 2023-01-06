#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    // 2^x = 1024 => x = 10
    printf("Parent process created (pid = %d)", (int)getpid());

    int ids[10], i = 0;
    for (i = 0; i < 10; i++)
    {
        ids[i] = fork();
        if (ids[i] == 0)
        {
            printf("New child is here! (pid = %d)\n", (int)getpid());
        }
        else if (ids[i] < 0)
        {
            fprintf(stderr,"Fork failed\n");
        }
        else
        {
            wait(NULL);
            printf("Parent waited the child (pid = %d)\n", (int)getpid());
        }
    }

    exit(0);
}
