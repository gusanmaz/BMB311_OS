#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

void main(int argc, char *argv[]) {
    
    int pid = atoi(argv[1]); //girilen string argüman int e çevrilir
    
    printf("Girilen pid değeri: %d\n",pid); //girilen argüman (pid) ekrana yazdırılır
    
    

    char filename[100]; //dosya ismini tutacak bir string
    
    sprintf(filename, "/proc/%d/comm", pid);  //okunacak dosya dizini oluşturulur
    
    FILE *fp = fopen(filename, "r"); //dosya okuma modunda açılır
    
    if(fp == NULL){
    	
    	printf("NULL\n");
    }
    else{
    	
    	char comm[1000]; //komut ismini tutacak bir string

	fscanf(fp, "%s",comm); //komut fscanf ile okunur
	    
	printf("comm = %s\n", comm); //komut ekrana yazdırılır
	    
	fclose(fp); //dosya kapatılır
    }
}
