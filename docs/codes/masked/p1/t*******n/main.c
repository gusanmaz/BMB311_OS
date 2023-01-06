#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include<stdio.h>
 
 
int main()
{
  
    for(int i=0;i<1024;i++) // döngü 1024 kere çalışacak 
    {
      
        if(fork() == 0)  //child processe girdiğinde
        {
            printf("child pid %d from [parent] pid %d\n",getpid(),getppid());
            exit(0);
        }
          
    }
    for(int i=0;i<1024;i++) // döngü 1024 kere konuşacak
            wait(NULL);      //child processler bitene kadar ana processin sonlanmasını engelleyecek
     
}
