#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <pthread.h>

long unsigned int numOfOne = 0;

void* counter(void* param){

    	char* fn = (char *)param; 
    	FILE* fp = fopen(fn,"r");
	    if(fp!=NULL){
		int id;
	    	while((id=fgetc(fp))!= EOF){
	    		if((int)id == 49){
	    		   numOfOne++;
	    		}
	    	}
	    	pthread_exit(0);
	    }
    }

int main(int argc, char *argv[]){
    pthread_t *tid;
    tid = (pthread_t *)malloc((argc - 1) * sizeof(pthread_t));
    
    for(int i=1; i < argc; i++){
    	pthread_create(&tid[i],NULL,counter,argv[i]); 
    	pthread_join(tid[i],NULL);			
    }
    
    printf("Dosyadaki 1 sayısı: %lu \n", numOfOne);
    
    return 0;
}
