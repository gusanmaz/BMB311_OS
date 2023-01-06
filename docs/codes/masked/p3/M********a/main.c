#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 

int getBirSayisi(char* dosyaAdi)
{
    int count=0;
    
    FILE* dosya;
    char ch;
    dosya = fopen(dosyaAdi, "r");
    
     if ((dosya = fopen(dosyaAdi, "r")) == NULL) {
      printf("\nDosya açma hatası! Dosya Yok yada Açılamadı!: %s\n\n",dosyaAdi);
      return count;
  }
 
    if (dosya==NULL) {
        fclose(dosya);
        return count;
    }
    
    ch = fgetc(dosya);
    while (ch != EOF) {
        if(ch=='1')
        
            count++;
        ch = fgetc(dosya);
    }
    printf("Nunmer of Ones in %s: %d\n",dosyaAdi,count);
    fclose(dosya);
    return count;
}

int main(int argc, char *argv[])
{
    int sumOne=0;
    for(int i=1;i<argc;i++)
      sumOne+= getBirSayisi(argv[i]);
      
    printf("\nTotal Number of Ones in All Files: %d\n",sumOne);
    return 0;
}
