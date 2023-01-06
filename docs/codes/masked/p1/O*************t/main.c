#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/wait.h> 

int main(int argc, char *argv[]) 
{ 
	int p_ids[1023], i;
	
	for(i=0; i<1023; i++){
		p_ids[i] = fork(); 
	}
 	
 	for(i=0; i<1023; i++){
		printf("process %d id = %d\n", i, p_ids[i]);
	}
	
	for(i=0; i<1023; i++){
		wait(&p_ids[i]);
	}
	
	 
	exit(0); 
} 
