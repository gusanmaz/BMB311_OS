#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

void main(int argc, char *argv[]) {
    
    int p = atoi(argv[1]); 
    
    printf("Girilen p değeri: %d\n",p); 
    
    

    char dosyaadi[100]; 
    
    sprintf(dosyaadi, "/proc/%d/comm", p);  
    
    FILE *fp = fopen(dosyaadi, "r");
    
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
