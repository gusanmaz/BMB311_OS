#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <pthread.h>

long unsigned int ones = 0;

//thread fonksiyonunu kullandık
void* counter(void* param){
    	
    	char *filename = (char*)param;
    	 
    	FILE* fp = fopen(filename,"r");
    	
    	    if (fp == NULL)//argüman girilmemiş ise null döndür yani (0)
	    {
		//printf("File open error..\n"); kısacası dosya bulunmadı demek
		//exit(0);
		
		ones = ones;
	    }
	    else
	    {
		int id;
	    	
	    	while((id=fgetc(fp))!= EOF){
	    	
	    		//printf("%c", id);
	    		
	    		if((int)id == 49){
	    		   
	    		   ones++;
	    		}
	    	}
	    	
	    	pthread_exit(0);
	    }
    	
    	
    }

int main(int argc, char *argv[])
{

    pthread_t *tid;  //bu foksiyon pthread_t türünde bir değer tutan değişkenin adresini tutar

    tid = (pthread_t *)malloc((argc - 1) * sizeof(pthread_t)); //her bir pthread (iplik) için bellekte yer ayırdık dinamik olarak
    
    //girilen argüman sayısının bir eksiği kadar döngü açtık
    for(int i=1; i < argc; i++){

    	pthread_create(&tid[i],NULL,counter,argv[i]); //burada thread(iplik) oluşturduk
    	pthread_join(tid[i],NULL);			// burda bu fonksiyonla thread(iplik) beklenir
    }
    
    printf("Number of total '1' in all file --> %lu \n", ones); //ve burada değerler ekrana yazdırılır
    
    
        
    return 0;
}
