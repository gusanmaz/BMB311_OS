#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <pthread.h>

long unsigned int census = 0;

void* counter(void* param){
    	
    	char* dosya = (char*)param;
    	 
    	FILE* fp = fopen(dosya,"r");
    	
    	    if (fp == NULL)
	    {
		census = census;
	    }
	    else
	    {
		int id;
	    	
	    	while((id=fgetc(fp))!= EOF){
	    	
	    		
	    		if((int)id == 49){
	    		   
	    		   census++;
	    		}
	    	}
	    	
	    	pthread_exit(0);
	    }
    	
    	
    }

int main(int argc, char *argv[])
{
    pthread_t *tid; 

    tid = (pthread_t *)malloc((argc - 1) * sizeof(pthread_t)); 
    
    for(int i=1; i < argc; i++){

    	pthread_create(&tid[i],NULL,counter,argv[i]); 
    	pthread_join(tid[i],NULL);			
    }
    printf("Total Number of census in All Files: %lu \n", census);     
    return 0;
}
