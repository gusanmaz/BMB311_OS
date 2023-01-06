#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include<unistd.h>
int main()

{
    for ( int i = 0; i < 10; i++)
    {
        int pid=fork();
        if(pid!=0)
        {
            wait(NULL);
        }
       
    }
     
    
}