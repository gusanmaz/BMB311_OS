#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int COUNT = 10;

    // creates COUNT child processes
    for (int i = 0; i < COUNT; i++)
    {
        int pid = fork();
        if (pid == 0)
        {
            printf("(i:%d) Child \n", i);
            wait(&pid);
        }
        else if (pid < 0)
        {
            printf("Fork failed\n");
            exit(1);
        }
    }

    exit(0);
}