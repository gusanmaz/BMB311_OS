#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    for(int i=0;i<1023;i++) // loop will run n times (n=1023)
    {
        if(fork() == 0)
        {
            printf("[son] pid %d from [parent] pid %d\n",getpid(),getppid());
            exit(0);
        }
    }
    for(int i=0;i<1023;i++) // loop will run n times (n=1023)
    wait(NULL);
     
}
