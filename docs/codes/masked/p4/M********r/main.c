#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

void main(int argc, char *argv[]) {
    
    int perid = atoi(argv[1]); //girilen string argüman int e çevrilir
    
    printf("Girilen pid değeri: %d\n",perid); //girilen argüman (pid) ekrana yazdırılır
    
    

    char dosyaadi[100]; //dosya ismini tutacak bir string
    
    
    
   
	sprintf(dosyaadi, "/proc/%d/comm", perid);  //okunacak dosya dizini oluşturulur
   
	FILE *da = fopen(dosyaadi, "r"); //dosya okuma modunda açılır
    
    
    
    if(da == NULL)
    {
    	
    	printf("NULL\n");
    }
    else
    {
    	
    	char comm[1000]; //komut ismini tutacak bir string

	fscanf(da, "%s",comm); //komut fscanf ile okunur
	    
        
	printf("comm = %s\n", comm); //komut ekrana yazdırılır
	    
        
	fclose(da); //dosya kapatılır
    }
}
