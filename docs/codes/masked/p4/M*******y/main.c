//kütüphaneler
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

//fonksiyon
void main(int argc, char *argv[]){

   int pid =atoi(argv[1]); 
   char komut[1000];
   char fn[100];

   printf("girdiğiniz pid değeri : %d\n",pid); //girdiğimiz pid değerini ekrana yazdırdık
   sprintf(fn,"/proc/%d/comm",pid);

   FILE*fp = fopen(fn,"r");
   if(fp==NULL){
    printf("NULL\n");
    
   }

   else{
    fscanf(fp,"%s",komut);
    printf("pid değerine sahip çalışan komutun ismi: %s\n", komut); //girdiğimiz pid değerine sahip komutu ekrana yazdırdık
    fclose(fp);


   }

}
