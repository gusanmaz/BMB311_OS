#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int pid1=fork();
    int pid2=fork();
    int pid3=fork();
    int pid4=fork();
    int pid5=fork();
    int pid6=fork();
    int pid7=fork();
    int pid8=fork();
    int pid9=fork();
    int pid10=fork();
    wait(&pid1);
    wait(&pid2);
    wait(&pid3);
    wait(&pid4);
    wait(&pid5);
    wait(&pid6);
    wait(&pid7);
    wait(&pid8);
    wait(&pid9);
    wait(&pid10);
    
    exit(0);
}
