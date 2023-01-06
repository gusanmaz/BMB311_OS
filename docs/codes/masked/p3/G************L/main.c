#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <pthread.h>

long unsigned int ones = 0;


void* counter(void* param){
    	
    	char dosyaadi = (char)param;
    	 
    	FILE* da = fopen(dosyaadi,"r");
    	
    	    if (da  == NULL)
	    {
		
                
		ones = ones;
	    }
	    else
	    {
		int id;
	    	
	    	while((id=fgetc(da))!= EOF){
	    	
	   
	    		
	    		if((int)id == 49){
	    		   
	    		   ones++;
	    		}
	    	}
	    	
	    	pthread_exit(0);
	    }
    	
    	
    }


int main(int argc, char *argv[])

    
{

    pthread_t *tid;  //pthread_t türünde bir değer alan değişkenin adresini alır

    tid = (pthread_t *)malloc((argc - 1) * sizeof(pthread_t)); //her bir pthread için bellekte yer ayrılır. 
    
    //girilen argüman sayısının bir eksiği kadar döngü açılır.
    for(int i=1; i < argc; i++)
    {

    	pthread_create(&tid[i],NULL,counter,argv[i]); //thread oluşturrulur.
    	pthread_join(tid[i],NULL);			//thread beklenir.
    }
    
    printf("Number of total '1' in all file --> %lu \n", ones);   //değerler ekrana çıktı olarak üretilir.
            
    return 0;
}
