#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int id1 = fork();	//child1 process oluşturulur
    int id2 = fork();	//child1 ve program kendi child processlerini oluşturur 
    int id3 = fork();	//her fork 2^n tane çocuk oluşturur
    int id4 = fork();   //alta oluşan child hem parent hemde child özelliği taşır 
    int id5 = fork();   //en son oluşan child lar sadece child özeliği taşır.
    int id6 = fork();
    int id7 = fork();
    int id8 = fork();
    int id9 = fork();
    int id10= fork();

    printf("%d-%d-%d-%d-%d-%d-%d-%d-%d-%d\n", id1, id2, id3, id4, id5, id6, id7, id8, id9, id10);
    
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

    exit(0);
}
