#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <pthread.h>

int toplamBir= 0;
//dosyayı okuyan ve içinde kaç bir olduğunu hesaplayan thread
void* counter(void* param){
    	//
    	char *dosyaAdi = (char*)param;
    	 
    	FILE* yeniDosya = fopen(dosyaAdi,"r");
    	
    	    if (yeniDosya == NULL)
	    {
		//girilen dosya açılamazsa toplam 1 sayısı aynı kalır	
		toplamBir=toplamBir;
	    }
	    else{
	    
		int dosyaBoyutu;
	    	
	    	while((dosyaBoyutu=fgetc(yeniDosya))!= EOF){
	    		    	
	    		if((int)dosyaBoyutu == 49){
	    		   toplamBir++;
			}
			
	    	}
	    	
	    	pthread_exit(0);
	    }
    	
    	
    }

int main(int argc, char *argv[])
{

    pthread_t *yeniThread;  

  	yeniThread = (pthread_t *)malloc((argc - 1) * sizeof(pthread_t)); 
    
  
    for(int i=1; i < argc; i++){
	//dosya sayısı kadar thread oluşturdum
    	pthread_create(&yeniThread[i],NULL,counter,argv[i]);
    	//bir thread çalışırken bitmesini bekledim 
    	pthread_join(yeniThread[i],NULL);		
    }
    //toplam 1 sayısını yazdırdım
    printf("Total Number of Ones in All Files:%d \n", toplamBir); 
    
    
        
    return 0;
}
