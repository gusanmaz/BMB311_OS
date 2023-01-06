#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void)
{
    for(int i=0;i<1023;i++)
    {
    pid_t pid=fork();
    if(pid<0)printf("process olusturmada hata olustu.");
    else if(pid==0)
        {
    printf("cocuk process pid: %d, parent process pid : %d\n",getpid(),getppid());
    exit(0);
        }
    else
    { 
    wait(NULL);
    }
        }
    return 0;
}
