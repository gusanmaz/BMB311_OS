#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <pthread.h>

long unsigned int ones = 0;

void* sayac(void* One){
    	
    	char* filename = (char *)One;
    	 
    	FILE* fp = fopen(filename,"r");
    	if (fp == NULL)
	    {
		
		ones = ones;
	    }
	    else
	    {
		int id;
	    	
	    	while((id=fgetc(fp))!= EOF){	    		    		
	    		
	    		if((int)id == 49){
	    		   
	    		   ones++;
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

    	pthread_create(&tid[i],NULL,sayac,argv[i]); 
    	pthread_join(tid[i],NULL);			
    }
    
    printf("Total Number of Ones in All Files: %lu \n", ones); 
    
    
        return 0;
}
