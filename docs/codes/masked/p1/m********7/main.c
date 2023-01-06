#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int COUNT = 10;
    int i = 0;
    // creates COUNT child processes
    while (i < COUNT)
    {
        int pid = fork();
        if (pid == 0)
        {
            printf("(i:%d) Child, %d\n", i,getpid());
            wait(&pid);
        }
        else if (pid < 0)
        {
            printf("Fork failed\n");
            exit(1);
        }
        i++;
    }
}
