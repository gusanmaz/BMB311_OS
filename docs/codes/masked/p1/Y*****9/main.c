#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
   for (int kid = 0; kid < 10; kid++){
      int pid = fork();

      if(pid<0) {
         exit(1);
      }
      else if(pid>0) {
         wait(NULL);
      }
      else if(pid==0) {
      }
   }
   return 0;
}
