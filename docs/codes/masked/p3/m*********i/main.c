#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
int sayiDosyaToplami = 0;
int toplamSonuc = 0;
void *threadFonksiyonu(void *dosya)
{
     sayiDosyaToplami = 0;
    int c;
    FILE *f = fopen(dosya, "r"); //dosya okuma 
    while(1)
    {
        c = fgetc(f);//1 kontrolü
        if(c == 49)
            sayiDosyaToplami++;
        if(feof(f))//dosya okuma bitirme
            break;
    }
    toplamSonuc += sayiDosyaToplami;//1'leri yeni sonuca aktarma 
    pthread_exit(NULL);
}

int main(int ac, char **av)
{
    pthread_t yeniThread[ac];//her dosya için yeni thread oluşturma 
    for(int i = 1; i < ac; i++)
     {
        pthread_create(&yeniThread[i], NULL, threadFonksiyonu, av[i]);
     }
     for(int i = 1; i < ac; i++)//thread bekletme
     {
        pthread_join(yeniThread[i], NULL );
     }
     printf("Tüm dosyalardaki toplam 1 sayısı: %d",toplamSonuc);
}
