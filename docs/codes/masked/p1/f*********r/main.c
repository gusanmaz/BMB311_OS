#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int MAX_VALUE = 1023;
int i = 0;

void processCreate();

int main()
{
    processCreate();
}

void processCreate()
{
    int pid;
    pid = fork();

    if(pid > 0)
    {
        wait(NULL);
        if (i == 0) printf("ilk process => pid: %d \n", getpid());
        else printf("%d. child process => pid: %d \n", i, getpid());
    }
    if(pid == 0)
    {
        if (i >= MAX_VALUE) return;
        i++;
        processCreate();
    }
    if(pid < 0)
    {
        printf("error \n");
    }
}
