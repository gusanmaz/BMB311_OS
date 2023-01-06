 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main() {
   // printf() displays the string inside quotation
   for (int i = 0; i < 10; i++)
   {
      int pid = fork();

      if(pid<0) {
         printf("Hata");
         exit(1);
      }
      else if(pid>0) {
         printf("Ben parent. Pid: %d, Benim pid: %d \n", pid, getpid());
         wait(NULL);
      }
      else if(pid==0) {
         printf("Ben child. Pid: %d, Benim pid: %d \n", pid, getpid());
      }
   }
   return 0;
}
