#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

void* mythread(void* arg){
  char *dosya = (char*)arg;
  //printf("\n%s\n",dosya);
  FILE* fp;
    char filepath[100];
    strcpy(filepath,dosya);
  //printf("\n%s\n",filepath);
    fp = fopen(filepath, "r");
  if (fp == NULL) { 
        //printf("Could not open file %s", filepath); 
     int* result = malloc(sizeof(int));
    *result = 0;
  return (void*) result;
    
    free(arg);
    }
  else{
  int c,n;
  n = 0;
    c = fgetc(fp);
    while (c != EOF)
    {
     
      char x = '1';
      if(x == c){
          n = n + 1;
         
        }
        c = fgetc(fp);
    }
  
    fclose(fp);
  //printf("tekrar sayisi :%d\n",n);
  int* result = malloc(sizeof(int));
    *result = n;
  return (void*) result;
    
    free(arg);
}
  }

int main(int argc, char *argv[])
{
  if(argc == 1 || argc < 1){
    printf("Total Number of Ones in All Files: 0");
    return 0;
  }
  else{
  int* sonuc = 0;
    int sonsonuc = 0;
  int dosyasayi = argc - 1;
  pthread_t th[dosyasayi];
  int i;
  for(i = 1; i <=dosyasayi;i++){
    char *file = argv[i];
    //printf("\n%s\n",file);
    int b = i - 1;
    pthread_create(&th[b], NULL, &mythread, file);
    }
  
    for (i = 1; i <= dosyasayi; i++){
      int b = i - 1;
      pthread_join(th[b], (void**) &sonuc);
      sonsonuc = sonsonuc + *sonuc;
    }
  printf("Total Number of Ones in All Files: %d",sonsonuc);
      
      return 0;
}
  }  
