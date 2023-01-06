#include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <string.h>
 #include <sys/wait.h>

 int main(int argc, char *argv[]) {

  

   int ug=fork();

  if(ug<0){
    fprintf(stderr, "Fork Failed");
    exit(1);
  } 
  else if(ug==0){ 
    int rc=fork();
    int rc1=fork();
    int rc2=fork();
    int rc3=fork();
    int rc4=fork();
    int rc5=fork();
    int rc6=fork();
    int rc7=fork();
    int rc8=fork();
    int rc9=fork();

    printf("%d-%d-%d-%d-%d-%d-%d-%d-%d-%d\n",rc,rc1,rc2,rc3,rc4,rc5,rc6,rc7,rc8,rc9);    

    wait(&rc);
    wait(&rc1);
    wait(&rc2);
    wait(&rc3);
    wait(&rc4);
    wait(&rc5);
    wait(&rc6);
    wait(&rc7);
    wait(&rc8);
    wait(&rc9);
    
   }
  
  else{

    printf("Ana Procces Id = %d\n", getpid());
  }
  return 0;
       
}
  
