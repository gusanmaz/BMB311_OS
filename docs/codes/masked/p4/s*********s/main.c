#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

void main(int argc, char *argv[]) {
    
    int pid = atoi(argv[1]); 
    printf("Girilen pid değeri: %d\n",pid);  
    char filename[100]; 
    sprintf(filename, "/proc/%d/comm", pid);
    FILE *fp = fopen(filename, "r"); 
    
    if(fp == NULL){
   	
    	printf("NULL\n");
    }
    else{
    	
    	char comm[1000]; 
	fscanf(fp, "%s",comm);     
	printf("comm = %s\n", comm); 
	fclose(fp); 
    }
}

