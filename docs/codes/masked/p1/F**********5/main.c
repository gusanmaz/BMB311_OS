#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int _tree (int height){
if(height==0) 
{
    return;
}
    int pid=fork();
    if(pid>0){
        pid2=fork();
            if(pid2>0){
                wait(NULL);
                printf("parent : %d c1:%d,c2%d\n",getpid(),pid,pid2);
        }
            else if(pid2==0){
        _tree(--height);
        }
    }
    else if(pid===0){
       _tree(--height);
    }

}

int main(int argc, char *argv[])
{
    _tree(11);
    
     
}
