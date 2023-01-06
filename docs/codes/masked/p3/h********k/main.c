#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

void *mythread(void *arg)
{
   char *belgeAdi = (char *)arg;
   FILE *belgePointeri;
   char belgeYolu[100];
   strcpy(belgeYolu, belgeAdi);
   belgePointeri = fopen(belgeYolu, "r");
   if(belgePointeri != NULL)
   {
      int harf, sayac;
      sayac = 0;
      harf = fgetc(belgePointeri);
      while (harf != EOF)
      {
         if (harf == '1')
         {
            sayac++;
         }
         harf = fgetc(belgePointeri);
      }

      fclose(belgePointeri);
      int *sonuc = malloc(sizeof(int));
      *sonuc = sayac;
      return (void *)sonuc;

      free(arg);
   }
   else
   {
      int *sonuc = malloc(sizeof(int));
      *sonuc = 0;
      return (void *)sonuc;
      free(arg);
   }
}

int main(int argc, char *argv[])
{
   if (argc == 1 || argc < 1)
   {
      printf("Total Number of Ones in All Files: 0\n");
      return 0;
   }
   else
   {
      int *sonuc;
      int toplamSonuc = 0;
      int belgeAdeti = argc - 1;
      pthread_t thread[belgeAdeti];
      for (int i = 1; i <= belgeAdeti; i++)
      {
         char *dosya = argv[i];
         pthread_create(&thread[i-1], NULL, &mythread, dosya);
      }

      for (int i = 1; i <= belgeAdeti; i++)
      {
         pthread_join(thread[i-1], (void **)&sonuc);
         toplamSonuc = toplamSonuc + *sonuc;
      }
      printf("Total Number of Ones in All Files: %d \n", toplamSonuc);

      return 0;
   }
}
