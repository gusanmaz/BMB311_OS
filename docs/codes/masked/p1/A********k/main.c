#include<stdio.h>
#include<stdlib.h> 
 
int main()
{
    for(int i=0;i<1023;i++)
    {
        if(fork() == 0)
        {
            printf("[cocuk] pid %d from [ana] pid %d\n",getpid(),getppid());
            exit(0);
        }
    }
    for(int i=0;i<1023;i++) 
    wait(NULL);
     
}
