#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

void forker(int nprocesses)
{
    printf("I am: %d process\n", (int)getpid());
    pid_t pid;
    if (nprocesses > 0)
    {
        if ((pid = fork()) < 0)
        {
            perror("fork");
        }
        else if (pid == 0)
        {
            // Child activity
            printf("I am the child with pid %d\n", (int)getpid());

        }
        else if (pid > 0)
        {
            // parent activity
            wait(NULL);
            forker(nprocesses - 1);
        }
    }
}

int main(int argc, char const *argv[])
{
    forker(1023);
    return (0);
}
