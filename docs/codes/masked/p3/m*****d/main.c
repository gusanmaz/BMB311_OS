#include <pthread.h> 
 #include <stdio.h> 
 #include <unistd.h> 
 #include <stdlib.h> 
 #include <string.h> 
  
 int        a = 0; 
 int result = 0; 
  
 void        *sum_one(void *str) 
 { 
         int        c; 
         FILE *f = fopen(str, "r"); 
  
         a = 0; 
         while (1) 
         { 
                 c = fgetc(f); 
                 if (c == 49) 
                         a++; 
                 if (feof(f)) 
                         break; 
         } 
         result += a; 
         pthread_exit(NULL); 
 } 
  
 int main(int argc, char *argv[]) 
 { 
         pthread_t        tid[argc]; 
         int        i; 
         for (i = 1; i < argc; i++) 
         { 
                 pthread_create(&tid[i], NULL, sum_one, argv[i]); 
                 pthread_join(tid[i], NULL); 
         } 
  
         printf("%d\n", result); 
         return (0); 
 }
