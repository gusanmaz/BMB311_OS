#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>     
#include <sys/wait.h>

int main()
{
    for(int i = 0; i < 10; i++)
    {
        int p=fork();
        if(p!=0)
        {
            wait(NULL);
        }
        printf("%d\n",p);
    wait(p);
    }
    
}
