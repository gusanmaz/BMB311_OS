#include <stdio.h>
#include <stdlib.h>
int main()
{
    int pid;
    printf("1) before the fork\n");
    pid = fork();
    printf("2) after the fork\n");
    if (pid == 0)
    {
        printf("3) i am the child process, my pid is %d\n", getpid());
        printf("my parent has the pid %d\n", getppid());
        exit(1);
    }
    else
    {
        printf("i am the parent process, my pid is %d\n", getpid());
        printf("my parent has the pid %d\n", getppid());
        exit(0); //the father of the father is the terminal
    }
}
