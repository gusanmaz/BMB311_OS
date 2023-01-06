#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

void main(int argc, char *argv[]) {
    
    int pid = atoi(argv[1]); // burada girilen string argüman int e çevrilir
    
    printf("Girilen pid değeri: %d\n",pid); // burda girilen argümanı  (pid) ekrana yazdırdık
    
    

    char filename[100]; // burada dosya ismini tutacak bir string değişkeni tanımladık
    
    sprintf(filename, "/proc/%d/comm", pid);  //okunacak dosya dizini oluşturulur bu komut 2. projede yardım alınıdı.
    
    FILE *fp = fopen(filename, "r"); //buarda dosyayı  okuma modunda açılır
    
    if(fp == NULL){
    	
    	printf("NULL\n");
    }
    else{
    	
    	char comm[1000]; // burada komut ismini tutacak bir string tanımladık

	fscanf(fp, "%s",comm); //ve bu komut fscanf ile okunur
	    
	printf("comm = %s\n", comm); //burda da komut ekrana yazdırılır
	    
	fclose(fp); //son olaraka da burada dosyayı  kapatırız
    }
}
