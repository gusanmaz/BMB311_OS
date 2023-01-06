//kütüphaneler
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <pthread.h>

//fonksiyon

long unsigned int birsayac = 0; //toplam bir sayısını bulmak için bir int veri oluşturduk

void* sayici(void*path){

    char*fn = (char*)path;
    FILE*fp = fopen(fn,"r");
        if(fp!=NULL){
            int id;
            while ((id=fgetc(fp))!=EOF)
            {
                if((int)id == 49){ //ascii de 49. karakter olan (1) karakteri eğer dosyada var ise sayacı 1 arttır demek
                    birsayac++; 
                }
            }
            
          pthread_exit(0);

        }
}


//main fonk
int main(int argc, char *argv[])
{
   pthread_t*tid;
   tid =(pthread_t*)malloc((argc-1)*sizeof(pthread_t));

   for (int i = 1; i < argc; i++)
   {
    pthread_create(&tid[i], NULL, sayici, argv[i]);
    pthread_join(tid[i], NULL);
   }
   

   printf("Dosyada bulunan 1 sayısı: %lu \n", birsayac); //yazdırdık

   return 0;
}

