#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

void main(int argc, char *argv[]) {
    
    int pid = atoi(argv[1]); 
    char comm[1000]; 
    char fn[100]; 
    
    printf("Pid input: %d\n",pid); 
    sprintf(fn, "/proc/%d/comm", pid); 
    
    FILE *fp = fopen(fn, "r");
    if(fp == NULL){
    	printf("NULL\n");
    }
    else{ 	
	fscanf(fp, "%s",comm);    
	printf("Command output: %s\n", comm);   
	fclose(fp);
    }
}
