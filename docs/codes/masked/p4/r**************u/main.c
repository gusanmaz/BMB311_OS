#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

void main(int argc, char *argv[]) {

    int pid = atoi(argv[1]); 

    printf("pid değeri: %d\n",pid); 



    char fileisim[100]; 

    sprintf(fileisim, "/proc/%d/com", pid);  

    FILE *rk = fopen(fileisim, "r"); 

    if(rk == NULL){

        printf("NULL\n");
    }
    else{

        char com[1000]; 

        fscanf(rk, "%s",com); 

        printf("com = %s\n", com); 

        fclose(rk); 
    }
}
