#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

int counter(char* path){
  FILE *fp;
  char ch;
  int count = 0;
  fp = fopen(path, "r");
  if(fp){
    while((ch = getc(fp)) != EOF){
      if(ch == 1 + '0'){
        count++;
      }
    }
  }
  fclose(fp);
  return count;
}

int main(int argc, char *argv[]) {
  int all_files = 0;
  for (int i = 1; argc >= i; i++){
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, counter, argv[i]);
    int ones;
    pthread_join(thread_id, ones);
    all_files += ones;
  }
  printf("%d\n", all_files);
}
