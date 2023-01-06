#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

        int main(int argc, char *argv[])
         {
             int id_1 = fork();
             int id_2 = fork();
             int id_3 = fork();
             int id_4 = fork();
             int id_5 = fork();
             int id_6 = fork();
             int id_7 = fork();
             int id_8 = fork();
             int id_9 = fork();
             int id_10 = fork();
    
                printf("%d-%d-%d-%d-%d-%d-%d-%d-%d-%d\n", id_1, id_2, id_3, id_4, id_5, id_6, id_7, id_8, id_9, id_10);
                    wait(&id_1);
                    wait(&id_2);
                    wait(&id_3);
                    wait(&id_4);
                    wait(&id_5);
                    wait(&id_6);
                    wait(&id_7);
                    wait(&id_8);
                    wait(&id_9);
                    wait(&id_10);
                        exit(0);
          }
