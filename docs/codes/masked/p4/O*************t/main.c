#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid1, pid2, pid3;
    pid1=0, pid2=0, pid3=0;
    pid1= fork(); 
    if(pid1==0){
        pid2=fork(); 
        pid3=fork(); 
    } else {
        pid3=fork(); 
        if(pid3==0) {
            pid2=fork(); 
        }
        if((pid1 == 0)&&(pid2 == 0))
            printf("Level 1\n");
        if(pid1 !=0)
            printf("Level 2\n");
        if(pid2 !=0)
           printf("Level 3\n");
        if(pid3 !=0)
           printf("Level 4\n");
       return 0;
    }
}
