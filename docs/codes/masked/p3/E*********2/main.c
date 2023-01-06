#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <pthread.h>

long unsigned int ones = 0;

//thread fonksiyonu
void* counter(void* param){
    	
    	char* filename = (char *)param;
    	 
    	FILE* fp = fopen(filename,"r");
    	
    	    if (fp == NULL)//argüman girilmemiş ise
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
    
    //girilen argüman sayısının bir eksiği kadar döngü açtık
    for(int i=1; i < argc; i++){

    	pthread_create(&tid[i],NULL,counter,argv[i]); //thread oluşturduk
    	pthread_join(tid[i],NULL);			//thread beklenir
    }
    
    printf("Number of total '1' in all file --> %lu \n", ones); //değerler ekrana yazdırılır
    
    
        
    return 0;
}
