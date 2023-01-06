#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int id1=fork(),id2=fork(),id3=fork(),id4=fork(),id5=fork();
    int id6=fork(),id7=fork(),id8=fork(),id9=fork(),id10=fork();
    
    printf("%d-%d-%d-%d-%d-%d-%d-%d-%d-%d-\n",id1,id2,id3,id4,id5,id6,id7,id8,id9,id10);

    wait(&id1);
    wait(&id2);  
    wait(&id3);  
    wait(&id4);  
    wait(&id5);  
    wait(&id6);  
    wait(&id7);  
    wait(&id8);  
    wait(&id9);  
    wait(&id10);     
    return 0;
}
