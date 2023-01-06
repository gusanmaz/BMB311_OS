//kütüphaneler 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

//main

int main(){

    for(int i=0; i<1023;i++){ // 1023 kere loopa sokacağız ve 1023 kere çocuk procces oluşturacak

        if (fork() ==0){

            printf(" ben çocuk proccessim pid'im %d Parent id'im ise %d\n", getpid(),getppid());
            exit(0);

        }
    
    }

    for(int i=0; i<1023;i++) // aynı şekilde 1023 kere loopa sokacağız
    wait(NULL);

}
