
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    // Write C code here
    int pid = fork();
    int pid2 = fork();
    int pid3 = fork();
    int pid4 = fork();
    int pid5 = fork();
    int pid6 = fork();
    int pid7 = fork();
    int pid8 = fork();
    int pid9 = fork();
    if(pid==0){
        printf(" ben child:%d pid'im:%d\n ",pid,getpid());
        
    }
    if(pid>0){
    wait(NULL);
        printf(" ben parent %d pid'im: %d \n",pid,getpid());
    }

    exit(0);
}
